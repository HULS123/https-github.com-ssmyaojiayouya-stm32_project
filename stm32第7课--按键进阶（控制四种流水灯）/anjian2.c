#include "stm32f4xx.h"

static GPIO_InitTypeDef  GPIO_InitStructure;

//ͨ���⺯��ֱ�Ӷ�ȡIO�ĵ�ƽ
#define S0 	GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) //PA0 --- KEY0
#define S1 	GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_2) //PE2 --- KEY1
#define S2 	GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3) //PE3 --- KEY2
#define S3 	GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4) //PE4 --- KEY3


void delayms(uint32_t x)
{
	uint32_t i;
	
	while(x--) for(i = 0;i < 120;i++);
	
}

void KeyInit()
{
	/* GPIOG Peripheral clock enable---ʹ�ܶ˿�E,Aʱ�� */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE | RCC_AHB1Periph_GPIOA, ENABLE);
	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4; //�� 0,2,3,4 ������ key0,1,2,3 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; //��������ģʽ[�ص��޸�]
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; //���� IO ���ٶ�Ϊ 100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; //����Ҫ��������
	
	GPIO_Init(GPIOE, &GPIO_InitStructure);
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
}


void LedInit()
{
	/* ʹ�ܶ˿�F��Eʱ�� */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF|RCC_AHB1Periph_GPIOE, ENABLE);

	/* ���ö˿�F,E���� */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_13 | GPIO_Pin_14; // ��9,10,13,14������
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; // ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; // ����ģʽ��������������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;// ���ŵ�������ٶ�
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; // û������������
	
	GPIO_Init(GPIOF, &GPIO_InitStructure);
    GPIO_Init(GPIOE, &GPIO_InitStructure);

}



int main(void)
{

	
    LedInit();
	KeyInit();
	
	GPIO_SetBits(GPIOF,GPIO_Pin_9); 
	GPIO_SetBits(GPIOF,GPIO_Pin_10); 
	GPIO_SetBits(GPIOE,GPIO_Pin_13); 
	GPIO_SetBits(GPIOE,GPIO_Pin_14); 
	
	while(1)
	{	
		if(S0 == 0) {
		     //����������Ϊ�͵�ƽ������
		     GPIO_ResetBits(GPIOF,GPIO_Pin_9); 
		}
		else {
			//����������Ϊ�ߵ�ƽ�����
			GPIO_SetBits(GPIOF,GPIO_Pin_9); 
		}
		
		
		if(S1 == 0) {
			GPIO_ResetBits(GPIOF,GPIO_Pin_10); 
		}
		else {
			GPIO_SetBits(GPIOF,GPIO_Pin_10); 
		}
		
		
		if(S2 == 0) {
			GPIO_ResetBits(GPIOE,GPIO_Pin_13); 
		}
		else {
			GPIO_SetBits(GPIOE,GPIO_Pin_13); 
		}

		
		if(S3 == 0) {
			GPIO_ResetBits(GPIOE,GPIO_Pin_14); 
		}
		else {
			GPIO_SetBits(GPIOE,GPIO_Pin_14); 
		}		

	}
	
}
