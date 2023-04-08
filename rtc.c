/*
 * rtc.c
 *
 * Created: 03.04.2023 6:42:23
 *  Author: Пользователь
 */ 
#include <stdint-gcc.h>

#include "rtc.h"

volatile RTC_DATA_t rtc_data;
volatile RTC_DATA_t *prtc_data;