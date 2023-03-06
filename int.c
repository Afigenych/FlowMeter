/*
 * int.c
 *
 * Created: 26.02.2023 18:01:39
 *  Author: Пользователь
 */ 

#include <avr/interrupt.h>
#include "main.h"



//extern volatile CNT_FM_t cnt_fm;



 ISR (RESET_vect)	{

	reti();
};

ISR (NMI_) {
	reti();
}

 ISR (BOD_VLM_vect)	{
	cnt_fm.bod_cnt ++;
	reti();
};

ISR (CLKCTRL_CFDEN_vect) {
	reti();
	
};

 ISR (RTC_PIT_vect) {
	reti();
};

void software_reset (void) {
CPU_CCP = CCP_IOREG_gc;
RSTCTRL_SWRR = RSTCTRL_SWRST_bm;
CPU_CCP &= ~(CCP_IOREG_gc); //need write another value?
};