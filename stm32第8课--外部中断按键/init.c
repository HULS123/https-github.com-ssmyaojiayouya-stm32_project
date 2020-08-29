#include "myhead.h"

static GPIO_InitTypeDef  GPIO_InitStructure;

void LedInit()
{
	/* ʹ�ܶ˿�F��Eʱ�� */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF|RCC_AHB1Periph_GPIOE, ENABLE);

	/* ���ö˿�F,E���� */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_13|GPIO_Pin_14; // ��9��10������
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; // ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; // ����ģʽ��������������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;// ���ŵ�������ٶ�
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; // û������������
	GPIO_Init(GPIOF, &GPIO_InitStructure);
	GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	// ����������Ϊ�ߵ�ƽ,���
    GPIO_SetBits(GPIOF, GPIO_Pin_9|GPIO_Pin_10);
    GPIO_SetBits(GPIOE, GPIO_Pin_13|GPIO_Pin_14);
	
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


//1.�ж���ռ��ʾ
void EXTI0_Init(void)
{
	 EXTI_InitTypeDef   EXTI_InitStructure;
	 NVIC_InitTypeDef   NVIC_InitStructure;
   
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);
	
	//ѡ���Ӧ��GPIO�������ӵ���Ӧ���жϿ�����
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA,EXTI_PinSource0);
	
	
	//���� EXTI_InitTypeDef �ṹ������ⲿ�жϿ����� 0 ��ʼ��
	EXTI_InitStructure.EXTI_Line = EXTI_Line0;
  EXTI_InitStructure.EXTI_Mode =EXTI_Mode_Interrupt; //�ж�����
  EXTI_InitStructure.EXTI_Trigger =EXTI_Trigger_Falling; //�½����ж�
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	
	//���� NVIC_InitTypeDef �ṹ����ж�������������
	NVIC_InitStructure.NVIC_IRQChannel =EXTI0_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority= 0x02;
  NVIC_InitStructure.NVIC_IRQChannelCmd =ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
}



void EXTI2_Init(void)
{
	 EXTI_InitTypeDef   EXTI_InitStructure;
	 NVIC_InitTypeDef   NVIC_InitStructure;
   
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);
	
	//ѡ���Ӧ��GPIO�������ӵ���Ӧ���жϿ�����
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE,EXTI_PinSource2);
	
	
	//���� EXTI_InitTypeDef �ṹ������ⲿ�жϿ����� 2 ��ʼ��
	EXTI_InitStructure.EXTI_Line = EXTI_Line2;
  EXTI_InitStructure.EXTI_Mode =EXTI_Mode_Interrupt; //�ж�����
  EXTI_InitStructure.EXTI_Trigger =EXTI_Trigger_Falling; //�½����ж�
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	
	//���� NVIC_InitTypeDef �ṹ����ж�������������
	NVIC_InitStructure.NVIC_IRQChannel =EXTI2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority= 0x02;
  NVIC_InitStructure.NVIC_IRQChannelCmd =ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	

}

void EXTI3_Init(void)
{
	 EXTI_InitTypeDef   EXTI_InitStructure;
	 NVIC_InitTypeDef   NVIC_InitStructure;
   
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);
	
	//ѡ���Ӧ��GPIO�������ӵ���Ӧ���жϿ�����
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE,EXTI_PinSource3);
	
	
	//���� EXTI_InitTypeDef �ṹ������ⲿ�жϿ����� 3 ��ʼ��
	EXTI_InitStructure.EXTI_Line = EXTI_Line3;
  EXTI_InitStructure.EXTI_Mode =EXTI_Mode_Interrupt; //�ж�����
  EXTI_InitStructure.EXTI_Trigger =EXTI_Trigger_Falling; //�½����ж�
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	
	//���� NVIC_InitTypeDef �ṹ����ж�������������
	NVIC_InitStructure.NVIC_IRQChannel =EXTI3_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority= 0x02;
  NVIC_InitStructure.NVIC_IRQChannelCmd =ENABLE;
	NVIC_Init(&NVIC_InitStructure);

}


void EXTI4_Init(void)
{
	 EXTI_InitTypeDef   EXTI_InitStructure;
	 NVIC_InitTypeDef   NVIC_InitStructure;
   
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);
	
	//ѡ���Ӧ��GPIO�������ӵ���Ӧ���жϿ�����
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE,EXTI_PinSource4);
	
	
	//���� EXTI_InitTypeDef �ṹ������ⲿ�жϿ����� 4 ��ʼ��
	EXTI_InitStructure.EXTI_Line = EXTI_Line4;
  EXTI_InitStructure.EXTI_Mode =EXTI_Mode_Interrupt; //�ж�����
  EXTI_InitStructure.EXTI_Trigger =EXTI_Trigger_Falling; //�½����ж�
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	
	//���� NVIC_InitTypeDef �ṹ����ж�������������
	NVIC_InitStructure.NVIC_IRQChannel =EXTI4_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority= 0x02;
  NVIC_InitStructure.NVIC_IRQChannelCmd =ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	
}


void EXTI0_IRQHandler(void)
{
	//����Ƿ��д����ж�
	if(EXTI_GetITStatus(EXTI_Line0) == SET) 
	{
		//����û�����		
    liushuideng1();
		
		//��ձ�־λ������CPU�Ѿ��������ж����󣬿��Դ�����һ���ж�
		EXTI_ClearITPendingBit(EXTI_Line0);		
	}
	
}


void EXTI2_IRQHandler(void)
{
	//����Ƿ��д����ж�
	if(EXTI_GetITStatus(EXTI_Line2) == SET) 
	{
		//����û�����		
    liushuideng2();
		
		
		//��ձ�־λ������CPU�Ѿ��������ж����󣬿��Դ�����һ���ж�
		EXTI_ClearITPendingBit(EXTI_Line2);		
	}
	
}

void EXTI3_IRQHandler(void)
{
	//����Ƿ��д����ж�
	if(EXTI_GetITStatus(EXTI_Line3) == SET) 
	{
		//����û�����		
    two_liangmie();
		
		
		//��ձ�־λ������CPU�Ѿ��������ж����󣬿��Դ�����һ���ж�
		EXTI_ClearITPendingBit(EXTI_Line3);		
	}
	
}


void EXTI4_IRQHandler(void)
{
	//����Ƿ��д����ж�
	if(EXTI_GetITStatus(EXTI_Line4) == SET) 
	{
		//����û�����		
    all_liangmie();
		
		
		//��ձ�־λ������CPU�Ѿ��������ж����󣬿��Դ�����һ���ж�
		EXTI_ClearITPendingBit(EXTI_Line4);		
	}
	
}


