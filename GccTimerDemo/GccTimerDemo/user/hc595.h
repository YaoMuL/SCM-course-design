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

#define hc595_ser	PORTC0 //ser/ds,串行输入数据
#define hc595_rck	PORTC4 //rck,串行输入数据
#define hc595_clk	PORTC5 //clk,串行输入数据
/* 函数 */
void hc595_init(void);
void hc595_en(void);
void hc595outbyte(unsigned char disdata);
void hc595out(unsigned char data);

#endif