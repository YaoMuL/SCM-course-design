/*
*adc功能，参考电压AREF为2.5v
*/
#include "adc.h"
unsigned int temp,temp2;

int main(void)
{
	/* 数码管初始化 */
	display_init();
	/* 595初始化 */
	hc595_init();
	/* adc初始化 */
	adc_init();
	
	while(1)
	{
		cli();
		adc_display(temp);//动态显示数码管
		sei();
	}
}
/* 中断服务函数 */
ISR(ADC_vect)
{
	//delay_1ms(1);
	//temp=ADCH;//读取转化的数据
	temp = ADCL>>6; 
	temp2 = ADCH;
	temp2 <<= 2;
	temp += temp2;   //10bit
	ADCSRA|=0X40;//重启ADC，设置ADCSRA的ADATA和连续转换模式时不用
}