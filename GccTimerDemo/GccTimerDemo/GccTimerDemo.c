/*
 * GccTimerDemo.c
 *
 * Created: 2022/12/15 16:02:42
 *  Author: lxr
 */ 
#include "hc595.h"
#include "display.h"
#include "timer.h"
unsigned char shiwei;
unsigned char gewei;
unsigned int Cnt=0,Cnt2=0,num=0,num1;
int main(void)
{
	/* 595��ʼ�� */
	hc595_init();
	/* ����ܳ�ʼ�� */
	display_init();
	/* ����ʱ��1�Ƚ�������ӵ��������ó����ģʽ */
	DDRB = (1<<PB1) | (1<<PB2); //pwm OC1A ,PB2-LED
	/* ��ʱ��0��ʼ�� */
	timer0_init();
	/* ��ʱ��1��pwm����ʼ�� */
	pwm1_init();
	
	while(1)
	{
		shiwei = num/10;
		gewei  = num%10;
		display_time(LED1,shiwei);
		display_time(LED2,gewei);
	}
}

/*******TIMER0�жϷ����������ܣ�***********/
ISR(TIMER0_OVF_vect)
{
	/* ÿ250ms�����ж� */
	TCNT0 = 6; //��װ�ؼ���ֵ
	Cnt++;
	if(Cnt > 3)//num ÿ�� 250ms*4=1s ����һ��
	{
		num++;
		Cnt = 0;
	}
	if(num > 60 )
	{
		num = 0;
	}
}

/*******TIMER1�жϷ������PWM���ܣ�***********/
ISR(TIMER1_COMPA_vect)
{
	OCR1A = 125; //��װ�ؼ���ֵ
	ICR1  = 500;
	Cnt2++��
	if(Cnt2 > 1000)
	{
		Cnt2 = 0;
	}
	PORTB ^= (1<<PB2);
}
