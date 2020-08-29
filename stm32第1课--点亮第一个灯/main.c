#include "stm32f4xx.h"


static  GPIO_InitTypeDef  GPIO_InitStructure;


void delay()
{

	uint32_t i = 0x100000;
	while(i--);

}

int main()
{
	/* GPIOG Peripheral clock enable---ʹ�ܶ˿�ʱ�� */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);

	/* Configure PG6 and PG8 in output pushpull mode----���ö˿ڹ��� */
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_9; //��9������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; // ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; // ����ģʽ
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; // ����IO���ŵ�����ٶ�
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; // ����Ҫ����������
	GPIO_Init(GPIOF, &GPIO_InitStructure);
	
	while(1)
	{
		// ����Ϊ�ߵ�ƽ
		GPIO_SetBits(GPIOF, GPIO_Pin_9);
		delay();
		// ����Ϊ�͵�ƽ
		GPIO_ResetBits(GPIOF, GPIO_Pin_9);
		delay();
	
	}

}

