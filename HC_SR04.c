#include "HC_SR04.h"

/*************
HCSR04 GPIO/Timer initialization function by Ding Wang in 2015.08.14
Must be called in the begining of the main program
*************/
void HCSR04_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	/*Initialize GPIOB.9(ECHO) as 50MHz IPD input*/
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	/*Initialize GPIOB.8(TRIG) as 50MHz OD output*/
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOB, GPIO_Pin_8);
	// Enable the clock of Timer4
	RCC->APB1ENR |= (1 << 2);
	// Configuration of Timer4
	TIM4->ARR = 0xFFFF;
	TIM4->PSC = 72 - 1;
	TIM4->CCMR2 |= (1<<8);		//IC4 map to TI4
	TIM4->CCMR2 |= (0<<10);		//No prescaler
	TIM4->CCMR2 |= (0<<12);		//No filter
	TIM4->CCER |= (1<<12);		//Capture 4 output enabled
	TIM4->CCER |= (0<<13);		//Capture 4 output polarity is rising
	TIM4->CR1 |= (u16)0x0001;	//Enable Timer4
}

/*************
HCSR04 measurement function by Ding Wang in 2015.08.14
Called as dis=HCSR04_Measure(), dis is the distance measured in centimeters, valid value can be from 1 to 181.
Nothing else can be done during playing, for improvment you can rewrite this funtion by interruption.
*************/
u32 HCSR04_Measure(void)
{
	u32 begintime, endtime, timelength;
	(TIM4->SR) = 0;											//Reset SR(capture flag)
	GPIO_SetBits(GPIOB, GPIO_Pin_8);		//Give a 10us high pulse
	SysTick_Delay_us(10);
	GPIO_ResetBits(GPIOB, GPIO_Pin_8);
	while(0 == ((TIM4->SR) & 0x0010));	//Loop till rising edge captured
	begintime = TIM4->CCR4;							//Note the capture time
	TIM4->CCER |= (1<<13);							//Capture 4 output polarity is trailing
	(TIM4->SR) = 0;											//Reset capture flag
	while(0 == ((TIM4->SR) & 0x0010));	//Loop till trailing edge captured
	endtime = TIM4->CCR4;								//Note the capture time
	TIM4->CCER &= (u16)0xDFFF;					//Capture 4 output polarity is rising
	(TIM4->SR) = 0;											//Reset capture flag
	if (begintime < endtime)						//timelength is the microseconds sound travelled
		timelength = endtime - begintime;
	else
		timelength = (endtime + 0xFFFF - begintime);
	return (timelength / 58);						//Sound speed is about 0.034cm per us, or 29us per cm
}
