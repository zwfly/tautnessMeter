/*
 * bsp_bright.c
 *
 *  Created on: 2017��6��26��
 *      Author: fly
 */

#include "bsp.h"

void Bright_InitHard(void) {

	P3M1 &= ~SET_BIT1;
	P3M2 |= SET_BIT1;

	clr_P31;

}
