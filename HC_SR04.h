#ifndef __HC_SR04_H
#define __HC_SR04_H

/*****************************
Moudle Description
Fuction: HC-SR04 ultrasonic module control
Author:  Ding Wang
Date:    2015.08.14
Module:  HC-SR04
Pin:     TRIG: Given a 10us up level pulse to start measuring
				 ECHO: Return a up level pulse last as long as the ultrasonic travelled
Depend:  stm32f10x.h is necessary
				 SysTich.h is for delay, not necessary, can be replaced by your own delay function
*********************************/

#include "stm32f10x.h"
#include "SysTick.h"

void HCSR04_Init(void);
u32 HCSR04_Measure(void);

#endif
