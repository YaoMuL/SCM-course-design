#include "hc595.h"

/* 595 */
//595初始化
void hc595_init(void)
{
	//DDRC = (1<<PC0) | (1<<PC4) | (1<<PC5); //缓冲器控制
	//hc595_ser = 1;
	hc595_rck = 1;
	hc595_clk = 0;
}

//锁存输出
void hc595_en(void)
{
	hc595_rck = 0;	//锁存低电平
	hc595_rck = 1;	//所存端产生上升沿跳变
	hc595_rck = 0;	//为下一次做准备
}

//串行输入一个字节
void hc595outbyte(unsigned char disdata)
{
	unsigned char i;//数据移位
	for(i=0;i<8;i++)//移位8次
	{
		if( disdata & 0x80 )//取出最高位，如果为1串行输入1，如果为0串行输入0
		{
			hc595_ser = 1;
		}
		else
		{
			hc595_ser = 0;
		}
		disdata <<= 1;
		/* SCLK产生上升沿，移位寄存器中的数据整体后移，并接受新的数据(从ser/DS输入) */
		hc595_clk = 1;
		hc595_clk = 0;
	}
}
//595输出数据
void hc595out(unsigned char data)
{
	hc595outbyte(data);//串行输入数据
	hc595_en();//数据锁存输出
}
