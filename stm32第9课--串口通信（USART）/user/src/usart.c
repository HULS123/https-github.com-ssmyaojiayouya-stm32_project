#include "usart.h"


void usart1_init(uint32_t BaudRate)
{
	GPIO_InitTypeDef    GPIO_InitStructure;
	USART_InitTypeDef   USART_InitStructure;
  NVIC_InitTypeDef   NVIC_InitStructure;
	
   /**  1.GPIO������	   **/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE); //ʹ�� GPIOA ʱ��

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF; //���ܸ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; // ����ģʽ��������������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10; // ��9��10������
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; // û�����������裨�������գ�
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;// ���ŵ�������ٶ�
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	//ѡ�����ĸ��ù���
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_USART1); //GPIOA9 ����Ϊ USART1
  GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_USART1); //GPIOA10 ����Ϊ USART1	
	
	
	/**  2.USART����	   **/
	//a.ʹ��USARTʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE); //ʹ�� USART1 ʱ��
	
	//b.USART��ʼ��	
	USART_InitStructure.USART_BaudRate = BaudRate; //����������
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; //��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx; //�շ�ģʽ	
	USART_InitStructure.USART_Parity = USART_Parity_No; //����żУ��λ
	USART_InitStructure.USART_StopBits = USART_StopBits_1; //һ��ֹͣλ
	USART_InitStructure.USART_WordLength = USART_WordLength_8b; //�ֳ�Ϊ 8 λ���ݸ�ʽ
	USART_Init(USART1, &USART_InitStructure);	
	

	/**  3.�ж�����	   **/
	//a.���ÿ�������Щ�¼������ж�
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE); //��������ж�(���������ݿ��������ж�)
	
	//b.Usart1 NVIC ����
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn; //���ô��� 1 �ж�ͨ��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //�ж�ͨ��ʹ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01; //��ռ���ȼ� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02; //�ӣ���Ӧ�����ȼ� 
  NVIC_Init(&NVIC_InitStructure); //����ָ���Ĳ�����ʼ�� VIC �Ĵ���


  /**  4.�򿪴���	   **/
	USART_Cmd(USART1, ENABLE); //ʹ�ܴ��� 1	
	
}

void USART_SendDatas(USART_TypeDef * USARTx,uint8_t *SendBuf,uint16_t len)
{
	uint16_t i;
	for(i=0;i<len;i++)
	{
		USART_SendData( USARTx,SendBuf[i]);
		while(USART_GetFlagStatus(USARTx,USART_FLAG_TXE)==RESET);//�ȴ��������
	}
}


//����1���жϴ�����
void USART1_IRQHandler(void)
{
	unsigned int data;		
	if(USART_GetITStatus(USART1,USART_IT_RXNE)==SET)//�������ݴ����ж�
	{
		data = USART_ReceiveData(USART1);//��ȡ���յ�������
		//...���ݴ���
/*		
		if(data == 'A')
		{
			 PFout(9) = 0;
			 PFout(10) = 0; 
			 PEout(13) = 0; 
			 PEout(14) = 0; 
		}
		
		if(data == 'B')
		{
			 PFout(9) = 1;
			 PFout(10) = 1; 
			 PEout(13) = 1; 
			 PEout(14) = 1; 
		}		
*/		
		if(data == 0x00) PFout(9) = 0; 
		if(data == 0xF0) PFout(9) = 1;
		
		if(data == 0x01) PFout(10) = 0; 
		if(data == 0xF1) PFout(10) = 1;
		
		if(data == 0x02) PEout(13) = 0; 
		if(data == 0xF2) PEout(13) = 1;
		
		if(data == 0x03) PEout(14) = 0; 
		if(data == 0xF3) PEout(14) = 1;

		USART_ClearITPendingBit(USART1,USART_IT_RXNE);//����жϱ�־λ
	}
}

