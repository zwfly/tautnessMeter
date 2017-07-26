#include "app.h"

//uint8_t c;
//DEVICE_T g_tDevice;

/******************************************************************************
 * FUNCTION_PURPOSE: I/O Pin interrupt Service Routine
 ******************************************************************************/
void PinInterrupt_ISR(void)
interrupt 7
{
	PIF = 0x00;                             //clear interrupt flag

}
void main(void) {
	uint8_t ucKeyCode;
	System_Clock_Select(E_HIRCEN);

#if  0
	CKDIV = 1;                        //Fsys = Fosc / (2* CLKDIV) = Fcpu
#endif

	/****************/
	bsp_Init();

	/****************/
	work_Init();
	app_key_init();
	app_charge_Init();

	/****************/
	Show_FW_Version_Number_To_PC();

	while (1) {

		if (Task_time.flag_10ms) {
			Task_time.flag_10ms = 0;
			//////////////////
			BEEP_Pro();
			bsp_KeyScan();
		}
		if (Task_time.flag_100ms) {
			Task_time.flag_100ms = 0;
			//////////////////
			app_key_100ms_pro();
			app_work_100ms_pro();
			app_charge_100ms_pro();
			Repeat_Pro();

		}
		if (Task_time.flag_1s) {
			static uint8_t tmp = 0;
			static uint8_t cnt = 0;
			Task_time.flag_1s = 0;
			//////////////////
			app_key_1s_pro();
			app_work_1s_pro();
			app_charge_1s_pro();

			cnt++;
			if (cnt > 3) {
				cnt = 10;

				tmp++;
//				LCD_Show_REP_Num(tmp % 99);
//				LCD_Show_Pulls_Num(tmp);
//				LCD_Show_CAL_Num(tmp);
			}

//			if (bb) {
//				bb = 0;
//				LCD_Display_Battery_ICO();
//				LCD_Display_REP_ICO();
//				LCD_Display_ABCD('A');
//				LCD_Display_QS_ICO();
//				LCD_Display_COACH_ICO();
//				LCD_Display_Heart_ICO();
//				LCD_Display_CAL_ICO();
//
//			} else {
//				bb = 1;
//				LCD_Clear_Battery_ICO();
//				LCD_Clear_REP_ICO();
//				LCD_Clear_ABCD();
//				LCD_Clear_QS_ICO();
//				LCD_Clear_COACH_ICO();
//				LCD_Clear_Heart_ICO();
//				LCD_Clear_CAL_ICO();

//
//			}
		}
#if 0
		if (TRUE == Get_Data_From_UART1(&c)) {

			printf("true %x\n", c);

			if (c) {
				BEEP_Start(0, 5, 5, 2);
			} else {
				BEEP_Start(0, 5, 5, 1);
			}
		}
#endif
#if 1

		ucKeyCode = bsp_GetKey();
		if (ucKeyCode != KEY_NONE) {
			app_key_pro(ucKeyCode);
		}
#endif
	}
}
