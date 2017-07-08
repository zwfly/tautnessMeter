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
		LCD_Show_Line_up();
		LCD_Show_CAL_ICO();
		break;
	case E_Quick_start_mode:

		LCD_Show_REP_ICO();
		LCD_Show_Line_up();

		LCD_Show_ABCD('A');
		LCD_Show_ABCD('B');
		LCD_Show_ABCD('C');
		LCD_Show_ABCD('D');

		LCD_Show_CAL_ICO();

		LCD_Clear_COACH_ICO();

		Repeat_Stop();
		Repeat_SetStart(LCD_Show_QS_ICO);
		Repeat_SetStop(LCD_Clear_QS_ICO);
		Repeat_Start(8, 8, 0);
		break;
	case E_Coach_mode:
		LCD_Show_REP_ICO();
		LCD_Show_Line_up();

		LCD_Show_ABCD('A');
		LCD_Show_ABCD('B');
		LCD_Show_ABCD('C');
		LCD_Show_ABCD('D');

		LCD_Show_CAL_ICO();

		LCD_Clear_QS_ICO();

		Repeat_Stop();
		Repeat_SetStart(LCD_Show_COACH_ICO);
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
		LCD_Show_Pulls_Num(g_tWork.sum);

		LCD_Show_CAL_Num(g_tWork.cal_num);
		break;
	case E_Quick_start_mode:

		break;
	case E_Coach_mode:

		break;
	}
}
void app_key_set(void) {
	static BIT power_on_mode_flag = 0;

	if (power_on_mode_flag) {
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
	} else {
		power_on_mode_flag = 1;


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
