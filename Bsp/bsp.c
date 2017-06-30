#include "bsp.h"

bit BIT_TMP;  //WTF

void bsp_Init(void) {

	Set_All_GPIO_Quasi_Mode();





//	bsp_InitKey();

	Bright_InitHard();
	BEEP_InitHard();

//	Timer0_InitHard();
//	Timer1_InitHard();



	Uart_InitHard();

}

