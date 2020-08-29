#include "key.h"

void Key_Init()
{
	// ʹ�ܶ˿�Fʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOE, ENABLE);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

	// ���ö˿ڹ���
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;			// ���ģʽ
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	// ����IO���ŵ�����ٶ�
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;		// ����Ҫ����������
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_Init(GPIOE, &GPIO_InitStructure);
}

void Extern_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	//EXTI0
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);
	
	EXTI_InitStructure.EXTI_Line = EXTI_Line0;				//ָ��ʹ�õڼ����ж�
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;		//ѡ��ģʽ
	EXTI_InitStructure.EXTI_Trigger= EXTI_Trigger_Falling;	//ѡ�񴥷���ʽ
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;				//ʹ���ж�
	EXTI_Init(&EXTI_InitStructure);
	
	/* Enable and set EXTI Line0 Interrupt to the lowest priority */
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;			//�����ⲿ�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;//ָ����ռ���ȼ�0-15
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;		//ָ�������ȼ�0-15
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//ʹ��
	NVIC_Init(&NVIC_InitStructure);//�ж����ȼ������ã��ж�ʹ��
		
	//EXTI2
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource2);
	
	EXTI_InitStructure.EXTI_Line = EXTI_Line2;				//ָ��ʹ�õڼ����ж�
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;		//ѡ��ģʽ
	EXTI_InitStructure.EXTI_Trigger= EXTI_Trigger_Falling;	//ѡ�񴥷���ʽ
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;				//ʹ���ж�
	EXTI_Init(&EXTI_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;			//�����ⲿ�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;//ָ����ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;		//ָ�������ȼ�
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//ʹ��
	NVIC_Init(&NVIC_InitStructure);//�ж����ȼ������ã��ж�ʹ��
	
	/*
	//EXTI3
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource3);
	
	EXTI_InitStructure.EXTI_Line = EXTI_Line3;				//ָ��ʹ�õڼ����ж�
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;		//ѡ��ģʽ
	EXTI_InitStructure.EXTI_Trigger= EXTI_Trigger_Falling;	//ѡ�񴥷���ʽ
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;				//ʹ���ж�
	EXTI_Init(&EXTI_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;			//�����ⲿ�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;//ָ����ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;		//ָ�������ȼ�
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//ʹ��
	NVIC_Init(&NVIC_InitStructure);//�ж����ȼ������ã��ж�ʹ��


	//EXTI4
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource4);
	
	EXTI_InitStructure.EXTI_Line = EXTI_Line4;				//ָ��ʹ�õڼ����ж�
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;		//ѡ��ģʽ
	EXTI_InitStructure.EXTI_Trigger= EXTI_Trigger_Falling;	//ѡ�񴥷���ʽ
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;				//ʹ���ж�
	EXTI_Init(&EXTI_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;			//�����ⲿ�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;//ָ����ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;		//ָ�������ȼ�
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//ʹ��
	NVIC_Init(&NVIC_InitStructure);//�ж����ȼ������ã��ж�ʹ��
	*/
}
