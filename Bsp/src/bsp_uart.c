/*
 * bsp_uart.c
 *
 *  Created on: 2017��6��27��
 *      Author: fly
 */

#include "bsp.h"

void Uart_InitHard(void) {

	P5M1 &= ~SET_BIT7;
	P5M2 |= SET_BIT7;

	InitialUART1_Timer3(9600);

}

