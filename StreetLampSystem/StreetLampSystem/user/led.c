#include "led.h"

void led_configuration(void)
{
		DDRB  = (1<<PB7);			  // 端口B方向,PB7为输出
		DDRD  = (PD2>>1)|(1<<PD5);  // Key,PD2输入,PD5输出
}

void keyint_init(void)
{
		cli();			//关闭全局中断

		// INT0下降沿
		EICRA &= ~_BV(ISC00);	// 0 , 下降沿产生中断
		EICRA |= _BV(ISC01);	// 1
		EIMSK |= _BV(INT0);		// 使能
		EIFR  |= _BV(INTF0);	// 标志位
		
		sei();					//开启全局中断
}
 
void led4_toggle(void)
{
	PORTB ^= _BV(LED4);
}

void led2_toggle(void)
{
	PORTB ^= _BV(LED2);
}

