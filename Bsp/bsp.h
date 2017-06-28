
#ifndef _BSP_H_
#define _BSP_H

#include <stdio.h>
#include <N76E616.h>
#include "Version.h"
#include "Typedef.h"
#include "Define.h"
#include "SFR_Macro.h"
#include "Common.h"
#include "Delay.h"
#include "Display.h"


#include "bsp_beep.h"
#include "bsp_key.h"
#include "bsp_bright.h"
#include "bsp_display.h"
#include "bsp_hall.h"
#include "bsp_bt.h"
#include "bsp_uart.h"

#ifndef TRUE
	#define TRUE  1
#endif

#ifndef FALSE
	#define FALSE 0
#endif




/* 提供给其他C文件调用的函数 */
void bsp_Init(void);
void bsp_Idle(void);

#endif

/***************************** (END OF FILE) *********************************/
