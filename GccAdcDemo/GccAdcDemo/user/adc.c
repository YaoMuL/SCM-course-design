#include "display.h"
#include "adc.h"

void display(unsigned int smg)
{
	smg = smg * 0.48875855;
	bai = smg/100;
	shi = (smg%100)/10;
	ge  = smg%100;
	
	hc595out(disp)
	
}