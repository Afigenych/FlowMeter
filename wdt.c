/*
 * wdt.c
 *
 * Created: 27.02.2023 9:16:01
 *  Author: user
 */ 

#include "ioavr64dd32.h"
#include "rtc.h"
#include "main.h"
#include "wdt.h"

void init_wdt (void)	{
	FUSE_WDTCFG = PERIOD_8KCLK_gc;
//	WDT_CTRLA = PERIOD_8KCLK_gc;
};

void init_BOD(void)	{
	FUSE.BODCFG = (BOD_LVL_BODLEVEL2_gc<<5) | BOD_SAMPFREQ_32HZ_gc | BOD_ACTIVE_SAMPLED_gc | BOD_SLEEP_DIS_gc;
	//	BOD.CTRLA= BOD_SAMPFREQ_32HZ_gc | BOD_ACTIVE_SAMPLED_gc | BOD_SLEEP_DIS_gc; //????? BOD_LVL_BODLEVEL2_gc must be shift left to 5 bit position ?????
	cnt_fm.bod_cnt = 0;
	return;
};


void init_pit(void)		{
	
	RTC_PITCTRLA = RTC_PERIOD_CYC1024_gc | RTC_PITEN_bm;
	RTC_PITINTCTRL |= RTC_PITEN_bm; 
	asm("WDR");
};

