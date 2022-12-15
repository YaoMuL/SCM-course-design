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
*1、发光二极管一秒闪烁一次
*2、利用中断使另一个发光二极管闪烁
*/

/* _BV()是把1左移N位的函数 */

int main(void)
{
	DDRB=(1<<PB6)|(1<<PB7);				// 端口B方向,PB6和PB7为输出
	//DDRC=(1<<PC0)|(1<<PC4)|(1<<PC5);	// 输出 PC4-LED
	DDRD=(PD2>>1)|(1<<PD5)|(1<<PD6);	// Key,PD2输入,PD5输出
	
	
	//DDRB = 0xFE;
	//PORTD=(1<<PD2);					// 上拉
	PORTD=(1<<PD5)|(1<<PD6);		// 输出1
	
	cli();			//关闭全局中断
	//--------------------------外部中断0 INT0
	//EICRA&=~_BV(ISC00);	// 0 0, 低电平产生中断
	//EICRA&=~_BV(ISC01);
	//EIMSK|=_BV(INT0);		// 外部中断0使能
	//EIFR|=_BV(INTF0);		// 清中断标志,写1
	
	// INT0下降沿
	EICRA&=~_BV(ISC00);		// 0 , 下降沿产生中断
	EICRA|=_BV(ISC01);		// 1
	EIMSK |=_BV(INT0);		// 使能
	EIFR|=_BV(INTF0);		// 标志位
	
	// 电平变化中断，实验ok，sim不行
	//PCICR|=_BV(PCIE2);		// 电平变化中断使能
	//PCIFR|=_BV(PCIF2);		// 标志位清除
	//PCMSK2|=_BV(PCINT18);	//使能
	
	sei();			//开启全局中断
	
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


/*******外部中断0中断服务程序***********/
ISR(INT0_vect)
//ISR(PCINT2_vect)
{
	//num++;
	//if(num>600) num=0;
	
	//PORTC^=_BV(PC4); 取反
	//PORTD^=(1<<LED);
	PORTD^=_BV(LED);
	//PORTD&=~_BV(PD5);
	
	//PCIFR|=_BV(PCIF2);		// 标志位清除
	//EIFR |=1;
	//PCIFR|=_BV(PCIF0);	// 置位，清中断标志(软件自动清)
}