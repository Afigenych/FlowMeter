//main.h

//#include <avr/alltypes.h>
//#include <avr/all-types>

//#include "twi_io.h"

#define NUMBER_ULTRA_SONIC	4

#define INT_US1		0x01
#define INT_US2		0x02
#define INT_US3		0x04
#define INT_US4		0x08
#define INT_KB		0x10
#define INT_CD		0x20
#define INT_FAULT	0x40

// state of fm
#define FM_INIT		0x00
#define FM_NORMAL	0x01
#define FM_DEBUG	0x02
#define FM_ERROR	0x03
	

typedef volatile struct CNT_FM {
	uint8_t state_fm;
	uint8_t wdg_cnt;
	uint8_t bod_cnt;
	uint8_t fm_ir;
	
}CNT_FM_t;
extern CNT_FM_t cnt_fm;

typedef volatile struct FM_CTRL {
	uint8_t io_flag;
	uint8_t io_processing;
	uint8_t ir;
	uint8_t kb;
	RTC_DATA_t * prtc_data;
	uint8_t lcd;
	uint8_t cs;
	
} FM_CTRL_t;
extern FM_CTRL_t fm_ctrl;
extern FM_CTRL_t * pfm_ctrl;

#define FM_RD_IR_bm		0x01<<7 
#define FM_RD_KB_bm		0x01<<6
#define FM_WR_KB_bm		0x01<<5
#define FM_RD_RTC_bm	0x01<<4
#define FM_WR_RTC_bm	0x01<<3
#define FM_WR_LCD_bm	0x01<<2
#define FM_WR_CS_bm		0x01<<1

#define FM_INT_US0		0x01<<0
#define FM_INT_US1		0x01<<1
#define FM_INT_US2		0x01<<2
#define FM_INT_US3		0x01<<3
#define FM_INT_KB		0x01<<4
#define FM_INT_CD		0x01<<5
#define FM_INT_FAULT	0x01<<6

volatile extern int8_t flag_int;

/*
typedef volatile struct ULTRA_SONIC {
	
}ULTRA_SONIC_t;
 extern ULTRA_SONIC_t ultra_sonic;

typedef volatile struct FLOW_METER {
	ULTRA_SONIC_t ultra_sonic[NUMBER_ULTRA_SONIC];
	
}FLOW_METER_t;
 extern FLOW_METER_t flow_meter;

typedef volatile struct FM_INT_FLAG {
	uint8_t port_int_flag;
	uint8_t fm_all_int_flag;
	}FM_INT_FLAG_t, * pFM_INT_FLAG_t;
extern FM_INT_FLAG_t * fm_int_flag_struct;
*/

int main (void);
void processingIR (void);