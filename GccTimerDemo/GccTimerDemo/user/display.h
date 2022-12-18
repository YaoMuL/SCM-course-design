#ifndef _DISPLAY_H_
#define _DISPLAY_H_
	
/* ͷ�ļ� */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>		// _delay_us()
#include "hc595.h"	
/* �궨�� */
#define SMG1_OFF()	( PORTD |= _BV(PD4) )
#define SMG1_ON()	( PORTD &= ~_BV(PD4))
#define SMG2_OFF()	( PORTD |= _BV(PD7) )
#define SMG2_ON()	( PORTD &= _BV(PD7) )
/* ���� */
void display_init(void);
void display_time(unsigned char Location,unsigned char num);
/* other */
extern unsigned char dispcode[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};//���������

#endif
