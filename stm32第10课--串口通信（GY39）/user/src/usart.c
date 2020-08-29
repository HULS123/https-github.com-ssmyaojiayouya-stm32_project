#include "usart.h"
#include "bitband.h"
#include "led.h"

void usart1_init(uint32_t BaudRate)	//�������ʲ���
{
	GPIO_InitTypeDef GPIO_InitStruct;
	USART_InitTypeDef USART_InitStruct;
	NVIC_InitTypeDef NVIC_InitStructure;
	//ʹ��GPIOA��ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE); 

	//GPIO��ʼ��Ϊ�������ģʽ
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;  		//���ܸ���ģʽ
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;		//�������
	GPIO_InitStruct.GPIO_Speed = GPIO_High_Speed;
	GPIO_Init(GPIOA, &GPIO_InitStruct); 
	
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource9, GPIO_AF_USART1);
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource10, GPIO_AF_USART1);	//�˴������û�����ϲ�
	
	//USART����
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE); 

	//GPIO��ʼ��Ϊ�������ģʽ
	USART_InitStruct.USART_BaudRate = BaudRate;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;  	//��Ӳ����
	USART_InitStruct.USART_Mode = USART_Mode_Tx|USART_Mode_Rx;		//���ͽ���ģʽ
	USART_InitStruct.USART_Parity = USART_Parity_No;				//��У��λ
	USART_InitStruct.USART_StopBits = USART_StopBits_1;   			//1bitֹͣλ
	USART_InitStruct.USART_WordLength = USART_WordLength_8b; 		//8bits����λ
	USART_Init(USART1, &USART_InitStruct); 
	
	
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
	GPIO_InitTypeDef    GPIO_InitStructure;
	USART_InitTypeDef   USART_InitStructure;
	NVIC_InitTypeDef   NVIC_InitStructure;
	
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

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF; //���ܸ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; // ����ģʽ��������������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10|GPIO_Pin_11; // ��2��3������
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; // ��������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;// ���ŵ�������ٶ�
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	//ѡ�����ĸ��ù���
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource2,GPIO_AF_USART3); //GPIOB10 ����Ϊ USART3
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource3,GPIO_AF_USART3); //GPIOB11 ����Ϊ USART3	
	
	
	// 2.USART����
	//a.ʹ��USARTʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE); //ʹ�� USART3 ʱ��
	
	//b.USART��ʼ��	
	USART_InitStructure.USART_BaudRate = BaudRate; //����������
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; //��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx; //�շ�ģʽ	
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
	USART_Cmd(USART3, ENABLE); //ʹ�ܴ��� 3	
	
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

//�������У��ֵ��У��
u8 SUM_Check(u8 *dataBuf, u8 n)
{
	u8 data = 0, i;

	while(i<n)
	{
		if( i< (n-1) )
		data += dataBuf[i];//�ۼ�Length-1ǰ������		
	}
	return data;
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
	static unsigned char dataBuf[9]={0},i=0;//���徲̬�ֲ�����		
	if(USART_GetITStatus(USART2,USART_IT_RXNE)==SET)//�������ݴ����ж�
	{
		GPIO_ResetBits(GPIOF, GPIO_Pin_9);
		dataBuf[i++] = USART_ReceiveData(USART2);//��ȡ���յ�������
		if(dataBuf[0] != 0xff)//ÿ֡���ݵĿ�ͷ������0xff
		{
			i=0;
		}
		if(i == 9)//���ݽ��ճɹ�
		{
			i=0;
			if(SUM_Check(dataBuf,9) == dataBuf[8])//���У���Ƿ���ȷ
			{
				values = dataBuf[2]<<8 | dataBuf[3];
			}
			sprintf((char *)SendBuf, "the value is %d\r\n", values);
			USART_SendDatas(USART1,SendBuf,strlen((char *)SendBuf));
		}
		//...���ݴ���	
		

		USART_ClearITPendingBit(USART2,USART_IT_RXNE);//����жϱ�־λ
	}
}






//����3���жϴ�����
void USART3_IRQHandler(void)
{
	static unsigned char dataBuf[30]={0},i=0,k=0;//���徲̬�ֲ�����	
  static unsigned char data,length;	
	if(USART_GetITStatus(USART3,USART_IT_RXNE)==SET)//�������ݴ����ж�
	{
		GPIO_ResetBits(GPIOF, GPIO_Pin_9);
		dataBuf[i++] = USART_ReceiveData(USART3);//��ȡ���յ�������
		if(dataBuf[0] != 0x5A || dataBuf[1] != 0x5A)//ÿ֡���ݵĿ�ͷ������0x5A
		{
			i=0;
		}
		length = dataBuf[3];
		if(i == length+5)//���ݽ��ճɹ�
		{
			i=0;
			if(SUM_Check(dataBuf,length+4) == dataBuf[length+4])//���У���Ƿ���ȷ
			{
				data = dataBuf[2];
				if(data == 0x82) //�����������ǿ��
				{
					temp = dataBuf[4]<<24 | dataBuf[5]<<16 | dataBuf[6]<<8 | dataBuf[7];
					sprintf((char *)SendBuf, "the temp is %d\r\n", temp);
			    USART_SendDatas(USART1,SendBuf,strlen((char *)SendBuf));
				}
				
			}

		}
	
		USART_ClearITPendingBit(USART3,USART_IT_RXNE);//����жϱ�־λ
	}
}

