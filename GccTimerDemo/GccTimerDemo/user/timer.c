#include "timer.h"
/* 系统频率1Mhz */

/* timer0--8位 */
void timer0_init(void)
{
	cli();												//关闭全局中断
	TCCR0B |= ( _BV(CS02) | _BV(CS00) )					//1024分频 约1ms
	TCCR0A |= ( _BV(WGM02) | _BV(WGM01) | _BV(WGM00) );	//定时器普通模式
	TCNT0 = 6;											//初值6，250ms
	TIMSK0 |= _BV(T0IE0)								//开溢出中断
	cli();												//打开全局中断
}

/* timer1--16位 */
void pwm1_init(void)
{
	cli();								//关闭全局中断
	TIMSK1 |= _BV(OCIE1A)				//A中断
	OCR1A  = 125;						//比较寄存器数值
	ICR1   = 500						
	TCCR1B |= _BV(CS10);				//不分频  1M/2/500
	TCCR1A |= (1<<WGM11) | (1<<COM1A1);	//相位修正PWM
	TCCR1B |= (1<<WGM13);
	cli();								//打开全局中断
}