#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "countsensor.h"
int16_t Num=0;

int main(void)
{
	OLED_Power();
	OLED_Init();
	CountSensor_Init(); // init the interrupt, after running this, 
	                    //each time something happends, program goes into interrupt function
	
	while(1)
	{
	OLED_ShowNum(1,1,Num,5); 
	}
}

void EXTI15_10_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line14)==SET) //test if the interrupt is from 14(15-10 use the same line)
	{
		Num++;
		EXTI_ClearITPendingBit(EXTI_Line14);  // in case the program keeps running the interrupt function
	}
	
}