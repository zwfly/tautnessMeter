/*
 * bsp_hall.c
 *
 *  Created on: 2017Äê6ÔÂ26ÈÕ
 *      Author: fly
 */

#include "bsp.h"

void Hall_InitHard(void) {
  PICON = PICON_VAL;
    PITYP = PITYP_VAL;
    PINEN = PINEN_VAL;
    PIPEN = PIPEN_VAL;
    
    set_EPI;
}

void hall_1_interrupt(void) {

}
void hall_2_interrupt(void) {

}
void hall_3_interrupt(void) {

}
