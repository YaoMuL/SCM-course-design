#include "adc.h"

void adc_init(void)
{
	cli();
	ADCSRA =0;//�ر�ADC
	ADMUX = 0X27;// 0010 0111 ����룬�ο���ѹAREF.ͨ��7
	ADCSRA = (1<<ADEN)|(1<<ADSC)|(1<<ADIE)|(7);//ʹ��adc���жϣ�Ԥ��Ƶ128������ADC,����������ת��ģʽ
	sei();
}
