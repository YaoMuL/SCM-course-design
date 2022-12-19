#include "display.h"
unsigned char dispcode1[]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};//共阳带小数点
unsigned char dispcode2[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};//共阳无小数点
/* 在这里低电平选中，上电时候，先关闭数码管 */
void display_init(void)
{
		DDRD = (1<<PD4)|(1<<PD7); //输出口
		SMG1_OFF();
		SMG2_ON();
}
//时间显示函数
void display_time(unsigned char Location,unsigned char num)
{
	switch(Location)
	{
		case LED1:hc595out(dispcode2[num]);SMG1_ON();_delay_us(1000);SMG1_OFF();break;
		case LED2:hc595out(dispcode2[num]);SMG2_ON();_delay_us(1000);SMG2_OFF();break;
	}
}
