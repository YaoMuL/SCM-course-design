#include "timer.h"
/* ϵͳƵ��1Mhz */

/* timer0--8λ */
void timer0_init(void)
{
	cli();												//�ر�ȫ���ж�
	TCCR0B |= ( _BV(CS02) | _BV(CS00) )					//1024��Ƶ Լ1ms
	TCCR0A |= ( _BV(WGM02) | _BV(WGM01) | _BV(WGM00) );	//��ʱ����ͨģʽ
	TCNT0 = 6;											//��ֵ6��250ms
	TIMSK0 |= _BV(T0IE0)								//������ж�
	cli();												//��ȫ���ж�
}

/* timer1--16λ */
void pwm1_init(void)
{
	cli();								//�ر�ȫ���ж�
	TIMSK1 |= _BV(OCIE1A)				//A�ж�
	OCR1A  = 125;						//�ȽϼĴ�����ֵ
	ICR1   = 500						
	TCCR1B |= _BV(CS10);				//����Ƶ  1M/2/500
	TCCR1A |= (1<<WGM11) | (1<<COM1A1);	//��λ����PWM
	TCCR1B |= (1<<WGM13);
	cli();								//��ȫ���ж�
}