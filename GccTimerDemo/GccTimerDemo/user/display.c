#include "display.h"

/* 595 */
//锁存输出
void hc595_en(void)
{
	PORTC &= ~_BV(hc595_cs);//锁存低电平
	PORTC |= _BV(hc595_cs);	//所存端产生上升沿跳变
	PORTC &= ~_BV(hc595_cs);//为下一次做准备
}
//595输出单字节
void hc595outbyte(unsigned char disdata)
{
	unsigned char d1;//数据移位
	for(d1=0;d1<8;d1++)//移位8次
	{
		if(disdata&0x80)
		{
			PORTC |= _BV(hc595_ser);//如果为1输出1
		}
		else
		{
			PORTC &= ~_BV(hc595_ser);//否则输出0
		}
		disdata <<= 1;
		/* 时钟跳变 */
		PORTC |= _BV(hc595_clk);
		PORTC &= ~_BV(hc595_clk);
	}
}
void hc595out(unsigned char data)
{
	hc595outbyte(data);//送出数据
	hc595_en();//数据锁存
}
