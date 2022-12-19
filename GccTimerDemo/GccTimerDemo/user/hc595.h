#ifndef _HC595_H_
#define _HC595_H_

/* ͷ�ļ� */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>		// _delay_us()
/* �궨�� */
//#define hc595_ser	PC0 //DS/SER,������������
//#define hc595_rck	PC4 //RCK,�������������
//#define hc595_clk	PC5 //SCLK,��������λʱ��

#define hc595ser_set()	( PORTC |= _BV(PC0) ) //ser/ds,������������
#define hc595ser_res()	( PORTC &= ~_BV(PC0)) 

#define hc595rck_set()	( PORTC |= _BV(PC4) ) //rck,������������
#define hc595rck_res()	( PORTC &= ~_BV(PC4)) 

#define hc595clk_set()	( PORTC |= _BV(PC5) ) //clk,������������
#define hc595clk_res()	( PORTC &= ~_BV(PC5))
/* ���� */
void hc595_init(void);
void hc595_en(void);
void hc595outbyte(unsigned char disdata);
void hc595out(unsigned char data);

#endif