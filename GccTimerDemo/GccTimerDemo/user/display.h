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
#define SMG2_ON()	( PORTD &= ~_BV(PD7) )  /* ��Ϊ�����ȡ������ûд����������һ�죬��ô�ģ������� */

#define LED1		1
#define LED2		2
/* ���� */
void display_init(void);
void display_time(unsigned char Location,unsigned char num);
/* other */
extern unsigned char dispcode1[];//������С����
extern unsigned char dispcode2[];//������С����

#endif
