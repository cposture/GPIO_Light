#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

int main()
{
	GPIO_InitTypeDef GPIO_Struct;
	int i;
	
	SystemInit();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_Struct.GPIO_Pin = GPIO_Pin_0;
	GPIO_Struct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Struct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&GPIO_Struct);

	while(1)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_0);
		for(i=0;i<0xfffff;i++)
			;
		
		GPIO_ResetBits(GPIOB,GPIO_Pin_0);
		for(i=0;i<0xfffff;i++)
			;
	}
}
