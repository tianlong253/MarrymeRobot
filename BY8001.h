#ifndef __BY8001_H
#define __BY8001_H

/*****************************
Moudle Description
Fuction: BY8001 sound module control
Author:  Ding Wang
Date:    2015.08.07
Module:  BY8001-16P
Pin:     BUSY: High when playing a piece of sound, otherwise low
				 IO1:  Play sound 1 when connected to ground
				 IO2:  Play sound 2 when connected to ground
				 IO3:  Play sound 3 when connected to ground
				 IO4:  Play sound 4 when connected to ground
				 IO5:  Play sound 5 when connected to ground
Depend:  stm32f10x.h is necessary
				 SysTich.h is for delay, not necessary, can be replaced by your own delay function
*********************************/

#include "stm32f10x.h"
#include "SysTick.h"

void BY8001_Init(void);
void BY8001_Play(u8 number);

#endif
