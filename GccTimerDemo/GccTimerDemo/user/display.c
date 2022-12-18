#include "display.h"
unsigned char dispcode[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};//共阳数码管
/* 在这里低电平选中，上电时候，先关闭数码管 */
void display_init(void)
{
		//DDRD = (1<<PD4) | (1<<PD7); 
		SMG1_OFF();
		SMG2_OFF();
}
//时间显示函数
void display_time(unsigned char Location,unsigned char num)
{
	switch(Location)
	{
		case LED1:SMG1_ON();_delay_us(1000);SMG1_OFF;break;
		case LED2:SMG2_ON();_delay_us(1000);SMG2_OFF;break;
	}
	hc595out(dispcode[num]);
}
