//twi_io

#include <stdint-gcc.h>
#include <avr/sfr_defs.h>
#include "ioavr64dd32.h"

#include "twi_io.h"

/*
void init_twi_ports (void) {
		
	TWI0_CTRLA = TWI_INPUTLVL_I2C_gc | TWI_SDASETUP_4CYC_gc | TWI_SDAHOLD_50NS_gc | TWI_FMPEN_OFF_gc;
	TWI0_DUALCTRL = TWI_INPUTLVL_I2C_gc | TWI_SDAHOLD_OFF_gc | TWI_FMPEN_OFF_gc | TWI_ENABLE_bp;
	TWI0_DBGCTRL = TWI_DBGRUN_RUN_gc;
};
*/


/*

void init_twi_host (void) {
	
};
*/

int8_t send_twi (int8_t address, int8_t data)	{
	int8_t error = 0;
	return error;
};

int8_t read_twi (int8_t address)	{
	return TWI0.MDATA;
};