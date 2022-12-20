#ifndef _TIMER_H_
#define _TIMER_H_

/* 头文件 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>		// _delay_us()
#include "gpio.h"
#include "led.h"
#include "hc595.h"
#include "display.h"
#include "adc.h"
/* 宏定义 */
void timer0_init(void);
void pwm1_init(void);
#endif
