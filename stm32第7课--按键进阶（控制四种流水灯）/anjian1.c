#include "stm32f4xx.h"

static GPIO_InitTypeDef  GPIO_InitStructure;

//ͨ���⺯��ֱ�Ӷ�ȡIO�ĵ�ƽ
#define S1 	GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_2) //PE2 --- KEY1


void delay()
{
	uint32_t i = 0x1000000;
	
	while(i--);
	
}

void KeyInit()
{
	/* GPIOG Peripheral clock enable---ʹ�ܶ˿�E,Aʱ�� */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; //�� 2 ������ key1 PE2
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; //��������ģʽ[�ص��޸�]
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; //���� IO ���ٶ�Ϊ 100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; //����Ҫ��������
	
	GPIO_Init(GPIOE, &GPIO_InitStructure);
	
}


void LedInit()
{
	/* ʹ�ܶ˿�F��Eʱ�� */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF|RCC_AHB1Periph_GPIOE, ENABLE);

	/* ���ö˿�F,E���� */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; // ��9������
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; // ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; // ����ģʽ��������������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;// ���ŵ�������ٶ�
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; // û������������
	GPIO_Init(GPIOF, &GPIO_InitStructure);


}

int main(void)
{

	
    LedInit();
	KeyInit();
	
	while(1)
	{	
		if(S1 == 0) {
		    //����������Ϊ�͵�ƽ������
		    GPIO_ResetBits(GPIOF,GPIO_Pin_9); 
		}
		else {
			//����������Ϊ�ߵ�ƽ�����
			GPIO_SetBits(GPIOF,GPIO_Pin_9); 	
		}

	}
	
}
