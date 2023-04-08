/*
 * int.c
 *
 * Created: 26.02.2023 18:01:39
 *  Author: Пользователь
 */ 

#include <avr/interrupt.h>
#include "mpr121.h"

#include "rtc.h"
#include "main.h"
#include "avr.h"
#include "twi_io.h"

#include "int.h"





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

ISR (PORTD_PORT_vect) {
	uint8_t io_flag = pfm_ctrl->io_flag;
	pfm_ctrl->io_flag = io_flag | FM_RD_IR_bm;
	reti();
};

ISR (TWI0_TWIM_vect) {
	
	uint8_t status = TWI0_MSTATUS;
	
	if(status & TWI_WIF_bm)	{
		if (status & TWI_RXACK_bm)	{
			ptwi_state->twi_host_operation = TWI_RXACK_bm;
			reti();
		};
		if (status & TWI_ARBLOST_bm)	{
			ptwi_state->twi_host_operation = TWI_ARBLOST_bm;
			reti();
		};
		if (status & TWI_CLKHOLD_bm)	{
			ptwi_state->twi_host_operation = TWI_CLKHOLD_bm;
			reti();
		};
	};
	
	if(status & TWI_RIF_bm)	{
		ptwi_state->twi_host_operation = TWI_RIF_bm;
		reti();
	};
	
	reti();
};

	

ISR (SPI0_INT_vect)	{
	
	cnt_fm.fm_ir = PORTD1_INT;
	reti();
};

ISR (USART0_RXC_vect)	{
	reti();
};
ISR (USART0_DRE_vect)	{
	reti();
};
ISR (USART0_TXC_vect)	{
	reti();
};

ISR (USART1_RXC_vect)	{
	reti();
};
ISR (USAR1_DRE_vect)	{
	reti();
};
ISR (USART1_TXC_vect)	{
	reti();
};

void software_reset (void) {
CPU_CCP = CCP_IOREG_gc;
RSTCTRL_SWRR = RSTCTRL_SWRST_bm;
CPU_CCP &= ~(CCP_IOREG_gc); //need write another value?
};