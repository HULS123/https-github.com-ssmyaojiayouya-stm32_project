#include "myhead.h"

/*
    �������ܣ������еİ����ļ��ʹ���ⲿ�жϽ���ʵ��
*/




int main(void)
{
	//���״̬
	GPIO_SetBits(GPIOF,GPIO_Pin_9); 
	GPIO_SetBits(GPIOF,GPIO_Pin_10); 
	GPIO_SetBits(GPIOE,GPIO_Pin_13); 
	GPIO_SetBits(GPIOE,GPIO_Pin_14); 

	
	LedInit();
	KeyInit();
	EXTI0_Init();
	
	EXTI2_Init();
	
	EXTI3_Init();
	
	EXTI4_Init();
	
	while(1)
	{
      
	}
	
	
}


