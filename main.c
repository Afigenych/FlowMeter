/*
 * GccApplication1.c
 *
 * Created: 15.02.2023 11:24:27
 * Author : user
 */ 
#include <stdint-gcc.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "main.h"
#include "twi_io.h"
#include "wdt.h"
#include "int.h"

volatile CNT_FM_t cnt_fm;

	
	
int main(void)
{
	init_wdt();
	init_pit();
	init_BOD();
	// select pin position
	
	
	

	

	

 
	
    while (1) 
    {
    }
};

