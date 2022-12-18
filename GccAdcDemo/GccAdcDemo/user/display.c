#include "display.h"

/* 595 */
//�������
void hc595_en(void)
{
	PORTC &= ~_BV(hc595_cs);//����͵�ƽ
	PORTC |= _BV(hc595_cs);	//����˲�������������
	PORTC &= ~_BV(hc595_cs);//Ϊ��һ����׼��
}
//595������ֽ�
void hc595outbyte(unsigned char disdata)
{
	unsigned char d1;//������λ
	for(d1=0;d1<8;d1++)//��λ8��
	{
		if(disdata&0x80)
		{
			PORTC |= _BV(hc595_ser);//���Ϊ1���1
		}
		else
		{
			PORTC &= ~_BV(hc595_ser);//�������0
		}
		disdata <<= 1;
		/* ʱ������ */
		PORTC |= _BV(hc595_clk);
		PORTC &= ~_BV(hc595_clk);
	}
}
void hc595out(unsigned char data)
{
	hc595outbyte(data);//�ͳ�����
	hc595_en();//��������
}
