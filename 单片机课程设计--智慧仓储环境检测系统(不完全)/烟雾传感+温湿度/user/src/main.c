#include "stm32f4xx.h"
#include "delay.h"
#include "usart.h"
#include "beep.h"
#include "key.h"

/**********************************
*������: ��������
*		ͨ������2������͵���������
*		ͨ������1��ȡ����Ũ��ֵ���͵�PC����ʾ
**********************************/

unsigned char MQcmd[] = {0xFF,0x01,0x86,0x00,0x00,0x00,0x00,0x00,0x79};
unsigned char LIGHTcmd[] = {0xA5,0x51,0xF6};
unsigned char OTHERcmd[] = {0xA5,0x52,0xF7};
unsigned char MANU_mode[] = {"===================�ֶ�ģʽ==================\r\n"};
unsigned char AUTO_mode[] = {"===================�Զ�ģʽ==================\r\n"};
	
unsigned char flag = 0;
unsigned char mode = 0;		//0���Զ�ģʽ��1���ֶ�ģʽ
//unsigned char CLEARcmd[]  = {"\n\n\n\n\n\n\n\n\n"};

int main()
{
	Led_Init();
	Beep_Init();
	Key_Init();
	Extern_Init();
	usart1_init(9600);
	usart2_init(9600);
	usart3_init(9600);
	
	while(1)
	{	
		USART_SendDatas(USART2,MQcmd,sizeof(MQcmd));
		delay_ms(200);
		
		USART_SendDatas(USART3,LIGHTcmd,sizeof(LIGHTcmd));
		delay_ms(200);
		
		USART_SendDatas(USART3,OTHERcmd,sizeof(OTHERcmd));
		delay_ms(200);
		if(mode == 0)
		{
			Warming();
			USART_SendDatas(USART1,AUTO_mode,strlen((char *)AUTO_mode));
		}
		else
		{
			USART_SendDatas(USART1,MANU_mode,strlen((char *)MANU_mode));
		}

		delay_ms(2000);
		//USART_SendDatas(USART1,CLEARcmd,strlen((char *)CLEARcmd));
		//delay_ms(100);
	}
}

//����1:ģʽѡ��
void EXTI0_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line0) == SET)
	{
		mode ^= 1;
		//��ձ�־λ������CPU���Ѿ��������ж����󣬿��Դ�����һ���ж�
		delay_ms(500);
		EXTI_ClearITPendingBit(EXTI_Line0);
		
	}
}

//����2���ֶ�ģʽ����������
void EXTI2_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line2) == SET)
	{
		if(mode == 1)
		{		
			//��������ǹرյ�
			if(PFout(8) == 0)
			{
				//flag = 1;		//����˸�ź�
				PFout(8) = 1;	//�򿪾���
				PFout(9) = 0;	
				PFout(10) = 0;
				PEout(13) = 0;
				PEout(14) = 0;
			}
			else
			{
				//flag = 0;		//����˸�ź���0
				PFout(8) = 0;	//�رվ���
				PFout(9) = 1;	
				PFout(10) = 1;
				PEout(13) = 1;
				PEout(14) = 1;
			}
		}
		delay_ms(500);
		//��ձ�־λ������CPU���Ѿ��������ж����󣬿��Դ�����һ���ж�
		EXTI_ClearITPendingBit(EXTI_Line2);
		
	}
}
