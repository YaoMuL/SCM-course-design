#ifndef _ADC_H_
#define _ADC_H_

/* ͷ�ļ� */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>		// _delay_us()
#include "display.h"
#include "hc595.h"
/* �궨�� */

/* ���� */
void adc_init(void);

#endif