/*
*1�����������һ����˸һ��
*2�������ж�ʹ��һ�������������˸
*/

#include "led.h"

int main(void)
{	
	/* led��������ʼ�� */
	led_configuration();
	/* �����жϳ�ʼ�� */
	keyint_init();
	
    while(1)
    {
		led2_toggle();
		led4_toggle();
		_delay_us(1000000);			
    }
}


/*******�ⲿ�ж�0�жϷ������***********/
ISR(INT0_vect)
{	
	PORTD^=_BV(LED3);
}