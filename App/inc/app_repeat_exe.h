/*
 * app_repeat_exe.h
 *
 *  Created on: 2017��7��6��
 *      Author: admin
 */

#ifndef APP_INC_APP_REPEAT_EXE_H_
#define APP_INC_APP_REPEAT_EXE_H_

typedef struct _REPEAT_T {
	uint8_t ucEnalbe;
	uint16_t usDelayTime;
	uint16_t usRepeatTime;
	uint16_t usCount;
	void (*fun)(void);

} REPEAT_T;

/* ���ⲿ���õĺ������� */

void Repeat_Start(uint16_t _usDelayTime, uint16_t _usRepeatTime,
		void (*_fun)(void));
void Repeat_Stop(void);

void Repeat_Pro(void);

#endif /* APP_INC_APP_REPEAT_EXE_H_ */
