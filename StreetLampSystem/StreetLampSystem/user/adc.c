#include "adc.h"

void adc_init(void)
{
	cli();
	ADCSRA =0;//关闭ADC
	ADMUX = 0X27;// 0010 0111 左对齐，参考电压AREF.通道7
	ADCSRA = (1<<ADEN)|(1<<ADSC)|(1<<ADIE)|(7);//使能adc和中断，预分频128，启动ADC,不设置连续转化模式
	sei();
}
