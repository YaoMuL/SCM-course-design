#ifndef _TIMER_H_
#define _TIMER_H_

/* ͷ�ļ� */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>		// _delay_us()
/* �궨�� */
void timer0_init(void);
void pwm1_init(void);
#endif
