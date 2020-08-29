#include "usart.h"

void usart1_init(uint32_t BaudRate)	//�������ʲ���
{
	//ʹ��GPIOA��ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE); 

	//GPIO��ʼ��Ϊ�������ģʽ
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;  		//���ܸ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;		//�������
	GPIO_InitStructure.GPIO_Speed = GPIO_High_Speed;
	GPIO_Init(GPIOA, &GPIO_InitStructure); 
	
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource9, GPIO_AF_USART1);
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource10, GPIO_AF_USART1);	//�˴������û�����ϲ�
	
	//USART����
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE); 

	//GPIO��ʼ��Ϊ�������ģʽ
	USART_InitStructure.USART_BaudRate = BaudRate;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;  	//��Ӳ����
	USART_InitStructure.USART_Mode = USART_Mode_Tx|USART_Mode_Rx;		//���ͽ���ģʽ
	USART_InitStructure.USART_Parity = USART_Parity_No;				//��У��λ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;   			//1bitֹͣλ
	USART_InitStructure.USART_WordLength = USART_WordLength_8b; 		//8bits����λ
	USART_Init(USART1, &USART_InitStructure); 
	
	
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);		//���������ݿ��������ж�
	
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;			//�����ⲿ�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;//ָ����ռ���ȼ�0-15
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;		//ָ�������ȼ�����Ӧ���ȼ�0-15
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//ʹ��
	NVIC_Init(&NVIC_InitStructure);	//�ж����ȼ������ã��ж�ʹ��
	
	USART_Cmd(USART1, ENABLE);		//�򿪴���
}


void usart2_init(uint32_t BaudRate)//PA2��PA3
{	
	//1.GPIO������
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE); //ʹ�� GPIOA ʱ��

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF; //���ܸ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; // ����ģʽ��������������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3; // ��2��3������
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; // û�����������裨�������գ�
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;// ���ŵ�������ٶ�
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	//ѡ�����ĸ��ù���
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource2,GPIO_AF_USART2); //GPIOA2 ����Ϊ USART2
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource3,GPIO_AF_USART2); //GPIOA3 ����Ϊ USART2	
	
	
	// 2.USART����
	//a.ʹ��USARTʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE); //ʹ�� USART2 ʱ��
	
	//b.USART��ʼ��	
	USART_InitStructure.USART_BaudRate = BaudRate; //����������
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; //��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx; //�շ�ģʽ	
	USART_InitStructure.USART_Parity = USART_Parity_No; //����żУ��λ
	USART_InitStructure.USART_StopBits = USART_StopBits_1; //һ��ֹͣλ
	USART_InitStructure.USART_WordLength = USART_WordLength_8b; //�ֳ�Ϊ 8 λ���ݸ�ʽ
	USART_Init(USART2, &USART_InitStructure);	
	

	//3.�ж�����	
	//a.���ÿ�������Щ�¼������ж�
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE); //��������ж�(���������ݿ��������ж�)
	
	//b.Usart1 NVIC ����
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn; //���ô��� 2 �ж�ͨ��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //�ж�ͨ��ʹ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01; //��ռ���ȼ� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02; //�ӣ���Ӧ�����ȼ� 
	NVIC_Init(&NVIC_InitStructure); //����ָ���Ĳ�����ʼ�� VIC �Ĵ���


	//4.�򿪴���
	USART_Cmd(USART2, ENABLE); //ʹ�ܴ��� 2	
	
}

void usart3_init(uint32_t BaudRate)//PB10��PB11
{
	GPIO_InitTypeDef    GPIO_InitStructure;
	USART_InitTypeDef   USART_InitStructure;
	NVIC_InitTypeDef   NVIC_InitStructure;
	
	//1.GPIO������
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE); //ʹ�� GPIOB ʱ��

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10|GPIO_Pin_11;			// ��10������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF; 		//���ܸ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;		// ����ģʽ��������������
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;	// û�����������裨�������գ�
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	// ���ŵ�������ٶ�
	GPIO_Init(GPIOB,&GPIO_InitStructure);

	//ѡ�����ĸ��ù���
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource10,GPIO_AF_USART3); //GPIOB10 ����Ϊ USART3
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource11,GPIO_AF_USART3); //GPIOB11 ����Ϊ USART3	
	
	
	// 2.USART����
	//a.ʹ��USARTʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE); //ʹ�� USART3 ʱ��
	
	//b.USART��ʼ��	
	USART_InitStructure.USART_BaudRate = BaudRate; //����������
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; //��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Rx|USART_Mode_Tx; //�շ�ģʽ	
	USART_InitStructure.USART_Parity = USART_Parity_No; //����żУ��λ
	USART_InitStructure.USART_StopBits = USART_StopBits_1; //һ��ֹͣλ
	USART_InitStructure.USART_WordLength = USART_WordLength_8b; //�ֳ�Ϊ 8 λ���ݸ�ʽ
	USART_Init(USART3, &USART_InitStructure);	

	//3.�ж�����	
	//a.���ÿ�������Щ�¼������ж�
	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE); //��������ж�(���������ݿ��������ж�)
	
	//b.Usart1 NVIC ����
	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn; //���ô��� 3 �ж�ͨ��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //�ж�ͨ��ʹ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01; //��ռ���ȼ� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02; //�ӣ���Ӧ�����ȼ� 
	NVIC_Init(&NVIC_InitStructure); //����ָ���Ĳ�����ʼ�� VIC �Ĵ���

	//4.�򿪴���
	USART_Cmd(USART3, ENABLE); //ʹ�ܴ���3	
}

//��������
void USART_SendDatas(USART_TypeDef * USARTx,uint8_t *SendBuf,uint16_t len)
{
	uint16_t i;
	for(i=0;i<len;i++)
	{
		USART_SendData( USARTx,SendBuf[i]);
		while(USART_GetFlagStatus(USARTx,USART_FLAG_TXE)==RESET);//�ȴ��������
	}
}

//�������У��ֵ,����2У��
u8 SUM_Check(u8 *dataBuf, u8 n)
{
	u8 data = 0, i;
	for(i = 0; i < n; i++)
	{
		data += dataBuf[i];
	}
	return data;
}

//�������У��ֵ����λȡ��+1У��.����3У��
u8 BACK_SUM_Check(u8 *dataBuf, u8 n)
{
	u8 data = 0, i;
	for(i = 1; i < n-1; i++)
	{
		data += dataBuf[i];
	}
	return (~data)+1;
}


//��������
void USART1_IRQHandler(void)
{
	static unsigned char data;
	if(USART_GetITStatus(USART1,USART_IT_RXNE)==SET)//�������ݴ����ж�
	{
		data = USART_ReceiveData(USART1);//��ȡ���յ�������
		//...���ݴ���
		
		USART_ClearITPendingBit(USART1,USART_IT_RXNE);//����жϱ�־λ
	}
	
}

//����2���жϴ�����
void USART2_IRQHandler(void)
{
	static unsigned char MQ_dataBuf[9]={0},j=0;//���徲̬�ֲ�����		
	if(USART_GetITStatus(USART2,USART_IT_RXNE)==SET)//�������ݴ����ж�
	{
		MQ_dataBuf[j++] = USART_ReceiveData(USART2);//��ȡ���յ�������
		if(MQ_dataBuf[0] != 0xff)//ÿ֡���ݵĿ�ͷ������0xff
		{
			j=0;
		}
		if(j == 9)//���ݽ��ճɹ�
		{
			j=0;
			if(BACK_SUM_Check(MQ_dataBuf,9) == MQ_dataBuf[8])//���У���Ƿ���ȷ
			{
				MQ_value = MQ_dataBuf[2]<<8 | MQ_dataBuf[3];
				sprintf((char *)MQ_SendBuf, "����ֵ:%-5.2f            ", MQ_value);
				USART_SendDatas(USART1,MQ_SendBuf,strlen((char *)MQ_SendBuf));
				/*
				//��������led����
				if(MQ_value > 70.0)
				{
					USART_SendDatas(USART1,MQ_Warm,strlen((char *)MQ_Warm));
					PFout(8) = 1;
					Led_flash1();
				}
				else
				{
					PFout(8) = 0;
				}
				*/
			}		
		}
		USART_ClearITPendingBit(USART2,USART_IT_RXNE);//����жϱ�־λ
	}
}

//����3���жϴ�����
void USART3_IRQHandler(void)
{	
	static unsigned char GY_dataBuf[15]={0},i=0;//���徲̬�ֲ�����		
	if(USART_GetITStatus(USART3,USART_IT_RXNE)==SET)//�������ݴ����ж�
	{
		GY_dataBuf[i++] = USART_ReceiveData(USART3);//��ȡ���յ�������
		if(i == 2)
		{
			if(GY_dataBuf[0] != 0x5A || GY_dataBuf[1] != 0x5A)//ÿ֡���ݵĿ�ͷ������0xff
			{
				i=0;
			}
		}
		
		//����ǿ��
		if(i == 9 && GY_dataBuf[2] == 0x15)//���ݽ��ճɹ�
		{
			i=0;
			if(SUM_Check(GY_dataBuf,8) ==  GY_dataBuf[8])//���У���Ƿ���ȷ
			{
				light_value = (GY_dataBuf[4]<<24)|(GY_dataBuf[5]<<16)|(GY_dataBuf[6]<<8)| GY_dataBuf[7];
				light_value /= 100.0;
				sprintf((char *)GY_SendBuf, "����ǿ�ȣ�%-5.2f lux\r\n", light_value);
				USART_SendDatas(USART1,GY_SendBuf,strlen((char *)GY_SendBuf));

			}
		}
		
		//��ʪ�ȡ����Ρ���ѹ
		if(i == 15 && GY_dataBuf[2] == 0x45)
		{
			i=0;
			if(SUM_Check(GY_dataBuf,14) ==  GY_dataBuf[14])//���У���Ƿ���ȷ
			{
				temp_value = (GY_dataBuf[4]<<8)|GY_dataBuf[5];
				temp_value /= 100.0;
				pres_value = (GY_dataBuf[6]<<24)|(GY_dataBuf[7]<<16)|(GY_dataBuf[8]<<8)| GY_dataBuf[9];
				pres_value /= 100.0;
				humi_value = (GY_dataBuf[10]<<8)|GY_dataBuf[11];
				humi_value /= 100.0;
				alti_value = (GY_dataBuf[12]<<8)|GY_dataBuf[13];
				sprintf((char *)GY_SendBuf, "�¶ȣ�%-5.2f ��             ��ѹ��%-5.2f pa\r\nʪ�ȣ�%-5.2f %%             ���Σ�%-5.2f m\r\n\n", temp_value,pres_value,humi_value,alti_value);
				USART_SendDatas(USART1,GY_SendBuf,strlen((char *)GY_SendBuf));
			}
		}
		USART_ClearITPendingBit(USART3,USART_IT_RXNE);//����жϱ�־λ
	}
}

void Warming()
{
	if(MQ_value>70)
	{
		USART_SendDatas(USART1,MQ_Warm,strlen((char *)MQ_Warm));
		PFout(8) = 1;
		Led_flash1();
	}
	if(light_value>120)
	{
		USART_SendDatas(USART1,LIGHT_Warm,strlen((char *)LIGHT_Warm));
		PFout(8) = 1;
		Led_flash2();
	}
	if(temp_value>35)
	{
		USART_SendDatas(USART1,TEMP_Warm,strlen((char *)TEMP_Warm));
		PFout(8) = 1;
		Led_flash3();
	}
	if(humi_value>80)
	{
		USART_SendDatas(USART1,HUMI_Warm,strlen((char *)HUMI_Warm));
		PFout(8) = 1;
		Led_flash4();
	}
	if(MQ_value<=70 && light_value<=120 && temp_value<=35 && humi_value<=80) 
	{
		PFout(8) = 0;
		PFout(9) = 1;
		PFout(10) = 1;
		PEout(13) = 1;
		PEout(14) = 1;
	}
}
