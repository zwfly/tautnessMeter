/*
 * bsp_hall.c
 *
 *  Created on: 2017年6月26日
 *      Author: fly
 */

#include "bsp.h"
#include "app_work.h"
#include "bsp_beep.h"
#include "app_key.h"

#define HALL_NUM  3
#define HALL_CNT_UP  12
#define HALL_CNT_DOWN  5

static HALL_T g_tHall;

static void Hall_InitHard(void) {

	P5M1 &= ~ SET_BIT4;
	P5M2 |= SET_BIT4;

//	app_powerKeyInt_close();

	bsp_hallInt_open();

	set_EPI;
}
static void Hall_InitVar(void) {
	g_tHall.count = 0;
	g_tHall.direction = 0;
	g_tHall.lastPos = 0;

}

void bsp_hallInt_open(void) {

	P54 = 0;

	set_PIPS2;
	clr_PIPS1;
	set_PIPS0;

	clr_PIT0;
	set_PIT1;
	set_PIT2;
	set_PIT3;
	clr_PIT4;
	clr_PIT5;
	clr_PIT6;
	clr_PIT7;

	clr_PINEN0;
	set_PINEN1;
	set_PINEN2;
	set_PINEN3;
	clr_PINEN4;
	clr_PINEN5;
	clr_PINEN6;
	clr_PINEN7;

	PIPEN = 0x00;
	clr_PIPEN1;
	clr_PIPEN2;
	clr_PIPEN3;

}
void bsp_hallInt_close(void) {

	P54 = 1;

	clr_PIT1;
	clr_PIT2;
	clr_PIT3;

	clr_PINEN1;
	clr_PINEN2;
	clr_PINEN3;
}
void Hall_Init(void) {
	Hall_InitHard();
	Hall_InitVar();
}

void bsp_hall_1s_pro(void) {

	printf("meter count %d\r\n", g_tHall.count);

}

//123 拉长
void hall_pro(uint8_t n) {
	static BIT valid_flag = 0;

	noOps_timeoutCnt = 0;
	lcd_bright_on();

	switch (n) {
	case 0:
		if (g_tHall.lastPos == 0) {
			if (g_tHall.direction) {
				g_tHall.direction = 0;
			} else {
				g_tHall.direction = 1;
			}
		} else if (g_tHall.lastPos == 1) {
			g_tHall.direction = 0;
		} else if (g_tHall.lastPos == 2) {
			g_tHall.direction = 1;  //拉长
		}
		break;
	case 1:
		if (g_tHall.lastPos == 1) {
			if (g_tHall.direction) {
				g_tHall.direction = 0;
			} else {
				g_tHall.direction = 1;
			}
		} else if (g_tHall.lastPos == 2) {
			g_tHall.direction = 0;
		} else if (g_tHall.lastPos == 0) {
			g_tHall.direction = 1;  //拉长
		}
		break;
	case 2:
		if (g_tHall.lastPos == 2) {
			if (g_tHall.direction) {
				g_tHall.direction = 0;
			} else {
				g_tHall.direction = 1;
			}
		} else if (g_tHall.lastPos == 0) {
			g_tHall.direction = 0;
		} else if (g_tHall.lastPos == 1) {
			g_tHall.direction = 1;  //拉长
		}
		break;
	}
	g_tHall.lastPos = n;
	if (g_tHall.direction) {
		g_tHall.count++;
	} else {
		g_tHall.count--;
	}
	if (valid_flag) {
		if (g_tHall.count < HALL_CNT_DOWN) {
			valid_flag = 0;
		}
	} else {
		if (g_tHall.count > HALL_CNT_UP) {
			valid_flag = 1;
			/* your code   --start */
			// 拉一次计数一次，计数一次调用一次
			query_work_sum();
			/* your code   --end */
		}
	}

}

void hall_1_interrupt(void) {
	hall_pro(0);
}
void hall_2_interrupt(void) {
	hall_pro(1);
}
void hall_3_interrupt(void) {
	hall_pro(2);
}
