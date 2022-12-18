#ifndef _TIMER_H_
#define _TIMER_H_

/* 头文件 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>		// _delay_us()
/* 宏定义 */
void timer0_init(void);
void pwm1_init(void);
#endif
