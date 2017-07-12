/*
 * bsp_adc.c
 *
 *  Created on: 2017Äê7ÔÂ7ÈÕ
 *      Author: admin
 */

#include "app.h"

CHARGE_T g_tCharge;

void ADC_Init(void) {

	g_tCharge.count = 0;
}

void app_charge_100ms_pro(void) {
//	uint8_t tmp = 0;
	static BIT flag = 0;

	g_tCharge.count++;
	switch (g_tCharge.status) {
	case E_NeedCharge:
		if (g_tCharge.count >= 5) {
			g_tCharge.count = 0;

			if (flag) {
				flag = 0;
				LCD_Show_Battery_ICO();
			} else {
				flag = 1;
				LCD_Clear_Battery_ICO();
			}
		}
		break;
	case E_InCharge:
		if (g_tCharge.count >= 10) {
			g_tCharge.count = 0;

			if (flag) {
				flag = 0;
				LCD_Show_Battery_ICO();
			} else {
				flag = 1;
				LCD_Clear_Battery_ICO();
			}
		}
		break;
	case E_FullCharge:
		if (g_tCharge.count >= 9) {
			g_tCharge.count = 0;

			LCD_Show_Battery_ICO();
		}
		break;
	case E_Discharge:
		if (g_tCharge.count >= 9) {
			g_tCharge.count = 0;

			LCD_Clear_Battery_ICO();
		}
		break;
	}

}
