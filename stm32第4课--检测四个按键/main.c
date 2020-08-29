#include "stm32f4xx.h"

static GPIO_InitTypeDef  GPIO_InitStructure;


void delay()
{
	uint32_t i = 0x1000000;
	
	while(i--);
	
}


void LedInit()
{
	/* ʹ�ܶ˿�F��Eʱ�� */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF|RCC_AHB1Periph_GPIOE, ENABLE);

	/* ���ö˿�F,E���� */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10| GPIO_Pin_13|GPIO_Pin_14; // ��9��10������
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; // ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; // ����ģʽ��������������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;// ���ŵ�������ٶ�
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; // û������������
	// ��ʼ��gpio
	GPIO_Init(GPIOF, &GPIO_InitStructure);
	GPIO_Init(GPIOE, &GPIO_InitStructure);

}

void KeyInit()
{
	/* ʹ�ܶ˿�A��Eʱ�� */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOE, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; // ����ģʽ�����˿ڵ�ƽ
	//GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; // ����ģʽ��������������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;// ���ŵ�������ٶ�
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; // û������������
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_Init(GPIOE, &GPIO_InitStructure);
}

int main(void)
{
	LedInit();
	KeyInit();
	
	GPIO_SetBits(GPIOF, GPIO_Pin_9|GPIO_Pin_10);
	GPIO_SetBits(GPIOE, GPIO_Pin_13|GPIO_Pin_14);
	while(1)
	{
		
		// �жϰ���PA0�Ƿ���
		if(Bit_RESET == GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0))
		{
			// ����������Ϊ�͵�ƽ������
			GPIO_ResetBits(GPIOF, GPIO_Pin_9);
		}
		else
			// ����������Ϊ�ߵ�ƽ,���
			GPIO_SetBits(GPIOF, GPIO_Pin_9);
		
		
		// �жϰ���PE2�Ƿ���
		if(Bit_RESET == GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_2))
		{
			// ����������Ϊ�͵�ƽ������
			GPIO_ResetBits(GPIOF, GPIO_Pin_10);
		}
		else
			// ����������Ϊ�ߵ�ƽ,���
			GPIO_SetBits(GPIOF, GPIO_Pin_10);
		
		// �жϰ���PE3�Ƿ���
		if(Bit_RESET == GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3))
		{
			// ����������Ϊ�͵�ƽ������
			GPIO_ResetBits(GPIOE, GPIO_Pin_9|GPIO_Pin_13);
		}
		else
			// ����������Ϊ�ߵ�ƽ,���
			GPIO_SetBits(GPIOE, GPIO_Pin_9|GPIO_Pin_13);
			
		
		// �жϰ���PE4�Ƿ���
		if(Bit_RESET == GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4))
		{
			// ����������Ϊ�͵�ƽ������
			GPIO_ResetBits(GPIOE, GPIO_Pin_9|GPIO_Pin_14);
		}
		else
			// ����������Ϊ�ߵ�ƽ,���
			GPIO_SetBits(GPIOE, GPIO_Pin_9|GPIO_Pin_14);
			
			
	}
	
	
}
