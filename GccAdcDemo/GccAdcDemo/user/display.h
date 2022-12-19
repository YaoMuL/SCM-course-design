#ifndef _DISPLAY_H_
#define _DISPLAY_H_
	
/* ͷ�ļ� */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>		// _delay_us()
#include "hc595.h"	
/* �궨�� */
//�붨ʱ����ʾʱ�书�ܵ�λѡ�߼��෴
#define SMG2_ON()	( PORTD |= _BV(PD7) )
#define SMG2_OFF()	( PORTD &= _BV(PD7) )

#define SMG3_ON()	( PORTD |= _BV(PD6) )
#define SMG3_OFF()	( PORTD &= _BV(PD6) )

#define SMG4_ON()	( PORTD |= _BV(PD5) )
#define SMG4_OFF()	( PORTD &= _BV(PD5) )

#define LED1		1
#define LED2		2
#define LED3		3
#define LED4		4
/* ���� */
void display_init(void);
void display(unsigned char Location,unsigned char num);
void adc_display(unsigned int smg);
/* other */
extern unsigned char dispcode1[];//���������
extern unsigned char dispcode2[];//���������

#endif
