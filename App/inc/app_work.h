/*
 * app_work.h
 *
 *  Created on: 2017Äê7ÔÂ6ÈÕ
 *      Author: admin
 */

#ifndef APP_INC_APP_WORK_H_
#define APP_INC_APP_WORK_H_

typedef enum {
	E_Simple_metering_mode, E_Quick_start_mode, E_Coach,
} E_TRAINING_MODE;

typedef struct _WORK_T {
	E_TRAINING_MODE mode;
	char reps_mode;
	uint8_t reps_num;
	uint16_t pulls_num;
	uint16_t cal_num;

} WORK_T;

void work_Init(void);
void app_work_1s_pro(void);

#endif /* APP_INC_APP_WORK_H_ */
