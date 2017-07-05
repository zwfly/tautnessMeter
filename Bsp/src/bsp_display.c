/*
 * bsp_display.c
 *
 *  Created on: 2017Äê6ÔÂ26ÈÕ
 *      Author: fly
 */

#include "bsp.h"

#define COM0    0x01
#define COM1    0x02
#define COM2    0x04
#define COM3    0x08

static void LCD_Try_Run(void);

void LCD_display_InitHard(void) {

	LCDCON = 0x00;      //;VLCD = 0.9VDD (VDD = 3.3V, VLCD = 3.0V)
						//;1/4 duty, 1/3 bias, 150kO resistor ladder

	LCDCLK = 0x04;      //

	//enable seg pin
	LCDSEG0 = 0xFF;
	LCDSEG1 = 0xFF;
	LCDSEG2 = 0x07;

	LCDCON |= SET_BIT7;  //LCDEN = 1

//	LCD_Try_Run();

}

 void LCD_Clear_All(void) {
	uint8_t i;
	for (i = 0; i < 19; i++) {
		LCDPTR = i;
		LCDDAT = 0;
	}
}

 void LCD_Clear_Bluetooth_ICO(void) {
	clr_SEG10EN;
	LCDPTR = 10;
	LCDDAT = COM0;
}
 void LCD_Display_Bluetooth_ICO(void) {
	set_SEG10EN;
	LCDPTR = 10;
	LCDDAT = COM0;
}

 void LCD_Clear_Bluetooth_Fill_ICO(void) {
	clr_SEG12EN;
	LCDPTR = 12;                            //MCU's SEG0 -- LCD's SEG1
	LCDDAT = COM0;                //LCD's COM1/2

}
 void LCD_Display_Bluetooth_Fill_ICO(void) {
	set_SEG12EN;                   //MCU's SEG0 enable
	LCDPTR = 12;                            //MCU's SEG0 -- LCD's SEG1
	LCDDAT = COM0;                //LCD's COM1/2

}

static void LCD_Clear_Line_up(void) {

}
static void LCD_Display_Line_up(void) {

}
static void LCD_Clear_Battery_ICO(void) {

}
static void LCD_Display_Battery_ICO(void) {

}
static void LCD_Clear_REP_ICO(void) {

}
static void LCD_Display_REP_ICO(void) {

}
static void LCD_Clear_REP_Num(void) {

}
static void LCD_Display_REP_Num(uint8_t num) {

}
static void LCD_Clear_ABCD(void) {

}
static void LCD_Display_ABCD(char c) {

}
static void LCD_Clear_Pulls_Num(void) {

}
static void LCD_Display_Pulls_Num(uint16_t num) {

}
static void LCD_Clear_QS_ICO(void) {

}
static void LCD_Display_QS_ICO(void) {

}
static void LCD_Clear_COACH_ICO(void) {

}
static void LCD_Display_COACH_ICO(void) {

}
static void LCD_Clear_Line_down(void) {

}
static void LCD_Display_Line_down(void) {

}
static void LCD_Clear_Heart_ICO(void) {

}
static void LCD_Display_Heart_ICO(void) {

}
static void LCD_Clear_CAL_Num(void) {

}
static void LCD_Display_CAL_Num(uint16_t num) {

}
static void LCD_Clear_CAL_ICO(void) {

}
static void LCD_Display_CAL_ICO(void) {

}

static void LCD_Try_Run(void) {

	LCD_Clear_Bluetooth_ICO();
	Timer1_Delay1ms(500);
	LCD_Display_Bluetooth_ICO();

	Timer1_Delay1ms(500);
}

