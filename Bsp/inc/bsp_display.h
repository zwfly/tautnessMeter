/*
 * bsp_display.h
 *
 *  Created on: 2017Äê6ÔÂ26ÈÕ
 *      Author: fly
 */

#ifndef BSP_INC_BSP_DISPLAY_H_
#define BSP_INC_BSP_DISPLAY_H_

typedef enum {
	E_NUM_0,
	E_NUM_1,
	E_NUM_2,
	E_NUM_3,
	E_NUM_4,
	E_NUM_5,
	E_NUM_6,
	E_NUM_7,
	E_NUM_8,
	E_NUM_9,
	E_NUM_A,
	E_NUM_B,
	E_NUM_C,
	E_NUM_D,
	E_NUM_E,
	E_NUM_F,
} E_DISPLAY_NUM;

void LCD_Clear_All(void);
void LCD_Clear_Bluetooth_ICO(void);
void LCD_Display_Bluetooth_ICO(void);
void LCD_Clear_Bluetooth_Fill_ICO(void);
void LCD_Display_Bluetooth_Fill_ICO(void);
void LCD_Clear_Line_up(void);
void LCD_Display_Line_up(void);
void LCD_Clear_Battery_ICO(void);
void LCD_Display_Battery_ICO(void);
void LCD_Clear_REP_ICO(void);
void LCD_Display_REP_ICO(void);
void LCD_Clear_REP_Num(void);
void LCD_Display_REP_Num(uint8_t num);
void LCD_Clear_ABCD(void);
void LCD_Display_ABCD(char c);
void LCD_Clear_Pulls_Num(void);
void LCD_Display_Pulls_Num(uint16_t num);
void LCD_Clear_QS_ICO(void);
void LCD_Display_QS_ICO(void);
void LCD_Clear_COACH_ICO(void);
void LCD_Display_COACH_ICO(void);
void LCD_Clear_Line_down(void);
void LCD_Display_Line_down(void);
void LCD_Clear_Heart_ICO(void);
void LCD_Display_Heart_ICO(void);
void LCD_Clear_CAL_Num(void);
void LCD_Display_CAL_Num(uint16_t num);
void LCD_Clear_CAL_ICO(void);
void LCD_Display_CAL_ICO(void);

void LCD_display_InitHard(void);

#endif /* BSP_INC_BSP_DISPLAY_H_ */
