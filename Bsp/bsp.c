#include "bsp.h"

bit BIT_TMP;  //WTF

void bsp_Init(void) {

//	Set_All_GPIO_Quasi_Mode();
	Set_All_GPIO_Input_Mode();

	bsp_InitKey();
	Hall_InitHard();
	Bright_InitHard();
	BEEP_InitHard();
	LCD_display_InitHard();
	Timer0_InitHard();
//	Timer1_InitHard();

	Uart_InitHard();

	set_EA;                                     //enable interrupts

}

