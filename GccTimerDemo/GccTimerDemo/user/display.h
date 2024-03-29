#ifndef _DISPLAY_H_
#define _DISPLAY_H_
	
/* 头文件 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>		// _delay_us()
#include "hc595.h"	
/* 宏定义 */
#define SMG1_OFF()	( PORTD |= _BV(PD4) )
#define SMG1_ON()	( PORTD &= ~_BV(PD4))

#define SMG2_OFF()	( PORTD |= _BV(PD7) )
#define SMG2_ON()	( PORTD &= ~_BV(PD7) )  /* 因为这里的取反符号没写，老子找了一天，他么的！！！！ */

#define LED1		1
#define LED2		2
/* 函数 */
void display_init(void);
void display_time(unsigned char Location,unsigned char num);
/* other */
extern unsigned char dispcode1[];//共阳带小数点
extern unsigned char dispcode2[];//共阳无小数点

#endif
