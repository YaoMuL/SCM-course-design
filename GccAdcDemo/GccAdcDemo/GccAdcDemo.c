/*
*adc���ܣ��ο���ѹAREFΪ2.5v
*/
#include "adc.h"
unsigned int temp,temp2;

int main(void)
{
	/* ����ܳ�ʼ�� */
	display_init();
	/* 595��ʼ�� */
	hc595_init();
	/* adc��ʼ�� */
	adc_init();
	
	while(1)
	{
		cli();
		adc_display(temp);//��̬��ʾ�����
		sei();
	}
}
/* �жϷ����� */
ISR(ADC_vect)
{
	//delay_1ms(1);
	//temp=ADCH;//��ȡת��������
	temp = ADCL>>6; 
	temp2 = ADCH;
	temp2 <<= 2;
	temp += temp2;   //10bit
	ADCSRA|=0X40;//����ADC������ADCSRA��ADATA������ת��ģʽʱ����
}