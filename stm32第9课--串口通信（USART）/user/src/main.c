#include "stm32f4xx.h"
#include "led.h"
#include "delay.h"
//#include "usart.h"

/**********************************
*������: ����ʵ��
*		��1�����°������򴮿ڷ����ַ����������������ֽ���
    ��2��ͨ���������֣���MCU�������ݣ������ַ�'A'��LEDȫ�����������ַ�'B'��LEDȫϨ��
**********************************/


static GPIO_InitTypeDef  GPIO_InitStructure;

#define S0 	GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) //PA0 --- KEY0

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
	
	GPIO_SetBits(GPIOF,GPIO_Pin_9); 
	GPIO_SetBits(GPIOF,GPIO_Pin_10); 
	GPIO_SetBits(GPIOE,GPIO_Pin_13); 	
	GPIO_SetBits(GPIOE,GPIO_Pin_14); 	

}


unsigned char str[] = {"hello,are you ok?\r\n"};

int main()
{
    usart1_init(9600);
		LedInit();
	  KeyInit();
	  while(1)
		{
			if(S0 == 0) {
				 USART_SendDatas(USART1,str,sizeof(str));		
         delay_ms(1000);	
			}				
		}
}

