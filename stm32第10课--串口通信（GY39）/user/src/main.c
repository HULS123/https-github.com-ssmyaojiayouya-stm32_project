#include "stm32f4xx.h"
#include "bitband.h"
#include "delay.h"
/*
#include "led.h"

#include "usart.h"
#include "key.h"
#include "stdio.h"
#include "string.h"
*/
/**********************************
*������: ��������
*		ͨ������2������͵���������
*		ͨ������1��ȡ����Ũ��ֵ���͵�PC����ʾ
**********************************/

unsigned char Luxcmd[] = {0xA5,0x81,0x26}; //�����������ǿ��
unsigned char Tphhcmd[] = {0xA5,0x82,0x27}; //��������ѹ��ʪ��ָ��

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
	
	GPIO_SetBits(GPIOF, GPIO_Pin_9);
	GPIO_SetBits(GPIOF, GPIO_Pin_10);
	GPIO_SetBits(GPIOE, GPIO_Pin_13);
	GPIO_SetBits(GPIOE, GPIO_Pin_14);

}

int main()
{
		LedInit();
		
		//GPIO_ResetBits(GPIOF, GPIO_Pin_9);
		
		//usart1_init(9600);
		//usart2_init(9600);
		//usart3_init(9600);

		while(1)
		{	
				PFout(9) = 1; 
			USART_SendDatas(USART3,Luxcmd,sizeof(Luxcmd));
				delay_ms(500);
				PFout(9) = 0;
				delay_ms(500);

		}
}


