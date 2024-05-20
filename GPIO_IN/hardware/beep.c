#include "stm32f10x.h"                  // Device header


void beep_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIO_Initstructure;
	GPIO_Initstructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Initstructure.GPIO_Pin=GPIO_Pin_12;
	GPIO_Initstructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_Initstructure);
}

void beep_on(void)
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);
}

void beep_off(void)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_12);
}