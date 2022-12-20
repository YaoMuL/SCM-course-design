#include "timer.h"
/* ϵͳƵ��1Mhz */

/* timer0--8λ */
void timer0_init(void)
{
	cli();												//�ر�ȫ���ж�
	TIMSK0 |= _BV(TOIE0);								//������ж�
	TCCR0B |= ( _BV(CS02) | _BV(CS00) );				//1024��Ƶ Լ1ms
//	TCCR0A |= ( _BV(WGM02) | _BV(WGM01) | _BV(WGM00) );	//��ʱ����ͨģʽ
	TCNT0 = 6;											//��ֵ6��250ms
	sei();												//��ȫ���ж�
}

/* timer1--16λ */
void pwm1_init(void)
{
	cli();								//�ر�ȫ���ж�
	TCCR1B |= _BV(CS10);				//����Ƶ  1M/2/500
	TCCR1A |= (1<<WGM11) | (1<<COM1A1);	//��λ����PWM
	TCCR1B |= (1<<WGM13);
	TIMSK1 |= _BV(OCIE1A);				//A�ж�
	/* 0-500����ʱ�ﵽ125���㣬��500-0����ʱ�ﵽ125��λ */
	OCR1A  = 125;						//�ȽϼĴ�����ֵ
	ICR1   = 500;						
	sei();								//��ȫ���ж�
}
