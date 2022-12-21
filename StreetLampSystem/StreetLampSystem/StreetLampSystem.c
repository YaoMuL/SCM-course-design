/*
*1、发光二极管一秒闪烁一次
*2、利用中断使另一个发光二极管闪烁
*3、定时器0实现秒表
*4、定时器1的pwm功能:1k，25%占空比相位修正PWM
*5、adc功能，参考电压AREF为2.5v
*/

#include "StreetLampSystem.h"

unsigned int temp=0,temp2=0;
unsigned int Cnt=0,Cnt2=0,num=0;

int main(void)
{
	/* 端口初始化 */
	gpio_init();
	/* 外部中断初始化 */
	keyint_init();
	/* 数码管初始化 */
	display_init();
	/* 595初始化 */
	hc595_init();
	/* 定时器初始化 */
	timer0_init();
	pwm_init();
	spwm_init();
	/* adc初始化 */
	adc_init();
	
	while(1)
	{
		/* led_task的一秒闪烁在timer0中断中实现 */
		/* 秒表和adc显示集成在display_task中 */
		display_task(num,temp);
	}
}
/* 中断函数在interrupt.c中 */