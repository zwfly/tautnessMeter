/*
 * bsp_bright.c
 *
 *  Created on: 2017Äê6ÔÂ26ÈÕ
 *      Author: fly
 */

#include "bsp.h"

void Bright_InitHard(void) {

#if 1
	P3M1 &= ~SET_BIT2;
	P3M2 |= SET_BIT2;

	lcd_bright_on();
#endif

}
void lcd_bright_on(void) {
	clr_P32;
}
void lcd_bright_off() {
	set_P32;
}
