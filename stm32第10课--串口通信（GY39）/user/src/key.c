#include "key.h"

void Key_Init()
{
	GPIO_InitTypeDef GPIO_InitStruct;
	// ʹ�ܶ˿�Fʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOE, ENABLE);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

	// ���ö˿ڹ���
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;			// ���ģʽ
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;	// ����IO���ŵ�����ٶ�
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;		// ����Ҫ����������
	GPIO_Init(GPIOA, &GPIO_InitStruct);
}



