/*
 * bsp_hall.h
 *
 *  Created on: 2017Äê6ÔÂ26ÈÕ
 *      Author: fly
 */

#ifndef BSP_INC_BSP_HALL_H_
#define BSP_INC_BSP_HALL_H_

#define HALL_COUNT   3

typedef struct _HALL_T {
	int count;
	uint8_t direction;
	uint8_t lastPos;
} HALL_T;
void bsp_hallInt_open(void);
void bsp_hallInt_close(void);
void Hall_Init(void);
void bsp_hall_1s_pro(void);
void hall_1_interrupt(void);
void hall_2_interrupt(void);
void hall_3_interrupt(void);

#endif /* BSP_INC_BSP_HALL_H_ */
