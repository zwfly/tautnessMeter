#include "app.h"

void main(void) {
	uint8_t ucKeyCode;
	System_Clock_Select(E_HIRCEN);

#if  0
	CKDIV = 1;                        //Fsys = Fosc / (2* CLKDIV) = Fcpu
#endif

	/****************/
	bsp_Init();

	/****************/
	Repeat_Init();
	work_Init();

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
			app_work_100ms_pro();
			Repeat_Pro();

		}
		if (Task_time.flag_1s) {
			static uint8_t tmp = 0;
			static uint8_t cnt = 0;
			Task_time.flag_1s = 0;
			//////////////////
			app_work_1s_pro();

			cnt++;
			if (cnt > 9) {
				cnt = 10;

				tmp++;
				LCD_Display_REP_Num(tmp % 99);
				LCD_Display_Pulls_Num(tmp);
				LCD_Display_CAL_Num(tmp);
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
//
//
//
//			}
		}
#if 1

		ucKeyCode = bsp_GetKey();
		if (ucKeyCode != KEY_NONE) {
			app_key_pro(ucKeyCode);
		}
#endif
	}
}
