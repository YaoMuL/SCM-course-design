#include "hc595.h"

/* 595 */
//595��ʼ��
void hc595_init(void)
{
	DDRC = (1<<PC0) | (1<<PC4) | (1<<PC5); //����˿�
	//hc595_ser = 1;
	hc595rck_set();
	hc595clk_res();
}

//�������
void hc595_en(void)
{
	hc595rck_res();	//����͵�ƽ
	hc595rck_set();	//����˲�������������
	hc595rck_res();	//Ϊ��һ����׼��
}

//��������һ���ֽ�
void hc595outbyte(unsigned char disdata)
{
	unsigned char i;//������λ
	for(i=0;i<8;i++)//��λ8��
	{
		if( disdata & 0x80 )//ȡ�����λ�����Ϊ1��������1�����Ϊ0��������0
		{
			hc595ser_set();
		}
		else
		{
			hc595ser_res();
		}
		disdata <<= 1;
		/* SCLK���������أ���λ�Ĵ����е�����������ƣ��������µ�����(��ser/DS����) */
		hc595clk_set();
		hc595clk_res();
	}
}
//595�������
void hc595out(unsigned char data)
{
	hc595outbyte(data);//������������
	hc595_en();//�����������
}
