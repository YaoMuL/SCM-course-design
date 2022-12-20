#ifndef _ADC_H_
#define _ADC_H_

/* 头文件 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>		// _delay_us()
#include "StreetLampSystem.h"
/* 宏定义 */

/* 函数 */
void adc_init(void);
#endif