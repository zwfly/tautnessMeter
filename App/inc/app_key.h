/*
 * app_key.h
 *
 *  Created on: 2017Äê7ÔÂ7ÈÕ
 *      Author: admin
 */

#ifndef APP_INC_APP_KEY_H_
#define APP_INC_APP_KEY_H_

typedef enum {
	E_RUN_STATUS_PLACE = 0,
	E_PowerOn,
	E_PowerOff,
	E_Sleep,
} E_RUN_STATUS;
typedef struct _DEVICE_T {
	E_RUN_STATUS status;

} DEVICE_T;

void app_key_init(void);
void app_key_pro(uint8_t keyCode);

#endif /* APP_INC_APP_KEY_H_ */
