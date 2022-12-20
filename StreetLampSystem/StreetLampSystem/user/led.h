#ifndef _LED_H_
#define _LED_H_

/* 头文件 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>	

/* 宏定义 */
#define	LED2	PB7
#define	LED3	PD5
#define	LED4	PB6

/* 函数定义 */
void led_configuration(void);
void keyint_init(void);
void led4_toggle(void);
void led2_toggle(void);

#endif

