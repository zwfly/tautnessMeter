/*
 * app_battery.c
 *
 *  Created on: 2017Äê7ÔÂ28ÈÕ
 *      Author: fly
 */

#include "app.h"


void app_battery_Init(void) {

}

static void app_battery_detection(void) {

	P01 = 0;
	nop
	set_ADCS;  //Trigger ADC start conversion
}

void app_battery_1s_pro(void) {
	 static idata uint8_t	cnt = 0;

	cnt++;
	if (cnt >= 5) {
		cnt = 0;
		app_battery_detection();
	}

}
