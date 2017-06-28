/*
 * bsp_timer0.c
 *
 *  Created on: 2017Äê6ÔÂ28ÈÕ
 *      Author: fly
 */

#include "bsp.h"

void Timer0_InitHard(void) {

	TMOD = 0x22;                  //Timer 0 and Timer 1 mode configuration

	TH0 = (256 - 50);            //initial counter values
	TL0 = (256 - 50);
	TH1 = (256 - 250);
	TL1 = (256 - 250);

	set_ET0;                                    //enable Timer0 interrupt
	set_ET1;                                    //enable Timer1 interrupt
	set_EA;                                     //enable interrupts
	set_TR0;                                    //Timer0 run
	set_TR1;                                    //Timer1 run

}

