/*
 * app_repeat_exe.c
 *
 *  Created on: 2017年7月6日
 *      Author: admin
 */

#include "app.h"

static REPEAT_T g_tRepeat; /* 定义蜂鸣器全局结构体变量 */

/*
 *********************************************************************************************************
 *	函 数 名:
 *	功能说明: 启动。
 *	形    参：_usBeepTime : 蜂鸣时间，单位100ms; 0 表示不鸣叫
 *			  _usStopTime : 停止时间，单位100ms; 0 表示持续鸣叫
 *			 _usCycle : 鸣叫次数， 0 表示持续鸣叫
 *	返 回 值: 无
 *********************************************************************************************************
 */
void Repeat_Start(uint16_t _usDelayTime, uint16_t _usRepeatTime,
		void (*_fun)(void)) {

	g_tRepeat.usDelayTime = _usDelayTime;
	g_tRepeat.usRepeatTime = _usRepeatTime;
	g_tRepeat.fun = _fun;
	g_tRepeat.usCount = 0;
}

/*
 *********************************************************************************************************
 *	函 数 名:
 *	功能说明: 停止。
 *	形    参：无
 *	返 回 值: 无
 *********************************************************************************************************
 */
void Repeat_Stop(void) {
	g_tRepeat.ucEnalbe = 0;
	g_tRepeat.fun = 0;
}

/*
 *********************************************************************************************************
 *	函 数 名:
 *	功能说明: 每隔100ms调用1次该函数，用于控制蜂鸣器发声。该函数在  中被调用。
 *	形    参：无
 *	返 回 值: 无
 *********************************************************************************************************
 */
void Repeat_Pro(void) {
	if (g_tRepeat.ucEnalbe == 0) {
		return;
	}
	if (g_tRepeat.usDelayTime) {
		g_tRepeat.usDelayTime--;
		return;
	}

	if (++g_tRepeat.usCount >= g_tRepeat.usRepeatTime) {
		g_tRepeat.usCount = 0;
		g_tRepeat.fun();
	}

}
