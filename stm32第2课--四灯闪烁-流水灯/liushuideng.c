/*
   ��ˮ�ƴ���-------���ʱ���л����ܣ�֧��HSI��HSE��PLL
*/

/*
	//�л��� HSI �ڲ�������ʱ��
	RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
	RCC->CFGR |= RCC_CFGR_SW_HSI;

	//�л��� HSE �ⲿ������ʱ��
	RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
	RCC->CFGR |= RCC_CFGR_SW_HSE;

	//�л��� PLL ���໷�������Զ���Ƶ��
	RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
	RCC->CFGR |= RCC_CFGR_SW_PLL;

*/


#include "stm32f4xx.h"


static GPIO_InitTypeDef  GPIO_InitStructure;


void delay()
{
	uint32_t i = 0x1000000;
	
	while(i--);
	

}


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
	
		GPIO_SetBits(GPIOF,GPIO_Pin_9 | GPIO_Pin_10); 		
		GPIO_SetBits(GPIOE,GPIO_Pin_13 | GPIO_Pin_14); 	
}

int main(void)
{
    //��׼C���ȶ�����ʹ��
	uint32_t i = 0;
	
    LedInit();
	
	
	while(1)
	{	
		
		i++;
		if(i == 1) { 
			//�л��� HSE �ⲿ������ʱ��  8M 
			RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
			RCC->CFGR |= RCC_CFGR_SW_HSE;
		}
		
		
		else if(i == 2) {

			//�л��� HSI �ڲ�������ʱ��  16M
			RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
			RCC->CFGR |= RCC_CFGR_SW_HSI;						
		}
		
		
		else if(i == 3) {
			//�л��� PLL ���໷�������Զ���Ƶ��  168M
			RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
			RCC->CFGR |= RCC_CFGR_SW_PLL;
			
			//��ձ�־λ
			i = 0;
		}
		
		
		
		
		
		//����������Ϊ�͵�ƽ������
		GPIO_ResetBits(GPIOF,GPIO_Pin_9); 
		delay();
		//����������Ϊ�ߵ�ƽ�����
		GPIO_SetBits(GPIOF,GPIO_Pin_9); 	
		delay();
		
		GPIO_ResetBits(GPIOF,GPIO_Pin_10); 
		delay();
		GPIO_SetBits(GPIOF,GPIO_Pin_10); 	
		delay();
		
		GPIO_ResetBits(GPIOE,GPIO_Pin_13);
    delay();		
		GPIO_SetBits(GPIOE,GPIO_Pin_13); 	
		delay();
		
	  GPIO_ResetBits(GPIOE,GPIO_Pin_14);
    delay();		
		GPIO_SetBits(GPIOE,GPIO_Pin_14); 	
		delay();
		
	}
	
}
