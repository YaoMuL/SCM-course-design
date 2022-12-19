#ifndef _HC595_H_
#define _HC595_H_

/* 头文件 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>		// _delay_us()
/* 宏定义 */
//#define hc595_ser	PC0 //DS/SER,串行输入数据
//#define hc595_rck	PC4 //RCK,上升沿锁存输出
//#define hc595_clk	PC5 //SCLK,上升沿移位时钟

#define hc595ser_set()	( PORTC |= _BV(PC0) ) //ser/ds,串行输入数据
#define hc595ser_res()	( PORTC &= ~_BV(PC0)) 

#define hc595rck_set()	( PORTC |= _BV(PC4) ) //rck,串行输入数据
#define hc595rck_res()	( PORTC &= ~_BV(PC4)) 

#define hc595clk_set()	( PORTC |= _BV(PC5) ) //clk,串行输入数据
#define hc595clk_res()	( PORTC &= ~_BV(PC5))
/* 函数 */
void hc595_init(void);
void hc595_en(void);
void hc595outbyte(unsigned char disdata);
void hc595out(unsigned char data);

#endif