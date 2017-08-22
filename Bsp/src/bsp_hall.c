/*
 * bsp_hall.c
 *
 *  Created on: 2017年6月26日
 *      Author: fly
 */

#include "bsp.h"
#include "app_work.h"
#include "bsp_beep.h"

#define HALL_NUM  3
#define HALL_CNT_UP  100
#define HALL_CNT_DOWN  10

static HALL_T g_tHall;

static void Hall_InitHard(void) {

	P5M1 &= ~ SET_BIT4;
	P5M2 |= SET_BIT4;

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

	set_PIT1;
	set_PIT2;
	set_PIT3;

	set_PINEN1;
	set_PINEN2;
	set_PINEN3;

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


//123 拉长
void hall_pro(uint8_t n) {
	static BIT valid_flag = 0;


	if (((n - g_tHall.lastPos) == 1) || ((g_tHall.lastPos - n) == 2)) {
		g_tHall.direction = 1;  //拉长方向
		if (g_tHall.count < 255) {
			g_tHall.count++;
		}

	} else {
		g_tHall.direction = 0;  //收缩方向
		if (g_tHall.count) {
			g_tHall.count--;
		}
	}
	g_tHall.lastPos = n;

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
	hall_pro(1);
}
void hall_2_interrupt(void) {
	hall_pro(2);
}
void hall_3_interrupt(void) {
	hall_pro(3);
}
