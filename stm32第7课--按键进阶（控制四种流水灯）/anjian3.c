#include "stm32f4xx.h"


static GPIO_InitTypeDef  GPIO_InitStructure;

//ͨ���⺯��ֱ�Ӷ�ȡIO�ĵ�ƽ
#define S0 	GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) //PA0 --- KEY0
#define S1 	GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_2) //PE2 --- KEY1
#define S2 	GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3) //PE3 --- KEY2
#define S3 	GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4) //PE4 --- KEY3

u8 flag1=0,flag2=0,flag3=0,flag4=0;


void delay_ms(uint32_t n)
{
  while(n--) {
		SysTick->CTRL = 0; // �رն�ʱ��
		SysTick->LOAD = 168000; // ���ö�ʱ��ʱ��1ms		
		SysTick->VAL = 0; // �����־λ
		SysTick->CTRL = 5; // ʹ�ܶ�ʱ����������ʼ������ͬʱʹ��ʱ��ԴΪϵͳʱ�ӣ�168M��
		
		while ((SysTick->CTRL & 0x00010000)==0);// �ȴ���ʱ���������
		SysTick->CTRL = 0; // �رն�ʱ��				
	}
	
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

}


void KeyScan()
{
   if(S0 == 0 && S1 == 1 && S2 == 1 && S3 == 1) { //key0����
	    delay_ms(5);//��ʱ����
	    if(S0 == 0 && S1 == 1 && S2 == 1 && S3 == 1)
			flag1 = 1;
   }
   
   if(S0 == 1 && S1 == 0 && S2 == 1 && S3 == 1) { //key1����
	    delay_ms(5); //��ʱ����
	    if(S0 == 1 && S1 == 0 && S2 == 1 && S3 == 1)
			flag2 = 1;
   }


   if(S0 == 1 && S1 == 1 && S2 == 0 && S3 == 1) { //key2����
	    delay_ms(5); //��ʱ����
	    if(S0 == 1 && S1 == 1 && S2 == 0 && S3 == 1)
			flag3 = 1;
   }


   if(S0 == 1 && S1 == 1 && S2 == 1 && S3 == 0) { //key3����
	    delay_ms(5); //��ʱ����
	    if(S0 == 1 && S1 == 1 && S2 == 1 && S3 == 0)
			flag4 = 1;
   }   
  
}

void liushuideng1()
{
		//����������Ϊ�͵�ƽ������
		GPIO_ResetBits(GPIOF,GPIO_Pin_9); 
		delay_ms(200);
		//����������Ϊ�ߵ�ƽ�����
		GPIO_SetBits(GPIOF,GPIO_Pin_9); 	
		delay_ms(200);
		
		GPIO_ResetBits(GPIOF,GPIO_Pin_10); 
		delay_ms(200);
		GPIO_SetBits(GPIOF,GPIO_Pin_10); 	
		delay_ms(200);
		
		GPIO_ResetBits(GPIOE,GPIO_Pin_13);
		delay_ms(200);
		GPIO_SetBits(GPIOE,GPIO_Pin_13); 	
		delay_ms(200);
		
		GPIO_ResetBits(GPIOE,GPIO_Pin_14);
		delay_ms(200);
		GPIO_SetBits(GPIOE,GPIO_Pin_14); 	
		delay_ms(200);
}

void liushuideng2()
{
		//����������Ϊ�ߵ�ƽ�����
		GPIO_SetBits(GPIOF,GPIO_Pin_9); 	
		delay_ms(200);
		//����������Ϊ�͵�ƽ������
		GPIO_ResetBits(GPIOF,GPIO_Pin_9); 
		delay_ms(200);
	

		GPIO_SetBits(GPIOF,GPIO_Pin_10); 	
		delay_ms(200);
		GPIO_ResetBits(GPIOF,GPIO_Pin_10); 
		delay_ms(200);

		GPIO_SetBits(GPIOE,GPIO_Pin_13); 	
		delay_ms(200);
		GPIO_ResetBits(GPIOE,GPIO_Pin_13);
		delay_ms(200);

		GPIO_SetBits(GPIOE,GPIO_Pin_14); 	
		delay_ms(200);
		GPIO_ResetBits(GPIOE,GPIO_Pin_14);
		delay_ms(200);
	
}

void two_liangmie()
{
		//����������Ϊ�͵�ƽ������
		GPIO_ResetBits(GPIOF,GPIO_Pin_9); 
		GPIO_ResetBits(GPIOF,GPIO_Pin_10);
	  delay_ms(200);
	
		//����������Ϊ�ߵ�ƽ�����
		GPIO_SetBits(GPIOF,GPIO_Pin_9); 			
		GPIO_SetBits(GPIOF,GPIO_Pin_10);
	  delay_ms(200);
	
	  GPIO_ResetBits(GPIOE,GPIO_Pin_13);
	  GPIO_ResetBits(GPIOE,GPIO_Pin_14);
	  delay_ms(200);

		GPIO_SetBits(GPIOE,GPIO_Pin_13); 			
		GPIO_SetBits(GPIOE,GPIO_Pin_14); 	
		delay_ms(200);
	
	
}

void all_liangmie()
{
		//����������Ϊ�͵�ƽ������
		GPIO_ResetBits(GPIOF,GPIO_Pin_9); 
		GPIO_ResetBits(GPIOF,GPIO_Pin_10); 
	  GPIO_ResetBits(GPIOE,GPIO_Pin_13);
	  GPIO_ResetBits(GPIOE,GPIO_Pin_14);
	  delay_ms(200);
	
		//����������Ϊ�ߵ�ƽ�����
		GPIO_SetBits(GPIOF,GPIO_Pin_9); 			
		GPIO_SetBits(GPIOF,GPIO_Pin_10); 					
		GPIO_SetBits(GPIOE,GPIO_Pin_13); 			
		GPIO_SetBits(GPIOE,GPIO_Pin_14); 	
		delay_ms(200);
}

void pattern()
{
	KeyScan();
	if(flag1) {
		
		while(flag1)  //key0  (��ˮ��1)
		{
			liushuideng1();
			
			KeyScan();
			if(flag2 || flag3 || flag4) { flag1=0; return;}
		}				
	}

	if(flag2) {
		//����������Ϊ�͵�ƽ������
		GPIO_ResetBits(GPIOF,GPIO_Pin_9); 
		GPIO_ResetBits(GPIOF,GPIO_Pin_10); 
	  GPIO_ResetBits(GPIOE,GPIO_Pin_13);
	  GPIO_ResetBits(GPIOE,GPIO_Pin_14);
		
		while(flag2)  //key1  (��ˮ��2)
		{
			liushuideng2();

			
			KeyScan();
			if(flag1 || flag3 || flag4) { flag2=0;}
		}				
	}	
	
	if(flag3) {
		//����������Ϊ�ߵ�ƽ�����
		GPIO_SetBits(GPIOF,GPIO_Pin_9); 			
		GPIO_SetBits(GPIOF,GPIO_Pin_10); 					
		GPIO_SetBits(GPIOE,GPIO_Pin_13); 			
		GPIO_SetBits(GPIOE,GPIO_Pin_14); 
		
		while(flag3)  //key2  (2������)
		{

			two_liangmie();
			
			KeyScan();
			if(flag1 || flag2 || flag4) { flag3=0;} 
		}				
	}	

	if(flag4) {
		//����������Ϊ�ߵ�ƽ�����
		GPIO_SetBits(GPIOF,GPIO_Pin_9); 			
		GPIO_SetBits(GPIOF,GPIO_Pin_10); 					
		GPIO_SetBits(GPIOE,GPIO_Pin_13); 			
		GPIO_SetBits(GPIOE,GPIO_Pin_14); 
		
		while(flag4)  //key3  (���е�����)
		{

			all_liangmie();
			
			KeyScan();
			if(flag1 || flag2 || flag3) { flag4=0;}
		}				
	}
	
}


int main(void)
{

	
  LedInit();
	KeyInit();
	
	//���״̬
	GPIO_SetBits(GPIOF,GPIO_Pin_9); 
	GPIO_SetBits(GPIOF,GPIO_Pin_10); 
	GPIO_SetBits(GPIOE,GPIO_Pin_13); 
	GPIO_SetBits(GPIOE,GPIO_Pin_14); 
	delay_ms(5);
	
	while(1)
	{	
     pattern(); 
	}
	
}
