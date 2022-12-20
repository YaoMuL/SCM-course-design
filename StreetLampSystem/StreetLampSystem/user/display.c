#include "display.h"
unsigned char dispcode1[]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};//共阳带小数点
unsigned char dispcode2[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};//共阳无小数点
/* 在这里低电平选中，上电时候，先关闭数码管 */
void display_init(void)
{
//		DDRD=(1<<PD5)|(1<<PD6)|(1<<PD7);    //输出口
	time_shi_off();
	time_ge_off();
	
	adc_bai_off();
	adc_shi_off();
	adc_ge_off();
}

//数码管显示函数
void display(unsigned char Location, unsigned char time, unsigned char adc)
{
	switch(Location)
	{
		case bai:
				hc595out(dispcode2[time],dispcode1[adc]);
				adc_bai_on();
				_delay_us(1000);
				adc_bai_off();
				break;
		case shi:
				hc595out(dispcode2[time],dispcode2[adc]);
				adc_shi_on();time_shi_on();
				_delay_us(1000);
				adc_shi_off();time_shi_off();
				break;
		case ge :
				hc595out(dispcode2[time],dispcode2[adc]);
				adc_ge_on();time_ge_on();
				_delay_us(1000);
				adc_ge_off();time_ge_off();
				break;
	}
}

/* 数码管显示任务函数 */
void display_task(unsigned char time , unsigned int adc)
{
	adc *= 0.48875855;
	display(bai,1,adc/100);				//秒表未设百位，此处随便给值
	display(shi,time/10,(adc%100)/10);
	display(ge,time%10,adc%10);				
}