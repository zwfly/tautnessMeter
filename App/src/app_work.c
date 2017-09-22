/*
 * app_work.c
 *
 *  Created on: 2017年7月6日
 *      Author: admin
 */

#include "app.h"
#include <string.h>

#define BEEP_SHORT_TIME   10
#define BEEP_LONG_TIME    30
#define COACH_DELAY_TIME  200
#define COACH_PACE_TIME   400
#define CAL_a 2

const uint8_t Rep_Pull_num[4][2] = { { 10, 20 }, { 20, 25 }, { 30, 30 }, { 50,
		40 } };

static idata BEEP_T g_tBeep; /* 定义蜂鸣器全局结构体变量 */
//static BEEP_T g_tBeep; /* 定义蜂鸣器全局结构体变量 */
WORK_T g_tWork;
static uint8_t count_NoAction = 0;
static BIT pull_once_flag = 0;
static BIT coach_mode_beep3_flag = 0;

static void app_work_pro(void);

void work_Init(void) {
	g_tWork.mode = E_Simple_metering_mode;
	g_tWork.reps_mode = 'A';
	g_tWork.sum = 0;
	g_tWork.reps_num = 0;
	g_tWork.pulls_num = 0;
	g_tWork.cal_num = 0;

	count_NoAction = 0;
}

void query_work_sum(void) {

	if (g_tDevice.level == E_LEVEL_PULL) {
		g_tWork.sum++;
		if (g_tWork.sum > 10000) {
			g_tWork.sum = 0;
		}
		pull_once_flag = 1;
	}

	if (g_tDevice.level == E_LEVEL_READY) {
		g_tDevice.level = E_LEVEL_PULL;

		g_tWork.sum++;
		if (g_tWork.sum > 10000) {
			g_tWork.sum = 0;
		}
		pull_once_flag = 1;
	}
}

void app_work_1s_pro(void) {
	if (count_NoAction < 255) {
		count_NoAction++;
	}

}
void app_work_100ms_pro(void) {
	static uint8_t coach_mode_beep3_cnt = 0;

	if (pull_once_flag) {
		static BIT level_pull_init_flag = 0;
		pull_once_flag = 0;
		///////////////////
		app_key_clear_noOps_timeoutCnt();
		app_work_pro();

		if (g_tDevice.level == E_LEVEL_PULL) {
			if (level_pull_init_flag == 0) {
				level_pull_init_flag = 1;
				BEEP_Start(1, BEEP_SHORT_TIME, COACH_PACE_TIME, 0);
			}
		} else {
			level_pull_init_flag = 0;
		}
	}
	if (coach_mode_beep3_flag) {
		coach_mode_beep3_cnt++;
		if (coach_mode_beep3_cnt > 6) {
			coach_mode_beep3_flag = 0;
			printf("coach set beep\n");
			BEEP_Start_struct(&g_tBeep);
		}
	} else {
		coach_mode_beep3_cnt = 0;
	}
}

static void app_work_pro(void) {
	static BIT finish_flag = 0;
	static BIT reps_num_appear_flag = 0;

	switch (g_tWork.mode) {
	case E_TRAINING_NONE:

		break;
	case E_Simple_metering_mode:

		if (g_tWork.sum % 10 == 0) {
			BEEP_Start(1, BEEP_LONG_TIME, 1, 1);
		} else {
			BEEP_Start(1, BEEP_SHORT_TIME, 1, 1);
		}
		g_tWork.pulls_num = g_tWork.sum;
		g_tWork.cal_num = g_tWork.sum * CAL_a;

		/********************/
		LCD_Show_Pulls_Num(g_tWork.pulls_num);
		LCD_Show_CAL_Num(g_tWork.cal_num);

		LCD_Clear_REP_Num();
		LCD_Clear_REP_ICO();
		LCD_Clear_ABCD();
		LCD_Clear_QS_ICO();
		LCD_Clear_COACH_ICO();

		LCD_Show_CAL_ICO();
		LCD_Show_Line_up();
		break;
	case E_Quick_start_mode:

		if (finish_flag) {
			BEEP_Start(1, BEEP_SHORT_TIME, 1, 1);
			g_tWork.sum = Rep_Pull_num[g_tWork.reps_mode - 'A'][0]
					* Rep_Pull_num[g_tWork.reps_mode - 'A'][1];
		} else {
			if (g_tWork.sum
					== Rep_Pull_num[g_tWork.reps_mode - 'A'][0]
							* Rep_Pull_num[g_tWork.reps_mode - 'A'][1]) {
				finish_flag = 1;
				BEEP_Start(1, 3 * BEEP_SHORT_TIME, 1, 1);
			} else {
				if (g_tWork.sum % Rep_Pull_num[g_tWork.reps_mode - 'A'][1]
						== 0) {
					BEEP_Start(1, BEEP_SHORT_TIME, BEEP_SHORT_TIME, 3);
				} else {
					BEEP_Start(1, BEEP_SHORT_TIME, 1, 1);
				}
			}
			reps_num_appear_flag = 1;
			g_tWork.reps_num = g_tWork.sum
					/ Rep_Pull_num[g_tWork.reps_mode - 'A'][1];
			g_tWork.pulls_num = g_tWork.sum
					% Rep_Pull_num[g_tWork.reps_mode - 'A'][1];
			g_tWork.cal_num = g_tWork.sum * CAL_a;
		}
		LCD_Show_REP_Num(g_tWork.reps_num);
		LCD_Show_Pulls_Num(g_tWork.pulls_num);
		LCD_Show_CAL_Num(g_tWork.cal_num);

		LCD_Show_REP_ICO();
		LCD_Show_ABCD(g_tWork.reps_mode);

		LCD_Show_QS_ICO();
		LCD_Clear_COACH_ICO();

		LCD_Show_CAL_ICO();
		LCD_Show_Line_up();

		break;
	case E_Coach_mode:
		if (finish_flag) {
			BEEP_Start(COACH_DELAY_TIME, BEEP_SHORT_TIME, 1, 1);
			g_tWork.sum = Rep_Pull_num[g_tWork.reps_mode - 'A'][0]
					* Rep_Pull_num[g_tWork.reps_mode - 'A'][1];
		} else {
			if (g_tWork.sum
					== Rep_Pull_num[g_tWork.reps_mode - 'A'][0]
							* Rep_Pull_num[g_tWork.reps_mode - 'A'][1]) {
				finish_flag = 1;
				BEEP_Start(1, 3 * BEEP_SHORT_TIME, 1, 1);
			} else {
				if (g_tWork.sum % Rep_Pull_num[g_tWork.reps_mode - 'A'][1]
						== 0) {
					BEEP_T* beep_pt = 0;
					coach_mode_beep3_flag = 1;
					beep_pt = BEEP_Start_get();
					memcpy(&g_tBeep, beep_pt, sizeof(BEEP_T));
					printf("coach get beep\n");
					BEEP_Start(1, BEEP_SHORT_TIME, BEEP_SHORT_TIME, 3);
				} else {
//					BEEP_Start(COACH_DELAY_TIME, BEEP_SHORT_TIME, 1, 1);
				}
			}
			reps_num_appear_flag = 1;
			g_tWork.reps_num = g_tWork.sum
					/ Rep_Pull_num[g_tWork.reps_mode - 'A'][1];
			g_tWork.pulls_num = g_tWork.sum
					% Rep_Pull_num[g_tWork.reps_mode - 'A'][1];
			g_tWork.cal_num = g_tWork.sum * CAL_a;
		}
		LCD_Show_REP_Num(g_tWork.reps_num);
		LCD_Show_Pulls_Num(g_tWork.pulls_num);
		LCD_Show_CAL_Num(g_tWork.cal_num);

		LCD_Show_REP_ICO();
		LCD_Show_ABCD(g_tWork.reps_mode);

		LCD_Clear_QS_ICO();
		LCD_Show_COACH_ICO();

		LCD_Show_CAL_ICO();
		LCD_Show_Line_up();

		break;
	}

#if 0
	LCD_Show_Pulls_Num(g_tWork.pulls_num);
	LCD_Show_CAL_Num(g_tWork.cal_num);
	if (reps_num_appear_flag) {
		LCD_Show_REP_Num(g_tWork.reps_num);
	} else {
		LCD_Clear_REP_Num();
	}
#endif
}

