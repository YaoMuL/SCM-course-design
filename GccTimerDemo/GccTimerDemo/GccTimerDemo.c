/*
 * GccTimerDemo.c
 *
 * Created: 2022/12/15 15:45:18
 *  Author: lxr
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>		// _delay_us()

unsigned int num=0;
#define		LED		PD5

/*
*1�����������һ����˸һ��
*2�������ж�ʹ��һ�������������˸
*/

/* _BV()�ǰ�1����Nλ�ĺ��� */

int main(void)
{
	DDRB=(1<<PB6)|(1<<PB7);				// �˿�B����,PB6��PB7Ϊ���
	//DDRC=(1<<PC0)|(1<<PC4)|(1<<PC5);	// ��� PC4-LED
	DDRD=(PD2>>1)|(1<<PD5)|(1<<PD6);	// Key,PD2����,PD5���
	
	
	//DDRB = 0xFE;
	//PORTD=(1<<PD2);					// ����
	PORTD=(1<<PD5)|(1<<PD6);		// ���1
	
	cli();			//�ر�ȫ���ж�
	//--------------------------�ⲿ�ж�0 INT0
	//EICRA&=~_BV(ISC00);	// 0 0, �͵�ƽ�����ж�
	//EICRA&=~_BV(ISC01);
	//EIMSK|=_BV(INT0);		// �ⲿ�ж�0ʹ��
	//EIFR|=_BV(INTF0);		// ���жϱ�־,д1
	
	// INT0�½���
	EICRA&=~_BV(ISC00);		// 0 , �½��ز����ж�
	EICRA|=_BV(ISC01);		// 1
	EIMSK |=_BV(INT0);		// ʹ��
	EIFR|=_BV(INTF0);		// ��־λ
	
	// ��ƽ�仯�жϣ�ʵ��ok��sim����
	//PCICR|=_BV(PCIE2);		// ��ƽ�仯�ж�ʹ��
	//PCIFR|=_BV(PCIF2);		// ��־λ���
	//PCMSK2|=_BV(PCINT18);	//ʹ��
	
	sei();			//����ȫ���ж�
	
	while(1)
	{
		//TODO:: Please write your application code
		PORTB|=_BV(PB6);		//	1s
		PORTB&=~_BV(PB7);
		_delay_us(1000000);		//
		PORTB&=~_BV(PB6);		//
		PORTB|=_BV(PB7);
		_delay_us(1000000);
	}
}


/*******�ⲿ�ж�0�жϷ������***********/
ISR(INT0_vect)
//ISR(PCINT2_vect)
{
	//num++;
	//if(num>600) num=0;
	
	//PORTC^=_BV(PC4); ȡ��
	//PORTD^=(1<<LED);
	PORTD^=_BV(LED);
	//PORTD&=~_BV(PD5);
	
	//PCIFR|=_BV(PCIF2);		// ��־λ���
	//EIFR |=1;
	//PCIFR|=_BV(PCIF0);	// ��λ�����жϱ�־(����Զ���)
}