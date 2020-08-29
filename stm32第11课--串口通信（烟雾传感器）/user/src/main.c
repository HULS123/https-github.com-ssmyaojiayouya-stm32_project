#include "stm32f4xx.h"
#include "led.h"
#include "delay.h"
#include "usart.h"
#include "key.h"
#include "bitband.h"
#include "stdio.h"
#include "string.h"

/**********************************
*������: ��������
*		ͨ������2������͵���������
*		ͨ������1��ȡ����Ũ��ֵ���͵�PC����ʾ
**********************************/

unsigned char ATcmd[] = {0xFF,0x01,0x86,0x00,0x00,0x00,0x00,0x00,0x79};
int main()
{
	led_init();//��led.c�ļ���
	GPIO_SetBits(GPIOF, GPIO_Pin_9);
	GPIO_SetBits(GPIOF, GPIO_Pin_10);
	usart1_init(9600);
	usart2_init(9600);

	while(1)
	{	
		USART_SendDatas(USART2,ATcmd,sizeof(ATcmd));
		delay_ms(1000);

	}
}


