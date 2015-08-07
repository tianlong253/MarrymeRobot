#include "SysTick.h"

u32 factor_us, factor_ms;
void SysTick_Initial(void)
{
	RCC_ClocksTypeDef RCC_Clocks;
	RCC_GetClocksFreq(&RCC_Clocks);
	
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
	factor_us = SystemCoreClock/8000000;
	factor_ms = factor_us * 1000;
}

void SysTick_Delay_us(u32 delayus)
{
	u32 state;
	SysTick -> LOAD = factor_us * delayus;
	SysTick -> VAL = 0x00;
	SysTick -> CTRL |= SysTick_CTRL_ENABLE_Msk;
	do
	{
		state = SysTick -> CTRL;
	}
	while((state & 0x01) && !(state & (1<<16)));
	SysTick -> CTRL &= ~SysTick_CTRL_ENABLE_Msk;
	SysTick -> VAL = 0x00;
}
