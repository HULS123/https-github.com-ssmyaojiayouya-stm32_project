#include "beep.h"

void Beep_Init()//PF8
{
	GPIO_InitTypeDef    GPIO_InitStructure;
	// ʹ�ܶ˿�Fʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	
	// ���ö˿ڹ���
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;		// ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;		// ����ģʽ��������������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	// ����IO���ŵ�����ٶ�
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;		// ����Ҫ����������
	GPIO_Init(GPIOF, &GPIO_InitStructure);
}

