/*
 * GccApplication1.c
 *
 * Created: 15.02.2023 11:24:27
 * Author : user
 */ 
#include <stdint-gcc.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "ioavr64dd32.h"
#include "rtc.h"
#include "twi_io.h"
#include "mpr121.h"

#include "main.h"
#include "avr.h"
#include "wdt.h"
#include "int.h"

volatile CNT_FM_t cnt_fm;
volatile FM_CTRL_t fm_ctrl;
volatile FM_CTRL_t * pfm_ctrl = &fm_ctrl;
//volatile FM_INT_FLAG_t * fm_int_flag_struct;
//volatile int8_t result;


	
	
int main(void)
{
	cnt_fm.state_fm = FM_INIT;
	init_avr();
	init_wdt();
	init_pit();
	init_BOD();
	// select pin position
	init_mpr121 ();
	
	cnt_fm.state_fm = FM_NORMAL;
	while (1)	{
		uint8_t io_flag = pfm_ctrl->io_flag;
		uint8_t io_processing = pfm_ctrl->io_processing;
		
		if ((io_flag & FM_RD_IR_bm) & !(io_processing & FM_RD_IR_bm)){
			pfm_ctrl->io_processing = io_processing | FM_RD_IR_bm;
			twi_io_readIR ();
			
		} else 	{
			if(pfm_ctrl->ir & FM_RD_KB_bm)	{
				pfm_ctrl->io_flag = io_flag | FM_RD_KB_bm;
				pfm_ctrl->io_processing = (io_processing & !(FM_RD_KB_bm));
			};
		};
		
		if ((io_flag & FM_RD_KB_bm) & !(io_processing & FM_RD_KB_bm)){
			pfm_ctrl->io_processing = io_processing | FM_RD_KB_bm;
			twi_io_readKB ();
		};
		if ((io_flag & FM_WR_RTC_bm) & !(io_processing & FM_WR_RTC_bm))	{
			pfm_ctrl->io_processing = io_processing | FM_WR_RTC_bm;
			twi_io_RTC ();		
		};
		if ((io_flag & FM_RD_RTC_bm) & !(io_processing & FM_RD_RTC_bm))	{
			pfm_ctrl->io_processing = io_processing | FM_RD_RTC_bm;
			twi_io_RTC ();
		};
	
		
		if ((io_flag & FM_WR_LCD_bm) & !(io_processing & FM_WR_LCD_bm))	{
			pfm_ctrl->io_processing = io_processing | FM_WR_LCD_bm;
			twi_io_writeLCD ();
					
		};
		if ((io_flag & FM_WR_CS_bm)	& (io_processing & FM_WR_CS_bm)){
			pfm_ctrl->io_processing = io_processing | FM_WR_CS_bm;
			twi_io_writeCS ();
			
		};
	};
	
//	twi_state = 
	
	void processingIR (void)	{
	};
	
//	uint8_t ir;
/*	while (1) {
	
		if(PORTD_INTFLAGS & PORT_INT1_bm) {
			if( (TWI0_MSTATUS & TWI_CLKHOLD_bm) || ((TWI0_MSTATUS & TWI_BUSSTATE_gm) == TWI_BUSSTATE_IDLE_gc))	{
				TWI0_MADDR = ADDR_IR | TWI_RD;
			};
//				else {
//			processingIR ();
		
		};
	};
	
*/
/*	
	do {((PORTD_INTFLAGS & PORT_INT1_bm) & (( TWI0_MSTATUS &  TWI_BUSSTATE_gm ) == TWI_BUSSTATE_IDLE_gc))	{
		TWI0_MADDR = ADDR_IR | TWIO_RD;
		PORTD_INTFLAGS = INP_INT_bm;
		
	}while (1);
	*/
	
/*
	while ((PORTD_INTFLAGS & PORT_INT1_bm) & (( TWI0_MSTATUS &  TWI_BUSSTATE_gm ) == TWI_BUSSTATE_IDLE_gc))	{
					TWI0_MADDR = ADDR_IR | TWIO_RD;
					PORTD_INTFLAGS = INP_INT_bm; // clear int flag
	} do {

 
*/

/*
    while (1) 
    {
		
		if((PORTD_INTFLAGS & PORT_INT1_bm) & (( TWI0_MSTATUS &  TWI_BUSSTATE_gm ) == TWI_BUSSTATE_IDLE_gc)) {
			TWI0_MADDR = ADDR_IR | TWIO_RD;
			PORTD_INTFLAGS = INP_INT_bm; // clear int flag
		};
		
	cnt_fm.fm_ir = TWI0_MDATA;
		
		ir = cnt_fm.fm_ir;
		if (ir & INT_US1)	{
		};
		if (ir & INT_US2)	{
		};
		if (ir & INT_US3)	{
		};
		if (ir & INT_US4)	{
		};
		if (ir & INT_KB)	{
//			twi_iobuf.dev_addr = ADDR_KB;
//			twi_iobuf.reg_addr = MPR121_TOUCH_STATUS_REG;
//			twi_iobuf.command = MPR121_CMD_READ_TOUCH_STATUS;
//			twi_iobuf.data_length = MPR121_BUF_SIZE;
			
		};
		if (ir & INT_CD)	{
		}
		if (ir & INT_FAULT)	{
		};
	};
*/
//		};
		
 };

