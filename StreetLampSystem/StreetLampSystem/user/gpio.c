#include "gpio.h"
/* 端口初始化 */
void gpio_init(void)
{
	/* B端口 */
	DDRB = (1<<PB1) | (1<<PB2) | (1<<PB7); //PB1和PB2为两路PWM输出，PB7为1s闪烁LED输出口	
	/* C端口 */
	DDRC = (1<<PC0) | (1<<PC4) | (1<<PC5);//输出到595的 DS RCK CLK 的输出口
	/* D端口 */
	DDRD = 0;//清零
	DDRD &= ~_BV(PD2);							// 按键输入
	DDRD |= (1<<PD5);							// 通过中断实现LED闪烁的输出
	DDRD |= (1<<PD4)|(1<<PD7);					// time显示数码管端口
	DDRD |= (1<<PD0) | (1<<PD1) | (1<<PD6);		//adc显示数码管端口
}