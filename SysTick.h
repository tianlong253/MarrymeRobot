#ifndef __SYSTICK_H
#define __SYSTICK_H

#include "stm32f10x.h"

void SysTick_Initial(void);
void SysTick_Delay_us(u32 delayus);

#endif
