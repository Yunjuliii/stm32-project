#include "stm32f10x.h"                  // Device header


void light_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIO_Initstructure;
	GPIO_Initstructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_Initstructure.GPIO_Pin=GPIO_Pin_13;
	GPIO_Initstructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_Initstructure);
}

uint8_t light_read()
{
	return GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13);
}
	