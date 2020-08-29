#include "led.h"

void Led_Init()//PF9,PF10,PE13,PE14
{
	GPIO_InitTypeDef    GPIO_InitStructure;
	// ʹ�ܶ˿�Fʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF|RCC_AHB1Periph_GPIOE, ENABLE);
	
	// ���ö˿ڹ���
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_13|GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;		// ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;		// ����ģʽ��������������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	// ����IO���ŵ�����ٶ�
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;		// ����Ҫ����������
	GPIO_Init(GPIOF, &GPIO_InitStructure);
	GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	PFout(9) = 1;
	PFout(10) = 1;
	PEout(13) = 1;
	PEout(14) = 1;
}

void Led_flash1()
{
	PFout(9) ^= 1;	//���ʵ�ַ�ת����
}

void Led_flash2()
{
	PFout(10) ^= 1;
}

void Led_flash3()
{
	PEout(13) ^= 1;
}

void Led_flash4()
{
	PEout(14) ^= 1;
}

void Led_flash5()
{
	PFout(9) ^= 1;
	PFout(10) ^= 1;
	PEout(13) ^= 1;
	PEout(14) ^= 1;
}
