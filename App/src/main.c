#include "bsp.h"

void Tmp_Delay(uint32_t xdata u32CNT)
{
	UINT32 xdata i,j;
	for (i=0;i<u32CNT;i++)
	j ++;
}

uint8_t ucKeyCode;
void main(void) {

	System_Clock_Select(E_HIRCEN);

	bsp_Init();

	InitialUART1_Timer3(9600);
	


	set_P30;
	set_P31;
	while (1) {
//	Send_Data_To_UART1(0x55);
		printf("test\n");

Tmp_Delay(10000);
	

#if 0
		BEEP_Pro();
		bsp_KeyScan();

		ucKeyCode = bsp_GetKey();

		if (ucKeyCode != KEY_NONE) {
			switch (ucKeyCode) {
				case KEY_DOWN_K1: /* K1������ ��ӡ����ִ����� */

				break;

				case KEY_DOWN_K2: /* K2������ ͨ������OSTaskQPost��������AppTaskMsgPro������ */

				break;
				case KEY_DOWN_K3:

				break;
				default: /* �����ļ�ֵ������ */

				break;

			}
		}
#endif
	}
}
