#include "timer.h"

/* timer0 */
void timer0_init(void)
{
	cli();								//�ر�ȫ���ж�
	TIMSK0 |= _BV(T0IE0)				//������ж�
	TCNT0 = 6;							//��ֵ6��250ms
	TCCR0B |= _BV(CS02) | _BV(CS00)		//1024��Ƶ Լ1ms
	cli();								//��ȫ���ж�
}

/* timer1 */
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