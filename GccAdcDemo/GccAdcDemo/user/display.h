#ifndef _DISPLAY_H_
#define _DISPLAY_H_
	
/* ͷ�ļ� */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>		// _delay_us()	
	
/* �궨�� */
#define hc595_ser	PC0 //DSER,������������
#define hc595_cs	PC4 //RCK,�������������
#define hc595_clk	PC5 //SCLK,��������λʱ��

#define SMG10FF		( PORTD |= _BV(PD4) )
#define SMG10N		( PORTD |= _BV(PD4) )
#define SMG20FF		( PORTD |= _BV(PD4) )
#define SMG20N		( PORTD |= _BV(PD4) )

#endif
