/*
 * bsp_adc.h
 *
 *  Created on: 2017Äê7ÔÂ7ÈÕ
 *      Author: admin
 */

#ifndef BSP_INC_BSP_ADC_H_
#define BSP_INC_BSP_ADC_H_

typedef enum {
	E_CHARGE_STATUS_PLACE = 0,
	E_NeedCharge,
	E_InCharge,
	E_FullCharge,
	E_Discharge,
} E_CHARGE_STATUS;

typedef struct _CHARGE_T {
	E_CHARGE_STATUS status;
	uint8_t count;

} CHARGE_T;

void ADC_Init(void);
void app_charge_100ms_pro(void);

#endif /* BSP_INC_BSP_ADC_H_ */
