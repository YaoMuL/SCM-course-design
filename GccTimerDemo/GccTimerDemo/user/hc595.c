#include "hc595.h"

/* 595 */
//595��ʼ��
void hc595_init(void)
{
	//DDRC = (1<<PC0) | (1<<PC4) | (1<<PC5); //����������
	//hc595_ser = 1;
	hc595_rck = 1;
	hc595_clk = 0;
}

//�������
void hc595_en(void)
{
	hc595_rck = 0;	//����͵�ƽ
	hc595_rck = 1;	//����˲�������������
	hc595_rck = 0;	//Ϊ��һ����׼��
}

//��������һ���ֽ�
void hc595outbyte(unsigned char disdata)
{
	unsigned char i;//������λ
	for(i=0;i<8;i++)//��λ8��
	{
		if( disdata & 0x80 )//ȡ�����λ�����Ϊ1��������1�����Ϊ0��������0
		{
			hc595_ser = 1;
		}
		else
		{
			hc595_ser = 0;
		}
		disdata <<= 1;
		/* SCLK���������أ���λ�Ĵ����е�����������ƣ��������µ�����(��ser/DS����) */
		hc595_clk = 1;
		hc595_clk = 0;
	}
}
//595�������
void hc595out(unsigned char data)
{
	hc595outbyte(data);//������������
	hc595_en();//�����������
}
