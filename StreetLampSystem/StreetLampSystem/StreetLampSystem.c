/*
*1�����������һ����˸һ��
*2�������ж�ʹ��һ�������������˸
*3����ʱ��0ʵ�����
*4����ʱ��1��pwm����:1k��25%ռ�ձ���λ����PWM
*5��adc���ܣ��ο���ѹAREFΪ2.5v
*/

#include "StreetLampSystem.h"

unsigned int temp=0,temp2=0;
unsigned int Cnt=0,Cnt2=0,num=0;

int main(void)
{
	/* �˿ڳ�ʼ�� */
	gpio_init();
	/* �ⲿ�жϳ�ʼ�� */
	keyint_init();
	/* ����ܳ�ʼ�� */
	display_init();
	/* 595��ʼ�� */
	hc595_init();
	/* ��ʱ����ʼ�� */
	timer0_init();
	pwm_init();
	spwm_init();
	/* adc��ʼ�� */
	adc_init();
	
	while(1)
	{
		/* led_task��һ����˸��timer0�ж���ʵ�� */
		/* ����adc��ʾ������display_task�� */
		display_task(num,temp);
	}
}
/* �жϺ�����interrupt.c�� */