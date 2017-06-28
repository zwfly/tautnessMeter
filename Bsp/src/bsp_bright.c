/*
 * bsp_bright.c
 *
 *  Created on: 2017Äê6ÔÂ26ÈÕ
 *      Author: fly
 */

#include "bsp.h"

void Bright_InitHard(void) {

	P3M1 &= ~SET_BIT1;
	P3M2 |= SET_BIT1;

	clr_P31;

}
