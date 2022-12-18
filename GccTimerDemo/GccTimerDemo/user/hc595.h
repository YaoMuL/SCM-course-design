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

#define hc595_ser	PORTC0 //ser/ds,������������
#define hc595_rck	PORTC4 //rck,������������
#define hc595_clk	PORTC5 //clk,������������
/* ���� */
void hc595_init(void);
void hc595_en(void);
void hc595outbyte(unsigned char disdata);
void hc595out(unsigned char data);

#endif