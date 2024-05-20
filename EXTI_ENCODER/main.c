#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "encoder.h"
int16_t Num=0;

int main(void)
{
	Encoder_Init();
	OLED_Power();
	OLED_Init();
	
	while(1)
	{
		Num += Encoder_get();
		OLED_ShowNum(1,2,Num,5);
	}
}

