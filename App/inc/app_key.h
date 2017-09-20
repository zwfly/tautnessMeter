/*
 * app_key.h
 *
 *  Created on: 2017Äê7ÔÂ7ÈÕ
 *      Author: admin
 */

#ifndef APP_INC_APP_KEY_H_
#define APP_INC_APP_KEY_H_

typedef enum {
	E_RUN_STATUS_NONE = 0, E_PowerOn, E_PowerDown, E_PowerReady,
} E_RUN_STATUS;

typedef enum {
	E_LEVEL_NONE = 0, E_LEVEL_MODE, E_LEVEL_REP, E_LEVEL_READY, E_LEVEL_PULL,
} E_LEVEL;

typedef struct _DEVICE_T {
	E_RUN_STATUS status;
	E_LEVEL level;
	E_TRAINING_MODE mode;
	char letter;
} DEVICE_T;

extern DEVICE_T g_tDevice;

//extern uint8_t level;
extern uint8_t noOps_timeoutCnt;
void app_key_init(void);
void app_powerKeyInt_open(void);
void app_powerKeyInt_close(void);
void app_key_100ms_pro(void);
void app_key_1s_pro(void);
void app_key_clear_noOps_timeoutCnt(void);
void app_key_pro(uint8_t keyCode);

#endif /* APP_INC_APP_KEY_H_ */
