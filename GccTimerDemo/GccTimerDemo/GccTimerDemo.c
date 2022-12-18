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
	/* 595初始化 */
	hc595_init();
	/* 数码管初始化 */
	display_init();
	/* 将定时器1比较输出连接的引脚配置成输出模式 */
	DDRB = (1<<PB1) | (1<<PB2); //pwm OC1A ,PB2-LED
	/* 定时器0初始化 */
	timer0_init();
	/* 定时器1（pwm）初始化 */
	pwm1_init();
	
	while(1)
	{
		shiwei = num/10;
		gewei  = num%10;
		display_time(LED1,shiwei);
		display_time(LED2,gewei);
	}
}

/*******TIMER0中断服务程序（秒表功能）***********/
ISR(TIMER0_OVF_vect)
{
	/* 每250ms进入中断 */
	TCNT0 = 6; //重装载计数值
	Cnt++;
	if(Cnt > 3)//num 每隔 250ms*4=1s 更新一次
	{
		num++;
		Cnt = 0;
	}
	if(num > 60 )
	{
		num = 0;
	}
}

/*******TIMER1中断服务程序（PWM功能）***********/
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
