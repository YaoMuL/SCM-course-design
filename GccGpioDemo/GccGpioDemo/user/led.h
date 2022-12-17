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
//D4
#define LED4_ON()	( PORTB6 = 0 )
#define LED4_OFF()	( PORTB6 = 1 )
//D2
#define LED2_ON()	( PORTB7 = 0 )
#define LED2_OFF()	( PORTB7 = 1 )

/* 函数定义 */
void led_configuration(void);
void keyint_init(void);
void led4_toggle(void);
void led2_toggle(void);

#endif

