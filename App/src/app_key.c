/*
 * app_key.c
 *
 *  Created on: 2017Äê7ÔÂ7ÈÕ
 *      Author: admin
 */

#include "app.h"

static void app_UI_init(void);

void app_key_init(void) {

	app_UI_init();
}

static void app_UI_init(void) {
	switch (g_tWork.mode) {
	case E_Simple_metering_mode:
		LCD_Display_Line_up();
		LCD_Display_CAL_ICO();
		break;
	case E_Quick_start_mode:

		LCD_Display_REP_ICO();
		LCD_Display_Line_up();

		LCD_Display_ABCD('A');
		LCD_Display_ABCD('B');
		LCD_Display_ABCD('C');
		LCD_Display_ABCD('D');

		LCD_Display_CAL_ICO();

		LCD_Clear_COACH_ICO();

		Repeat_Stop();
		Repeat_SetStart(LCD_Display_QS_ICO);
		Repeat_SetStop(LCD_Clear_QS_ICO);
		Repeat_Start(8, 8, 0);
		break;
	case E_Coach_mode:
		LCD_Display_REP_ICO();
		LCD_Display_Line_up();

		LCD_Display_ABCD('A');
		LCD_Display_ABCD('B');
		LCD_Display_ABCD('C');
		LCD_Display_ABCD('D');

		LCD_Display_CAL_ICO();

		LCD_Clear_QS_ICO();

		Repeat_Stop();
		Repeat_SetStart(LCD_Display_COACH_ICO);
		Repeat_SetStop(LCD_Clear_COACH_ICO);
		Repeat_Start(8, 8, 0);
		break;
	}
}

void app_key_power_or_return(void) {
	switch (g_tWork.mode) {
	case E_Simple_metering_mode:
		g_tWork.sum = 0;
		g_tWork.cal_num = 0;
		LCD_Display_Pulls_Num(g_tWork.sum);

		LCD_Display_CAL_Num(g_tWork.cal_num);
		break;
	case E_Quick_start_mode:

		break;
	case E_Coach_mode:

		break;
	}
}
void app_key_set(void) {
	switch (g_tWork.mode) {
	case E_Simple_metering_mode:
		g_tWork.mode = E_Quick_start_mode;
		break;
	case E_Quick_start_mode:
		g_tWork.mode = E_Coach_mode;
		break;
	case E_Coach_mode:
		g_tWork.mode = E_Simple_metering_mode;
		break;
	}
	app_UI_init();
}
void app_key_add(void) {
	switch (g_tWork.mode) {
	case E_Simple_metering_mode:

		break;
	case E_Quick_start_mode:

		break;
	case E_Coach_mode:

		break;
	}
}
void app_key_ok(void) {

}
void app_key_pro(uint8_t keyCode) {

//	BEEP_KeyTone();

	switch (keyCode) {
	case KEY_UP_K1:

		break;
	case KEY_DOWN_K1:
		app_key_power_or_return();
		break;
	case KEY_LONG_K1:

		break;
	case KEY_UP_K2:

		break;
	case KEY_DOWN_K2:
		app_key_set();
		break;
	case KEY_LONG_K2:

		break;
	case KEY_UP_K3:

		break;
	case KEY_DOWN_K3:
		app_key_add();
		break;
	case KEY_LONG_K3:

		break;
	case KEY_UP_K4:

		break;
	case KEY_DOWN_K4:
		app_key_ok();
		break;
	case KEY_LONG_K4:

		break;
	case KEY_UP_K1K3:

		break;
	case KEY_DOWN_K1K3:

		break;
	case KEY_LONG_K1K3:

		break;
	default:
		BEEP_KeyTone();
		break;

	}
}
