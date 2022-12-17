/*
 * GccTimerDemo.c
 *
 * Created: 2022/12/15 16:02:42
 *  Author: lxr
 */ 
#include "display.h"
#include "timer.h"

unsigned char dispcode[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};//���������
unsigned char shiwei;
unsigned char gewei;
unsigned int Cnt=0,Cnt2=0,num=0,num1;

int main(void)
{
	DDRD = (1<<PD4) | (1<<PD7); //λѡ
	DDRC = (1<<PC0) | (1<<PC4) | (1<<PC5); //����������
	DDRB = (1<<PB1) | (1<<PB2); //λѡ
	/* ��ʱ��0��ʼ�� */
	timer0_init();
	/* ��ʱ��1��pwm����ʼ�� */
	pwm1_init();
	
	while(1)
	{
		shiwei = num/10;
		gewei  = num%10;
		
		hc595out(dispcode[shiwei]);
		
	}
}


/*******TIMER0�жϷ������***********/
ISR(TIMER0_OVF_vect)
{
	TCNT0 = 6; //��װ�ؼ���ֵ
	Cnt++;
	if(Cnt > 3)
	{
		num++;
		Cnt = 0;
	}
	if(num > 60 )
	{
		num = 0;
	}
}

/*******TIMER1�жϷ������***********/
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
