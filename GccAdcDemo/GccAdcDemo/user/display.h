#ifndef _DISPLAY_H_
#define _DISPLAY_H_
	
/* 头文件 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>		// _delay_us()	
	
/* 宏定义 */
#define hc595_ser	PC0 //DSER,串行输入数据
#define hc595_cs	PC4 //RCK,上升沿锁存输出
#define hc595_clk	PC5 //SCLK,上升沿移位时钟

#define SMG10FF		( PORTD |= _BV(PD4) )
#define SMG10N		( PORTD |= _BV(PD4) )
#define SMG20FF		( PORTD |= _BV(PD4) )
#define SMG20N		( PORTD |= _BV(PD4) )

#endif
