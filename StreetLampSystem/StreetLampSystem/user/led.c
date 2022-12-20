#include "led.h"

void led_configuration(void)
{
		DDRB  = (1<<PB7);			  // �˿�B����,PB7Ϊ���
		DDRD  = (PD2>>1)|(1<<PD5);  // Key,PD2����,PD5���
}

void keyint_init(void)
{
		cli();			//�ر�ȫ���ж�

		// INT0�½���
		EICRA &= ~_BV(ISC00);	// 0 , �½��ز����ж�
		EICRA |= _BV(ISC01);	// 1
		EIMSK |= _BV(INT0);		// ʹ��
		EIFR  |= _BV(INTF0);	// ��־λ
		
		sei();					//����ȫ���ж�
}
 
void led4_toggle(void)
{
	PORTB ^= _BV(LED4);
}

void led2_toggle(void)
{
	PORTB ^= _BV(LED2);
}

