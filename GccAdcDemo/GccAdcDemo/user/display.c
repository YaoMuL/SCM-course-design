#include "display.h"
unsigned char dispcode1[]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
unsigned char dispcode2[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};//共阳数码管
/* 在这里低电平选中，上电时候，先关闭数码管 */
void display_init(void)
{
		//DDRD=(1<<PD5)|(1<<PD6)|(1<<PD7);    //输出，数码管段选
		SMG2_OFF();
		SMG3_OFF();
		SMG4_OFF();
}
//数码管显示函数
void display(unsigned char Location,unsigned char num)
{
	switch(Location)
	{
//		case LED1:SMG1_ON();_delay_us(1000);SMG1_OFF();break;
		case LED2:hc595out(dispcode2[num]);SMG2_ON();_delay_us(1000);SMG2_OFF();break;
		case LED3:hc595out(dispcode1[num]);SMG3_ON();_delay_us(1000);SMG3_OFF();break;
		case LED4:hc595out(dispcode1[num]);SMG4_ON();_delay_us(1000);SMG4_OFF();break;
	}
}
//adc输出显示函数
void adc_display(unsigned int smg)
{
	unsigned char bai,shi,ge;
	//smg =smg*1.9607843;   // 5/2.55
	smg = smg*0.48875855;
	bai=smg/100;
	shi=(smg%100)/10;
	ge=smg%10;
	
	display(LED2,bai);
	display(LED3,shi);
	display(LED4,ge);
}