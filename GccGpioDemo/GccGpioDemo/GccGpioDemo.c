/*
*1、发光二极管一秒闪烁一次
*2、利用中断使另一个发光二极管闪烁
*/

#include "led.h"

int main(void)
{	
	/* led及按键初始化 */
	led_configuration();
	/* 按键中断初始化 */
	keyint_init();
	
    while(1)
    {
		led2_toggle();
		led4_toggle();
		_delay_us(1000000);			
    }
}


/*******外部中断0中断服务程序***********/
ISR(INT0_vect)
{	
	PORTD^=_BV(LED3);
}