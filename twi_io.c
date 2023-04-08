//twi_io

#include <stdint-gcc.h>
#include <avr/sfr_defs.h>
#include "rtc.h"
#include "mpr121.h"
#include "ioavr64dd32.h"
#include "main.h"
#include "twi_io.h"

volatile TWI_STATE_t twi_state;
volatile TWI_STATE_t * ptwi_state;
volatile TWI_IOBUF_t twi_iobuf;


/*
 void twi_send_command (uint8_t addr, uint8_t command, uint8_t data_length, TWIO_BUF_t * data_buf) {
	 
	 TWI0_MADDR = addr | TWI_WR;
	 TWI0_MDATA = command;
	 
 };
*/
/*
int8_t send_twi (int8_t address, int8_t data)	{
	int8_t error = 0;
	return error;
};


int8_t read_twi (int8_t address)	{
	
	return TWI0.MDATA;
};
*/
/*
int8_t twi_io (int8_t addr, int8_t dir,  *FM_INT_FLAG_t  fm_portd_int, int8_t length )	{
	int8_t result;
	return result;
	
};
*/
/*
void twi_read_IR (void)	{
	
 TWI0_MADDR = ADDR_IR | TWI_RD;
	
};
*/
/*
void twi_io(uint8_t dev_addr, void * pbuf) {
	switch(dev_addr){
		case ADDR_IR:
			TWI0_MADDR = ADDR_IR | TWI_RD;
		break;
		case ADDR_KB:
			TWIO_MADDR = ADDR_KB | pbuf->command;
		break;
		case ADDR_LED:
		break;
		case ADDR_RTC_EEPROM:
		break;
		case ADDR_RTC_SRAM_RTCC:
		break;
		case ADDR_SS:
		break;
	};
	
};
*/

void twi_io_readIR(void)	{
	TWI0_MADDR = ADDR_IR | TWI_RD;
	
};
void twi_io_writeKB	(void)	{
	
};
void twi_io_writeCS (void)	{
	
};
void twi_io_readRTC (void)	{
	
};
void twi_io_writeRTC (void)	{
	
};
void twi_io_writeLCD (void) {

};
/*
void twi_io_write_mpr121(void)	{
	uint8_t i,k, status;
	
	TWI0_MADDR = ADDR_KB | TWI_WR;
	k=1;
	while(k)	{
		status = TWI0_MSTATUS;
		if(status & TWI_WIF_bm)	{
			if(status & TWI_RXACK_bm) {
				
			};
			if(status & TWI_ARBLOST_bm	{
				
			};
			if (status & TWI_CLKHOLD_bm)	{
				
			}
		TWI0_MDATA = (pmpr121_io->addr_reg) | TWI_WR;
			}
			
			
		};
	//	if(status )
		
		if (TWI0_MSTATUS_TWI) k=0;
		
	}
	
	
	for(i=0; i<pmpr121_io->data_length; i++) {
		TWI0_MDATA = pmpr121_io->data_reg [i];
	};
	

};
*/
void twi_io_read_mpr121(void)	{
};
	
uint8_t set_twi_bus_idle(void) {
	TWI0_MSTATUS = TWI_BUSSTATE_IDLE_gc;
	if ((TWI0_MSTATUS & TWI_BUSSTATE_gm) == TWI_BUSSTATE_IDLE_gc ) {
		return 1;
	}else return 0;
};
void twi_set_addr (uint8_t addr, uint8_t direction)	{
	TWI0_MADDR = addr|direction;
};
uint8_t twi_status_operation (void) {
	return ptwi_state->twi_host_operation;
};
void twi_send_byte (uint8_t data	){
		TWI0_MDATA = data;
};