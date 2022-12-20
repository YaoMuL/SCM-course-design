#include "timer.h"
/* 系统频率1Mhz */

/* timer0--8位 */
void timer0_init(void)
{
	cli();												//关闭全局中断
	TIMSK0 |= _BV(TOIE0);								//开溢出中断
	TCCR0B |= ( _BV(CS02) | _BV(CS00) );				//1024分频 约1ms
//	TCCR0A |= ( _BV(WGM02) | _BV(WGM01) | _BV(WGM00) );	//定时器普通模式
	TCNT0 = 6;											//初值6，250ms
	sei();												//打开全局中断
}

/* timer1--16位 */
void pwm1_init(void)
{
	cli();								//关闭全局中断
	TCCR1B |= _BV(CS10);				//不分频  1M/2/500
	TCCR1A |= (1<<WGM11) | (1<<COM1A1);	//相位修正PWM
	TCCR1B |= (1<<WGM13);
	TIMSK1 |= _BV(OCIE1A);				//A中断
	/* 0-500升序时达到125清零，在500-0降序时达到125置位 */
	OCR1A  = 125;						//比较寄存器数值
	ICR1   = 500;						
	sei();								//打开全局中断
}
