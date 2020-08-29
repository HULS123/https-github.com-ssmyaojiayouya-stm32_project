#include "stm32f4xx.h"


static  GPIO_InitTypeDef  GPIO_InitStructure;

void delay()
{
	uint32_t i = 0x1000000;
	
	while(i--);
}

void initLED()
{
	
	/* GPIOG Peripheral clock enable---ʹ�ܶ˿�F,Eʱ�� */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF|RCC_AHB1Periph_GPIOE, ENABLE);

	/* Configure PG6 and PG8 in output pushpull mode----���ö˿�F,E���� */
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_13 | GPIO_Pin_14; //��9,10,13,14������
	
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; // ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; // ����ģʽ��������������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; // ����IO���ŵ�����ٶ�
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; // ����Ҫ����������
	GPIO_Init(GPIOF, &GPIO_InitStructure);  //ʹ��F�˿�
	GPIO_Init(GPIOE, &GPIO_InitStructure);  //ʹ��E�˿�

		GPIO_SetBits(GPIOF,GPIO_Pin_9 | GPIO_Pin_10); 		
		GPIO_SetBits(GPIOE,GPIO_Pin_13 | GPIO_Pin_14); 	
}

int main(void)
{

	
   initLED();
	
	while(1)
	{
		
		//����������Ϊ�ߵ�ƽ�����
		GPIO_SetBits(GPIOF,GPIO_Pin_9 | GPIO_Pin_10); 		
		GPIO_SetBits(GPIOE,GPIO_Pin_13 | GPIO_Pin_14); 		
		delay();
		
		
			
		//����������Ϊ�͵�ƽ������
		GPIO_ResetBits(GPIOF,GPIO_Pin_9 | GPIO_Pin_10); 
		GPIO_ResetBits(GPIOE,GPIO_Pin_13 | GPIO_Pin_14); 
		delay();
	}
	
}
