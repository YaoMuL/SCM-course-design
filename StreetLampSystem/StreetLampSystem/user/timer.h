#ifndef _TIMER_H_
#define _TIMER_H_

/* ͷ�ļ� */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>		// _delay_us()
#include "gpio.h"
#include "led.h"
#include "hc595.h"
#include "display.h"
#include "adc.h"
/* �궨�� */
void timer0_init(void);
void pwm1_init(void);
#endif
