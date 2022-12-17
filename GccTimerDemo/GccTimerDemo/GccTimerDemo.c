/*
 * GccTimerDemo.c
 *
 * Created: 2022/12/15 16:02:42
 *  Author: lxr
 */ 
#include "display.h"
#include "timer.h"

unsigned char dispcode[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};//共阳数码管
unsigned char shiwei;
unsigned char gewei;
unsigned int Cnt=0,Cnt2=0,num=0,num1;

int main(void)
{
	DDRD = (1<<PD4) | (1<<PD7); //位选
	DDRC = (1<<PC0) | (1<<PC4) | (1<<PC5); //缓冲器控制
	DDRB = (1<<PB1) | (1<<PB2); //位选
	/* 定时器0初始化 */
	timer0_init();
	/* 定时器1（pwm）初始化 */
	pwm1_init();
	
	while(1)
	{
		shiwei = num/10;
		gewei  = num%10;
		
		hc595out(dispcode[shiwei]);
		
	}
}


/*******TIMER0中断服务程序***********/
ISR(TIMER0_OVF_vect)
{
	TCNT0 = 6; //重装载计数值
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

/*******TIMER1中断服务程序***********/
ISR(TIMER1_COMPA_vect)
{
	OCR1A = 125; //重装载计数值
	ICR1  = 500;
	Cnt2++；
	if(Cnt2 > 1000)
	{
		Cnt2 = 0;
	}
	PORTB ^= (1<<PB2);
}
