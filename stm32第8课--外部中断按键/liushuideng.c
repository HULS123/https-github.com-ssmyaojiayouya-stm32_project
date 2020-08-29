#include "myhead.h"

void liushuideng1(void)
{
	
	//��ȡGPIO��ODR�Ĵ�����ַ  
	uint32_t PF_ODR = GPIOF_BASE + 0x14;
	
	uint32_t PE_ODR = GPIOE_BASE + 0x14;
	
	//ת��λ������ַ�����ڷ������PF9����
	uint32_t *PF9_BitBand = (uint32_t *)(0x42000000+(PF_ODR - 0x40000000)*8*4 + 9*4);
	uint32_t *PF10_BitBand = (uint32_t *)(0x42000000+(PF_ODR - 0x40000000)*8*4 + 10*4);
	uint32_t *PE13_BitBand = (uint32_t *)(0x42000000+(PE_ODR - 0x40000000)*8*4 + 13*4);
	uint32_t *PE14_BitBand = (uint32_t *)(0x42000000+(PE_ODR - 0x40000000)*8*4 + 14*4);
	
	   *PF9_BitBand ^= 1; //λ��ʵ�ַ�ת����
		 delay_ms21(100);
		 *PF9_BitBand ^= 1; //λ��ʵ�ַ�ת����
		 delay_ms21(100);
		
		 *PF10_BitBand ^= 1; //λ��ʵ�ַ�ת����
		 delay_ms21(100);
		 *PF10_BitBand ^= 1; //λ��ʵ�ַ�ת����
		 delay_ms21(100);
		
		 *PE13_BitBand ^= 1; //λ��ʵ�ַ�ת����
		 delay_ms21(100);
		 *PE13_BitBand ^= 1; //λ��ʵ�ַ�ת����
		 delay_ms21(100);		
		
		 *PE14_BitBand ^= 1; //λ��ʵ�ַ�ת����
		 delay_ms21(100);
		 *PE14_BitBand ^= 1; //λ��ʵ�ַ�ת����
		 delay_ms21(100);
}



void liushuideng2(void)
{

		//led�ƽ�������

	   PFout(9) = 0; 
		 delay_ms21(100);
		 PFout(9) = 1; 
		 
		
	   PFout(10) = 0; 
		 delay_ms21(100);
		 PFout(10) = 1; 
		 
		
	   PEout(13) = 0; 
		 delay_ms21(100);
		 PEout(13) = 1; 
		 
		
	   PEout(14) = 0; 
		 delay_ms21(100);
		 PEout(14) = 1; 
		 
}

void two_liangmie(void)
{
		//����������Ϊ�͵�ƽ������
		GPIO_ResetBits(GPIOF,GPIO_Pin_9); 
		GPIO_ResetBits(GPIOF,GPIO_Pin_10);
	  delay_ms21(100);
	
		//����������Ϊ�ߵ�ƽ�����
		GPIO_SetBits(GPIOF,GPIO_Pin_9); 			
		GPIO_SetBits(GPIOF,GPIO_Pin_10);
	  delay_ms21(100);
	
		GPIO_ResetBits(GPIOE,GPIO_Pin_13);
		GPIO_ResetBits(GPIOE,GPIO_Pin_14);
	  delay_ms21(100);

		GPIO_SetBits(GPIOE,GPIO_Pin_13); 			
		GPIO_SetBits(GPIOE,GPIO_Pin_14); 	
		delay_ms21(100);
	
	
}

void all_liangmie(void)
{
		//����������Ϊ�͵�ƽ������
		GPIO_ResetBits(GPIOF,GPIO_Pin_9); 
		GPIO_ResetBits(GPIOF,GPIO_Pin_10); 
	  GPIO_ResetBits(GPIOE,GPIO_Pin_13);
	  GPIO_ResetBits(GPIOE,GPIO_Pin_14);
	  delay_ms21(100);
	
		//����������Ϊ�ߵ�ƽ�����
		GPIO_SetBits(GPIOF,GPIO_Pin_9); 			
		GPIO_SetBits(GPIOF,GPIO_Pin_10); 					
		GPIO_SetBits(GPIOE,GPIO_Pin_13); 			
		GPIO_SetBits(GPIOE,GPIO_Pin_14); 	
		delay_ms21(100);
}


