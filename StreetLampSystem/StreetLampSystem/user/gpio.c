#include "gpio.h"
/* �˿ڳ�ʼ�� */
void gpio_init(void)
{
	/* B�˿� */
	DDRB = (1<<PB1) | (1<<PB2) | (1<<PB7); //PB1��PB2Ϊ��·PWM�����PB7Ϊ1s��˸LED�����	
	/* C�˿� */
	DDRC = (1<<PC0) | (1<<PC4) | (1<<PC5);//�����595�� DS RCK CLK �������
	/* D�˿� */
	DDRD = 0;//����
	DDRD &= ~_BV(PD2);							// ��������
	DDRD |= (1<<PD5);							// ͨ���ж�ʵ��LED��˸�����
	DDRD |= (1<<PD4)|(1<<PD7);					// time��ʾ����ܶ˿�
	DDRD |= (1<<PD0) | (1<<PD1) | (1<<PD6);		//adc��ʾ����ܶ˿�
}