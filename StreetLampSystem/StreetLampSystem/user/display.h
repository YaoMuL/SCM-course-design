#ifndef _DISPLAY_H_
#define _DISPLAY_H_
	
/* ͷ�ļ� */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>		// _delay_us()
#include "hc595.h"	
/* �궨�� */
//�붨ʱ����ʾʱ�书�ܵ�λѡ�߼��෴
#define time_shi_on()	( PORTD &= ~_BV(PD4) )
#define time_shi_off()	( PORTD |= _BV(PD4)  )

#define time_ge_on()	( PORTD &= ~_BV(PD7) )
#define time_ge_off()	( PORTD |= _BV(PD7)  )

#define adc_bai_on()	( PORTD |= _BV(PD0)  )
#define adc_bai_off()	( PORTD &= ~_BV(PD0) )

#define adc_shi_on()	( PORTD |= _BV(PD1)  )
#define adc_shi_off()	( PORTD &= ~_BV(PD1) )

#define adc_ge_on()		( PORTD |= _BV(PD6)  )
#define adc_ge_off()	( PORTD &= ~_BV(PD6) )

#define bai		1
#define shi		2
#define ge		3

/* ���� */
void display_init(void);
void display_task(unsigned char time , unsigned int adc);
/* other */
extern unsigned char dispcode1[];//������С����
extern unsigned char dispcode2[];//������С����

#endif
