//main.h

//#include <avr/alltypes.h>
//#include <avr/all-types>

#include "twi_io.h"

//#define BAUD_RATE_TWI 30

	

typedef volatile struct CNT_FM {
	uint8_t wdg_cnt;
	uint8_t bod_cnt;
	uint8_t isr_fm;
	
}CNT_FM_t;
extern CNT_FM_t cnt_fm;

int main (void);