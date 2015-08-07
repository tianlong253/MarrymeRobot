#include "BY8001.h"

/*************
BY8001 GPIO initialization function by Ding Wang in 2015.08.07
Must be called in the begining of the main program
*************/
void BY8001_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	/*Initialize GPIOB.10(BUSY) as 50MHz IPD input*/
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	/*Initialize GPIOA.1(IO5), GPIOA.2(IO5), GPIOA.3(IO5), GPIOA.4(IO5), GPIOA.5(IO5) all as 50MHz OD outputs, and all set to 1*/
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_SetBits(GPIOA, GPIO_Pin_1);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_SetBits(GPIOA, GPIO_Pin_2);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_SetBits(GPIOA, GPIO_Pin_3);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_SetBits(GPIOA, GPIO_Pin_4);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_SetBits(GPIOA, GPIO_Pin_5);
}

/*************
BY8001 play control function by Ding Wang in 2015.08.07
Called as BY8001_Play(x), x is the number of sound pieces, can be 1 to 5
Nothing else can be done during playing, for improvment you can rewrite this funtion by interruption
*************/
void BY8001_Play(u8 number)
{
	switch(number)
	{
		case 1:
			GPIO_ResetBits(GPIOA, GPIO_Pin_5);
			SysTick_Delay_us(5000);								// Should be replaced by your own delay function
			GPIO_SetBits(GPIOA, GPIO_Pin_5);
			while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10));
			break;
		case 2:
			GPIO_ResetBits(GPIOA, GPIO_Pin_4);
			SysTick_Delay_us(5000);								// Should be replaced by your own delay function
			GPIO_SetBits(GPIOA, GPIO_Pin_4);
			while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10));
			break;
		case 3:
			GPIO_ResetBits(GPIOA, GPIO_Pin_3);
			SysTick_Delay_us(5000);								// Should be replaced by your own delay function
			GPIO_SetBits(GPIOA, GPIO_Pin_3);
			while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10));
			break;
		case 4:
			GPIO_ResetBits(GPIOA, GPIO_Pin_2);
			SysTick_Delay_us(5000);								// Should be replaced by your own delay function
			GPIO_SetBits(GPIOA, GPIO_Pin_2);
			while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10));
			break;
		case 5:
			GPIO_ResetBits(GPIOA, GPIO_Pin_1);
			SysTick_Delay_us(5000);								// Should be replaced by your own delay function
			GPIO_SetBits(GPIOA, GPIO_Pin_1);
			while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10));
			break;
		default:
			break;
	}
}
