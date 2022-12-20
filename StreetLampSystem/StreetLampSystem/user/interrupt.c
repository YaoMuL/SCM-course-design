/* �жϷ������ */
#include "interrupt.h"
/*******�ⲿ�ж�0�жϷ������***********/
ISR(INT0_vect)
{
	PORTD^=_BV(LED3);
}

/*******TIMER0�жϷ����������ܣ�***********/
ISR(TIMER0_OVF_vect)
{
	/* ÿ250ms�����ж� */
	TCNT0 = 6; //��װ�ؼ���ֵ
	Cnt++;
	if(Cnt > 3)//num ÿ�� 250ms*4=1s ����һ��
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

/*******TIMER1�жϷ������PWM���ܣ�***********/
/* 1k��25%ռ�ձ���λ����PWM */
ISR(TIMER1_COMPA_vect)
{
	OCR1A = 125; //��װ�ؼ���ֵ
	ICR1  = 500;
	Cnt2++;
	if(Cnt2 > 1000)
	{
		Cnt2 = 0;
	}
	PORTB ^= (1<<PB1);//PWM����������˿�
}

/*******ADC�жϷ������***********/
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
