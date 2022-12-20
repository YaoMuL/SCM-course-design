/* 中断服务程序 */
#include "interrupt.h"
/*******外部中断0中断服务程序***********/
ISR(INT0_vect)
{
	PORTD^=_BV(LED3);
}

/*******TIMER0中断服务程序（秒表功能）***********/
ISR(TIMER0_OVF_vect)
{
	/* 每250ms进入中断 */
	TCNT0 = 6; //重装载计数值
	Cnt++;
	if(Cnt > 3)//num 每隔 250ms*4=1s 更新一次
	{
		led2_toggle();
		num++;
		Cnt = 0;
	}
	if(num > 60 )
	{
		num = 0;
	}
}

/*******TIMER1中断服务程序（PWM功能）***********/
/* 1k，25%占空比相位修正PWM */
ISR(TIMER1_COMPA_vect)
{
	OCR1A = 125; //重装载计数值
	ICR1  = 500;
	Cnt2++;
	if(Cnt2 > 1000)
	{
		Cnt2 = 0;
	}
	PORTB ^= (1<<PB1);//PWM波形输出到端口
}

/*******ADC中断服务程序***********/
ISR(ADC_vect)
{
	//delay_1ms(1);
	//temp=ADCH;//读取转化的数据
	temp = ADCL>>6;
	temp2 = ADCH;
	temp2 <<= 2;
	temp += temp2;   //10bit
	ADCSRA|=0X40;//重启ADC，设置ADCSRA的ADATA和连续转换模式时不用
}
