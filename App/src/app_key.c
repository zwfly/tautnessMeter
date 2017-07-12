/*
 * app_key.c
 *
 *  Created on: 2017年7月7日
 *      Author: admin
 */

#include "app.h"

DEVICE_T g_tDevice;

static E_TRAINING_MODE mode;
static char letter = '\0';

/*
 * level: 0, 拉动时候的界面
 *        1,
 * */
static uint8_t level = 0;

static void app_UI_init(void);

void app_key_init(void) {
	level = 0;

	mode = E_Simple_metering_mode;
	g_tWork.mode = E_Simple_metering_mode;
	g_tDevice.status = E_PowerOn;
	app_UI_init();
}

static void app_UI_init(void) {
	switch (mode) {
	case E_Simple_metering_mode:
		LCD_Show_Line_up();
		LCD_Clear_REP_ICO();

		LCD_Clear_ABCD();

		LCD_Show_CAL_ICO();
		LCD_Clear_QS_ICO();
		LCD_Clear_COACH_ICO();

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

	switch (level) {
	case 0:
		switch (mode) {
		case E_Simple_metering_mode:
			g_tWork.sum = 0;
			g_tWork.cal_num = 0;
			LCD_Show_Pulls_Num(g_tWork.sum);
			LCD_Show_CAL_Num(g_tWork.cal_num);
			break;
		case E_Quick_start_mode:
			g_tWork.sum = 0;
			g_tWork.cal_num = 0;
			LCD_Show_REP_Num(0);
			LCD_Show_Pulls_Num(0);
			LCD_Show_CAL_Num(0);
			break;
		case E_Coach_mode:
			g_tWork.sum = 0;
			g_tWork.cal_num = 0;
			LCD_Show_REP_Num(0);
			LCD_Show_Pulls_Num(0);
			LCD_Show_CAL_Num(0);
			break;
		}
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	}

}
void app_key_set(void) {
	static BIT power_on_mode_flag = 0;

	switch (level) {
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	}

	switch (g_tWork.mode) {
	case E_Simple_metering_mode:
		g_tWork.mode = E_Quick_start_mode;
		mode = E_Quick_start_mode;
		level = 1;
		break;
	case E_Quick_start_mode:

		break;
	case E_Coach_mode:

		break;
	}

	app_UI_init();
}
void app_key_add(void) {

	switch (level) {
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	}

	switch (mode) {
	case E_Simple_metering_mode:
		if (level == 1) {
			mode = E_Quick_start_mode;

		}
		break;
	case E_Quick_start_mode:
		if (level == 1) {
			mode = E_Coach_mode;
		} else if (level == 2) {
			if (letter == '\0') {
				letter = 'A';
			} else {
				letter++;
				if (letter > 'D') {
					letter = 'A';
				}
			}
		}
		break;
	case E_Coach_mode:
		if (level == 1) {
			mode = E_Simple_metering_mode;
		} else if (level == 2) {

		}
		break;
	}
}

void app_flash_Show_ABCD(void) {

	if (mode == E_Quick_start_mode) {
		LCD_Show_QS_ICO();
		LCD_Clear_COACH_ICO();
	} else if (mode == E_Coach_mode) {
		LCD_Clear_QS_ICO();
		LCD_Show_COACH_ICO();
	}

	LCD_Show_ABCD('A');
	LCD_Show_ABCD('B');
	LCD_Show_ABCD('C');
	LCD_Show_ABCD('D');

}
void app_flash_Clear_ABCD(void) {

	switch (level) {
	case 0:
		break;
	case 1:

		break;
	case 2:
		break;
	case 3:
		break;
	}

	if (mode == E_Quick_start_mode) {
		LCD_Clear_QS_ICO();
	} else if (mode == E_Coach_mode) {
		LCD_Clear_COACH_ICO();
	}

	if (letter == '\0') {
		LCD_Clear_ABCD();
	}
	if (letter == 'A') {
//		LCD_Clear_ABCD('A');
		LCD_Clear_ABCD('B');
		LCD_Clear_ABCD('C');
		LCD_Clear_ABCD('D');
	}
	if (letter == 'B') {
		LCD_Clear_ABCD('A');
//		LCD_Clear_ABCD('B');
		LCD_Clear_ABCD('C');
		LCD_Clear_ABCD('D');
	}
	if (letter == 'C') {
		LCD_Clear_ABCD('A');
		LCD_Clear_ABCD('B');
//		LCD_Clear_ABCD('C');
		LCD_Clear_ABCD('D');
	}
	if (letter == 'D') {
		LCD_Clear_ABCD('A');
		LCD_Clear_ABCD('B');
		LCD_Clear_ABCD('C');
//		LCD_Clear_ABCD('D');
	}
}
void app_key_ok(void) {
	//g_tWork.mode = mode;

	level++;
	if (level >= 3) {
		level = 0;
	}

	switch (level) {
	case 0:
		break;
	case 1:

		switch (mode) {
		case E_Simple_metering_mode:

			break;
		case E_Quick_start_mode:

			LCD_Show_QS_ICO();
			LCD_Clear_COACH_ICO();

			Repeat_Stop();
			Repeat_SetStart(app_flash_Show_ABCD);
			Repeat_SetStop(app_flash_Clear_ABCD);
			Repeat_Start(9, 9, 0);

			break;
		case E_Coach_mode:

			break;
		}
		break;
	case 2:
		switch (mode) {
		case E_Simple_metering_mode:

			break;
		case E_Quick_start_mode:
			if (level == 2) {
				LCD_Show_QS_ICO();
				LCD_Clear_COACH_ICO();

				Repeat_Stop();
				Repeat_SetStart(app_flash_Show_ABCD);
				Repeat_SetStop(app_flash_Clear_ABCD);
				Repeat_Start(9, 9, 0);
			} else if (level == 2) {

			}

			break;
		case E_Coach_mode:

			break;
		}
		break;
	case 3:
		break;
	}

}

void app_power_on(void) {
	SW_Reset();  //复位
}
void app_power_off(void) {
	lcd_bright_off();
	LCD_Clear_All();
}
void app_key_pro(uint8_t keyCode) {

	BEEP_KeyTone();

	switch (keyCode) {
	case KEY_UP_K1:
		app_key_power_or_return();
		break;
	case KEY_DOWN_K1:

		break;
	case KEY_LONG_K1:
		if (g_tDevice.status == E_PowerOn) {
			g_tDevice.status = E_PowerOff;
			app_power_off();
		} else if (g_tDevice.status == E_PowerOff) {
			g_tDevice.status = E_PowerOn;
			app_power_on();
		}

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
//		BEEP_KeyTone();
		break;

	}
}
