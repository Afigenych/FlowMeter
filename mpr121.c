/*
 * mpr121.c
 *
 * Created: 27.03.2023 10:09:39
 *  Author: Пользователь
 */ 
#include <stdint-gcc.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "ioavr64dd32.h"
#include "twi_io.h"
#include "mpr121.h"

MPR121_IO_t mpr121_io;
MPR121_IO_t * pmpr121_io;
//pmpr121_io = &mpr121_io;

void init_mpr121 (void) {
	uint8_t status_operation = 0;
	uint8_t state_init = MPR121_INIT_BEGIN;
	uint8_t addr_reg [NUMBER_REG_FOR_INIT]= {MPR121_AUTOCONFIG_CONTROL_0_REG,\
											 MPR121_AUTOCONFIG_CONTROL_1_REG,\
											 MPR121_AUTOCONFIG_USL_REG,\
											 MPR121_AUTOCONFIG_LSL_REG,\
											 MPR121_AUTOCONFIG_TARGET_REG};
	uint8_t data_reg [NUMBER_REG_FOR_INIT] = {0x1F,0x13,0x09,0x7e,0x7f};
		
		switch (state_init)	{
			case MPR121_INIT_BEGIN:
				if (set_twi_bus_idle ())	{
					state_init = MPR121_SEND_ADDR;
				};
			break;
			case MPR121_SEND_ADDR:
				twi_set_addr(ADDR_MPR121,TWI_WR);
				state_init=MPR121_SEND_REG;
			break;
			case MPR121_SEND_REG:
				status_operation = twi_status_operation();
				switch (status_operation)	{
					case TWI_ARBLOST_bm:
					break;
					case TWI_RXACK_bm :
					break;
					case TWI_CLKHOLD_bm :
						twi_send_byte(MPR121_ELECTRODE_CONFIG_REG);
						state_init = MPR121_SEND_DATA;
					break;			
				case MPR121_SEND_DATA:
			
			break;
			
		};

	while (1)	{
		
	if (set_twi_bus_idle ())	{
		twi_set_addr(ADDR_MPR121,TWI_WR);
		};
		while (1)	{
			status_operation = twi_status_operation();
			switch (status_operation)	{
				case TWI_ARBLOST_bm:
				break;
				case TWI_RXACK_bm :
				break;
				case TWI_CLKHOLD_bm :
				
					for(uint8_t i=0;i<NUMBER_REG_FOR_INIT;i++)	{
						twi_send_byte(data_reg[i]);
						while (1)	{
							status_operation = twi_status_operation();
						};
		//				stop_mpr121();
					};
				break;
			};
			break;
		}
	};	
	
	pmpr121_io = &mpr121_io;
//	pmpr121_io->command = MPR121_WRITE;
	pmpr121_io->data_length = MPR121_ONE_BYTE;
	pmpr121_io->addr_reg[MPR121_ONE_BYTE - 1] = MPR121_ELECTRODE_CONFIG_REG;
	pmpr121_io->data_reg[MPR121_ONE_BYTE - 1] = MPR121_ELEPROX_0 | MPR121_ELE_0;
	
//	twi_io_write_mpr121();
	
//	twi_io (ADDR_KB, pmpr121_io);
} ;
void stop_mpr121(void)	{
	
	
};

void read_touch_status (void) {
//	twi_io();
};