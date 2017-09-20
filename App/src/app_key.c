/*
 * app_key.c
 *
 *  Created on: 2017年7月7日
 *      Author: admin
 */

#include "app.h"

DEVICE_T g_tDevice;

#define BLINK_FLASH_TIME   4

/*
 * level: 0, 拉动时候的界面
 *        1,
 * */
//uint8_t level = 0;
static void app_UI_init(void);

void app_key_init(void) {

	app_powerKeyInt_close();
	bsp_hallInt_open();

//	g_tWork.mode = E_TRAINING_NONE;

	g_tDevice.mode = E_Simple_metering_mode;
	g_tDevice.status = E_PowerOn;
	g_tDevice.level = E_LEVEL_PULL;
	g_tDevice.letter = 'A';

	app_UI_init();
}
void app_powerKeyInt_open(void) {
	clr_PIPS2;
	clr_PIPS1;
	clr_PIPS0;

	set_PIT6;
	set_PINEN6;
	clr_PIPEN6;

}
void app_powerKeyInt_close(void) {
	clr_PIPS2;
	clr_PIPS1;
	clr_PIPS0;

	clr_PIT6;
	clr_PINEN6;
	clr_PIPEN6;
}
static void app_UI_init(void) {
	switch (g_tDevice.mode) {
	case E_TRAINING_NONE:

		break;
	case E_Simple_metering_mode:

		LCD_Clear_REP_Num();
		LCD_Show_Pulls_Num(0);
		LCD_Show_CAL_Num(0);

		LCD_Show_Line_up();
		LCD_Clear_REP_ICO();

		LCD_Clear_ABCD();

		LCD_Show_CAL_ICO();
		LCD_Clear_QS_ICO();
		LCD_Clear_COACH_ICO();

//		Repeat_Stop();
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

//		Repeat_Stop();
//		Repeat_SetStart(LCD_Show_QS_ICO);
//		Repeat_SetStop(LCD_Clear_QS_ICO);
//		Repeat_Start(4, 4, 0);
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

//		Repeat_Stop();
//		Repeat_SetStart(LCD_Show_COACH_ICO);
//		Repeat_SetStop(LCD_Clear_COACH_ICO);
//		Repeat_Start(4, 4, 0);
		break;
	}
}

void app_flash_Show(void) {

	LCD_Show_Line_up();
	switch (g_tDevice.level) {
	case E_LEVEL_NONE:

		break;
	case E_LEVEL_MODE:

		switch (g_tDevice.mode) {
		case E_TRAINING_NONE:
			break;
		case E_Simple_metering_mode:

			break;
		case E_Quick_start_mode:
			LCD_Show_QS_ICO();
			break;
		case E_Coach_mode:
			LCD_Show_COACH_ICO();
			break;
		}

		break;
	case E_LEVEL_REP:

		switch (g_tDevice.letter) {
		case '\0':
			g_tDevice.letter = 'A';
			break;
		case 'A':
			LCD_Show_REP_Num(Rep_Pull_num['A' - 'A'][0]);
			LCD_Show_Pulls_Num(Rep_Pull_num['A' - 'A'][1]);
			break;
		case 'B':
			LCD_Show_REP_Num(Rep_Pull_num['B' - 'A'][0]);
			LCD_Show_Pulls_Num(Rep_Pull_num['B' - 'A'][1]);
			break;
		case 'C':
			LCD_Show_REP_Num(Rep_Pull_num['C' - 'A'][0]);
			LCD_Show_Pulls_Num(Rep_Pull_num['C' - 'A'][1]);
			break;
		case 'D':
			LCD_Show_REP_Num(Rep_Pull_num['D' - 'A'][0]);
			LCD_Show_Pulls_Num(Rep_Pull_num['D' - 'A'][1]);
			break;
		default:
			g_tDevice.letter = 'A';
			break;
		}
		if (g_tDevice.mode == E_Quick_start_mode) {
			LCD_Show_QS_ICO();
		} else if (g_tDevice.mode == E_Coach_mode) {
			LCD_Show_COACH_ICO();
		}
		LCD_Show_ABCD_all();

		break;
	case E_LEVEL_READY:

		break;
	case E_LEVEL_PULL:

		break;
	}
	LCD_Show_Line_up();
}
void app_flash_Clear(void) {

	switch (g_tDevice.level) {
	case E_LEVEL_NONE:
		break;
	case E_LEVEL_MODE:

		LCD_Clear_QS_ICO();
		LCD_Clear_COACH_ICO();
		break;
	case E_LEVEL_REP:

		if (g_tDevice.letter == '\0') {
			LCD_Clear_ABCD();
		}
		if (g_tDevice.letter == 'A') {
			LCD_Clear_ABCD();
			LCD_Show_ABCD('A');
		}
		if (g_tDevice.letter == 'B') {
			LCD_Clear_ABCD();
			LCD_Show_ABCD('B');
		}
		if (g_tDevice.letter == 'C') {
			LCD_Clear_ABCD();
			LCD_Show_ABCD('C');
		}
		if (g_tDevice.letter == 'D') {
			LCD_Clear_ABCD();
			LCD_Show_ABCD('D');
		}
		if (g_tDevice.mode == E_Quick_start_mode) {
			LCD_Clear_QS_ICO();
		} else if (g_tDevice.mode == E_Coach_mode) {
			LCD_Clear_COACH_ICO();
		}
		break;
	case E_LEVEL_READY:
		break;
	case E_LEVEL_PULL:

		break;
	}

}
void app_key_power_or_return(void) {

	switch (g_tDevice.level) {
	case E_LEVEL_NONE:

		break;
	case E_LEVEL_MODE:
//		Repeat_Stop();

		break;
	case E_LEVEL_REP:

		g_tDevice.level = E_LEVEL_MODE;

		break;
	case E_LEVEL_READY:

		g_tDevice.level = E_LEVEL_REP;

		break;
	case E_LEVEL_PULL:

#if 1
		g_tWork.sum = 0;
		g_tWork.cal_num = 0;

		app_UI_init();

		LCD_Show_Pulls_Num(g_tWork.sum);
		LCD_Show_CAL_Num(g_tWork.cal_num);

		switch (g_tDevice.mode) {
		case E_TRAINING_NONE:

			break;
		case E_Simple_metering_mode:

			LCD_Show_Line_up();
			LCD_Clear_REP_ICO();

			LCD_Clear_REP_Num();

			LCD_Clear_ABCD();

			LCD_Show_CAL_ICO();
			LCD_Clear_QS_ICO();
			LCD_Clear_COACH_ICO();

			break;
		case E_Quick_start_mode:

			LCD_Show_Line_up();
			LCD_Show_REP_ICO();
			LCD_Show_REP_Num(0);
			LCD_Show_ABCD(g_tWork.reps_mode);

			LCD_Show_CAL_ICO();
			LCD_Show_QS_ICO();
			LCD_Clear_COACH_ICO();
			break;
		case E_Coach_mode:

			LCD_Show_Line_up();
			LCD_Show_REP_ICO();
			LCD_Show_REP_Num(0);
			LCD_Show_ABCD(g_tWork.reps_mode);

			LCD_Show_CAL_ICO();
			LCD_Clear_QS_ICO();
			LCD_Show_COACH_ICO();

			break;
		}
#endif

		break;
	}

}
void app_key_set(void) {

	LCD_Show_REP_Num(0);
	LCD_Show_Pulls_Num(0);
	LCD_Show_CAL_Num(0);

	LCD_Show_Line_up();
	LCD_Show_REP_ICO();

	LCD_Show_ABCD_all();

	LCD_Show_CAL_ICO();

	g_tDevice.mode = E_Quick_start_mode;

//	g_tDevice.mode = E_Quick_start_mode;
//	g_tDevice.level = 1;

	g_tDevice.level = E_LEVEL_MODE;
	Repeat_Stop();
	Repeat_SetStart(app_flash_Show);
	Repeat_SetStop(app_flash_Clear);
	Repeat_Start(BLINK_FLASH_TIME, BLINK_FLASH_TIME, 0);

	switch (g_tDevice.level) {
	case E_LEVEL_NONE:

		break;
	case E_LEVEL_MODE:
		switch (g_tWork.mode) {
		case E_Simple_metering_mode:

			break;
		case E_Quick_start_mode:

			break;
		case E_Coach_mode:

			break;
		}
		break;
	case E_LEVEL_REP:

		break;
	case E_LEVEL_READY:

		break;
	case E_LEVEL_PULL:

		break;
	}

	app_UI_init();
}

void app_key_add(void) {

	switch (g_tDevice.level) {
	case E_LEVEL_NONE:

		break;
	case E_LEVEL_MODE:
		switch (g_tDevice.mode) {
		case E_TRAINING_NONE:

			break;
		case E_Simple_metering_mode:
			g_tDevice.mode = E_Quick_start_mode;

			break;
		case E_Quick_start_mode:
			g_tDevice.mode = E_Coach_mode;

			break;
		case E_Coach_mode:
			g_tDevice.mode = E_Simple_metering_mode;

			break;
		}
		break;
	case E_LEVEL_REP:
		switch (g_tDevice.mode) {
		case E_TRAINING_NONE:

			break;
		case E_Simple_metering_mode:

			break;
		case E_Quick_start_mode:

			if (g_tDevice.letter == '\0') {
				g_tDevice.letter = 'A';
			} else {
				g_tDevice.letter++;
				if (g_tDevice.letter > 'D') {
					g_tDevice.letter = 'A';
				}
			}

			break;
		case E_Coach_mode:
			if (g_tDevice.letter == '\0') {
				g_tDevice.letter = 'A';
			} else {
				g_tDevice.letter++;
				if (g_tDevice.letter > 'D') {
					g_tDevice.letter = 'A';
				}
			}
			break;
		}
		break;
	case E_LEVEL_READY:
		break;
	case E_LEVEL_PULL:

		break;
	}
	app_UI_init();
}

void app_key_ok(void) {

	switch (g_tDevice.level) {
	case E_LEVEL_NONE:

		break;
	case E_LEVEL_MODE:

		switch (g_tDevice.mode) {
		case E_TRAINING_NONE:

			break;
		case E_Simple_metering_mode:
			g_tDevice.level = E_LEVEL_READY;
			break;
		case E_Quick_start_mode:
			g_tDevice.level = E_LEVEL_REP;

			LCD_Show_QS_ICO();
			LCD_Clear_COACH_ICO();

//			Repeat_Stop();
//			Repeat_SetStart(app_flash_Show);
//			Repeat_SetStop(app_flash_Clear);
//			Repeat_Start(BLINK_FLASH_TIME, BLINK_FLASH_TIME, 0);

			break;
		case E_Coach_mode:
			g_tDevice.level = E_LEVEL_REP;
			LCD_Clear_QS_ICO();
			LCD_Show_COACH_ICO();

//			Repeat_Stop();
//			Repeat_SetStart(app_flash_Show);
//			Repeat_SetStop(app_flash_Clear);
//			Repeat_Start(BLINK_FLASH_TIME, BLINK_FLASH_TIME, 0);
			break;
		}
		g_tDevice.letter = g_tWork.reps_mode;

		break;
	case E_LEVEL_REP:
		switch (g_tDevice.mode) {
		case E_TRAINING_NONE:

			break;
		case E_Simple_metering_mode:

			break;
		case E_Quick_start_mode:

//			Repeat_Stop();
			LCD_Show_QS_ICO();
			LCD_Clear_COACH_ICO();

			break;
		case E_Coach_mode:
//			Repeat_Stop();
			LCD_Show_COACH_ICO();
			LCD_Clear_QS_ICO();

			break;
		}
		g_tWork.mode = g_tDevice.mode;
		g_tWork.reps_mode = g_tDevice.letter;
		g_tWork.sum = 0;
		g_tDevice.level = E_LEVEL_READY;
		break;
	case E_LEVEL_READY:

		break;
	case E_LEVEL_PULL:

		break;
	}
//	app_UI_init();
}

void app_power_on(void) {
	SW_Reset();  //复位
}
void app_power_off(void) {
	lcd_bright_off();
	LCD_Clear_All();
}

uint8_t noOps_timeoutCnt = 0;
static BIT offBight_flag = 0;

void app_key_100ms_pro(void) {
	static uint8_t cnt = 0;

	if (g_tDevice.status == E_PowerDown) {
		cnt++;
		if (cnt >= 3) {
			cnt = 0;

			app_key_clear_noOps_timeoutCnt();
//			keyInvalid_flag = 1;
			bsp_hallInt_close();
			app_powerKeyInt_open();
			set_PD;
		}
	} else {
		cnt = 0;
	}
}

void app_key_1s_pro(void) {

	noOps_timeoutCnt++;
	if (noOps_timeoutCnt == 40) {
		offBight_flag = 1;
//		keyInvalid_flag = 1;
		lcd_bright_off();
		printf("off bright\n");
	} else if (noOps_timeoutCnt == 50) {
		app_power_off();
		printf("power off\n");
		g_tDevice.status = E_PowerDown;
	}

}
void app_key_clear_noOps_timeoutCnt(void) {
	noOps_timeoutCnt = 0;
}
void app_key_pro(uint8_t keyCode) {

	app_key_clear_noOps_timeoutCnt();

	if (offBight_flag && (g_tDevice.status == E_PowerOn)) {
		offBight_flag = 0;
		lcd_bright_on();
		//	keyInvalid_flag = 1;
		return;
	}

	switch (keyCode) {
	case KEY_UP_K1:
#if 0
		if (g_tDevice.status == E_PowerReady) {
			app_power_off();
			printf("power off\n");
			g_tDevice.status = E_PowerDown;
		}
#endif
		break;
	case KEY_DOWN_K1:
		BEEP_KeyTone();
		if (g_tDevice.status == E_PowerOn) {
			app_key_power_or_return();
		} else if (g_tDevice.status == E_PowerDown) {
			g_tDevice.status = E_PowerOn;
			app_power_on();
		}
		break;
	case KEY_LONG_K1:
		BEEP_KeyTone();
		if (g_tDevice.status == E_PowerOn) {
			g_tDevice.status = E_PowerDown;
			app_power_off();
		} else if (g_tDevice.status == E_PowerReady) {
			g_tDevice.status = E_PowerOn;
			app_power_on();
		}

		break;
	case KEY_UP_K2:

		break;
	case KEY_DOWN_K2:
		BEEP_KeyTone();
		app_key_set();
		break;
	case KEY_LONG_K2:

		break;
	case KEY_UP_K3:

		break;
	case KEY_DOWN_K3:
		BEEP_KeyTone();
		app_key_add();
		break;
	case KEY_LONG_K3:

		break;
	case KEY_UP_K4:

		break;
	case KEY_DOWN_K4:
		BEEP_KeyTone();
		app_key_ok();
		break;
	case KEY_LONG_K4:

		break;
#if DEBUG_KEY
		case KEY_UP_K5:

		break;
		case KEY_DOWN_K5:
		//BEEP_KeyTone();
		query_work_sum();
		break;
		case KEY_LONG_K5:

		break;
#endif
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

