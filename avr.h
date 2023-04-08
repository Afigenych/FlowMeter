/*
 * avr.h
 *
 * Created: 03.03.2023 13:17:08
 *  Author: Пользователь
 */ 


#ifndef AVR_H_
#define AVR_H_





#endif /* AVR_H_ */

//define bit mask for port D
#define INP_INT_bm 	1<<1
#define OUT_LDAC_bm	1<<2
#define EN_HART_bm  1<<3

//define bit mask for port F
#define INP_MFP_bm		1<<1
#define OUT_SS1_bm		1<<2
#define OUT_SS2_bm		1<<3
#define OUT_SS3_bm		1<<4
#define OUT_SS4_bm		1<<5


void init_avr(void);