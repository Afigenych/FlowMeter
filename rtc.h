/*
 * rtc.h
 *
 * Created: 03.04.2023 6:41:56
 *  Author: Пользователь
 */ 


#ifndef RTC_H_
#define RTC_H_





#endif /* RTC_H_ */

typedef volatile struct RTC_DATA	{
	uint8_t date;
	uint8_t month;
	uint8_t years;
	uint8_t hour;
	uint8_t minute;
	} RTC_DATA_t;
extern RTC_DATA_t rtc_data;
extern RTC_DATA_t * prtc_data;