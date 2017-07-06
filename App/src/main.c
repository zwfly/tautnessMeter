#include "app.h"

void Tmp_Delay(uint32_t xdata u32CNT)
{
	UINT32 xdata i,j;
	for (i=0;i<u32CNT;i++)
	j ++;
}

uint8_t ucKeyCode;
void main(void) {

	System_Clock_Select(E_HIRCEN);

#if  0
	CKDIV = 1;                        //Fsys = Fosc / (2* CLKDIV) = Fcpu
#endif

	bsp_Init();

	/****************/

	Repeat_Init();
	/****************/
	Show_FW_Version_Number_To_PC();

	while (1) {
//	Send_Data_To_UART1(0x55);
//		printf("test\n");

//		Tmp_Delay(50000);

		if (Task_time.flag_10ms) {
			Task_time.flag_10ms = 0;
			//////////////////
			BEEP_Pro();
			bsp_KeyScan();
		}
		if (Task_time.flag_100ms) {
			Task_time.flag_100ms = 0;
			//////////////////

			Repeat_Pro();

			/*if (P03 == 0) {
			 printf("P03\n");
			 }
			 if (P04 == 0) {
			 printf("P04\n");
			 }
			 if (P05 == 0) {
			 printf("P05\n");
			 }
			 if (P06 == 0) {
			 printf("P06\n");
			 }*/

		}
		if (Task_time.flag_1s) {
			static bit bb = 0;
			Task_time.flag_1s = 0;
			//////////////////
			app_work_1s_pro();
			//printf("test\n");
			if (bb) {
				bb = 0;
				LCD_Clear_Bluetooth_ICO();

			} else {
				bb = 1;
				LCD_Display_Bluetooth_ICO();
			}

		}
#if 1

		ucKeyCode = bsp_GetKey();
		if (ucKeyCode != KEY_NONE) {
//			BEEP_KeyTone();
			switch (ucKeyCode) {
			case KEY_UP_K1:

				break;
			case KEY_DOWN_K1:

				break;
			case KEY_LONG_K1:

				break;
			case KEY_UP_K2:

				break;
			case KEY_DOWN_K2:

				break;
			case KEY_LONG_K2:

				break;
			case KEY_UP_K3:

				break;
			case KEY_DOWN_K3:

				break;
			case KEY_LONG_K3:

				break;
			case KEY_UP_K4:

				break;
			case KEY_DOWN_K4:

				break;
			case KEY_LONG_K4:

				break;
			case KEY_UP_K1K3:

				break;
			case KEY_DOWN_K1K3:

				break;
			case KEY_LONG_K1K3:

				break;
			default:
				BEEP_KeyTone();
				break;

			}
		}
#endif
	}
}
