#include "stm32f10x.h"                  // Device header
#include "beep.h"
#include "light.h"

uint8_t readnum;
int main(void)
{
	beep_Init();
	light_Init();
	
	
	
	while(1)
	{
		readnum = light_read();
		if(readnum==0)
		{
			beep_on();
		}
		else
		{
			beep_off();
		}
		
	}	
}
