﻿/*
 * mpr121.h
 *
 * Created: 27.03.2023 10:10:08
 *  Author: Пользователь
 */ 


#include <stdint-gcc.h>


#ifndef MPR121_H_
#define MPR121_H_





#endif /* MPR121_H_ */

#define MPR121_CMD_STOP					0x01u
#define MPR121_CMD_RUN					0x02u
#define MPR121_CMD_AUTOCFG1				0x03u
#define MPR121_CMD_AUTOCFG2				0x04u
#define MPR121_CMD_SOFT_RST				0x05u
#define MPR121_CMD_ELECTRODE_CFG		0x06u
#define MPR121_CMD_READ_TOUCH_STATUS	0x07u

#define MPR121_ELEPROX_0  0x00	//b00<<4
#define MPR121_ELEPROX_4  0x02	//b10<<4

#define MPR121_ELE_0	 0x00
#define MPR121_ELE_4	 0x04

#define MPR121_STOP = ELEPROX0

//data length
#define MPR121_ONE_BYTE	1
#define MPR121_TWO_BYTE	2

#define MPR121_WRITE	0x00
#define MPR121_READ		0x01


/*! \brief MPR121 register map
 */
enum mpr121_register {
    MPR121_TOUCH_STATUS_REG = 0x00u,
    MPR121_OUT_OF_RANGE_STATUS_0_REG = 0x02u,
    MPR121_OUT_OF_RANGE_STATUS_1_REG = 0x03u,
    MPR121_ELECTRODE_FILTERED_DATA_REG = 0x04u,
    MPR121_BASELINE_VALUE_REG = 0x1Eu,
    // Registers 0x2B ~ 0x7F are control and configuration registers
    MPR121_MAX_HALF_DELTA_RISING_REG = 0x2Bu,
    MPR121_NOISE_HALF_DELTA_RISING_REG = 0x2Cu,
    MPR121_NOISE_COUNT_LIMIT_RISING_REG = 0x2Du,
    MPR121_FILTER_DELAY_COUNT_RISING_REG = 0x2Eu,
    MPR121_MAX_HALF_DELTA_FALLING_REG = 0x2Fu,
    MPR121_NOISE_HALF_DELTA_FALLING_REG = 0x30u,
    MPR121_NOISE_COUNT_LIMIT_FALLING_REG = 0x31u,
    MPR121_FILTER_DELAY_COUNT_FALLING_REG = 0x32u,
    MPR121_NOISE_HALF_DELTA_TOUCHED_REG = 0x33u,
    MPR121_NOISE_COUNT_LIMIT_TOUCHED_REG = 0x34u,
    MPR121_FILTER_DELAY_COUNT_TOUCHED_REG = 0x35u,
    // (ELEPROX 0x36 .. 0x40)
    MPR121_TOUCH_THRESHOLD_REG = 0x41u,
    MPR121_RELEASE_THRESHOLD_REG = 0x42u,
    // (ELEPROX 0x59 .. 0x5A)
    MPR121_DEBOUNCE_REG = 0x5Bu,
    MPR121_AFE_CONFIG_REG = 0x5Cu,
    MPR121_FILTER_CONFIG_REG = 0x5Du,
    MPR121_ELECTRODE_CONFIG_REG = 0x5Eu,
    MPR121_ELECTRODE_CURRENT_REG = 0x5Fu,
    MPR121_ELECTRODE_CHARGE_TIME_REG = 0x6Cu,
    MPR121_GPIO_CTRL_0_REG = 0x73u,
    MPR121_GPIO_CTRL_1_REG = 0x74u,
    MPR121_GPIO_DATA_REG = 0x75u,
    MPR121_GPIO_DIRECTION_REG = 0x76u,
    MPR121_GPIO_ENABLE_REG = 0x77u,
    MPR121_GPIO_DATA_SET_REG = 0x78u,
    MPR121_GPIO_DATA_CLEAR_REG = 0x79u,
    MPR121_GPIO_DATA_TOGGLE_REG = 0x7Au,
    MPR121_AUTOCONFIG_CONTROL_0_REG = 0x7Bu,
    MPR121_AUTOCONFIG_CONTROL_1_REG = 0x7Cu,
    MPR121_AUTOCONFIG_USL_REG = 0x7Du,
    MPR121_AUTOCONFIG_LSL_REG = 0x7Eu,
    MPR121_AUTOCONFIG_TARGET_REG = 0x7Fu,
    MPR121_SOFT_RESET_REG = 0x80u
};

#define MPR121_LENGTH_DATA_BUF			0x05
#define NUMBER_REG_FOR_INIT				0x05
#define MPR121_INIT_BEGIN		0x00
#define MPR121_SEND_ADDR		0x01
#define MPR121_SEND_REG			0x02
#define MPR121_SEND_DATA		0x03

typedef struct MPR121_IO	{
//	uint8_t command;
	uint8_t addr_reg [MPR121_LENGTH_DATA_BUF];
	uint8_t data_reg [MPR121_LENGTH_DATA_BUF];
	uint8_t data_length;
	} MPR121_IO_t;
	
	extern MPR121_IO_t mpr121_io;
	extern MPR121_IO_t * pmpr121_io;

void init_mpr121 (void) ;
void read_touch_status (void);
void stop_mpr121 (void);