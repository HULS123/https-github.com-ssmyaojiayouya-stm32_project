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
	
	// ����������Ϊ�ߵ�ƽ,���
    GPIO_SetBits(GPIOF, GPIO_Pin_9|GPIO_Pin_10);
    GPIO_SetBits(GPIOE, GPIO_Pin_13|GPIO_Pin_14);
	
}

int main(void)
{

    initLED();
	
    //��ʼ��ϵͳ��ʱ����1S�ں˴���1000���жϣ�˵���˶�ʱ1ms  ������1000�����Ƕ�ʱ1ms���������1�����Ƕ�ʱ1s��
	SysTick_Config(SystemCoreClock/1000);
	
	while(1)
	{

	}
	
}


//�δ�ʱ��ÿ��1ms������жϷ�����
void SysTick_Handler(void)
{
	//static��������ֻ��ʼ��һ��
	static uint32_t cnt=0;
	
	cnt++;
	
	//���� 100ms �Ķ�ʱ
	if(cnt == 100)
	{		
		//����
		GPIO_ResetBits(GPIOF,GPIO_Pin_9 | GPIO_Pin_10); 
        GPIO_ResetBits(GPIOE,GPIO_Pin_13 | GPIO_Pin_14); 
	}	
	
	//���� 200ms �Ķ�ʱ
	if(cnt == 200)
	{
		cnt=0;
		//����������Ϊ�ߵ�ƽ�����
		GPIO_SetBits(GPIOF,GPIO_Pin_9 | GPIO_Pin_10); 		
		GPIO_SetBits(GPIOE,GPIO_Pin_13 | GPIO_Pin_14); 	 
	}		
}











