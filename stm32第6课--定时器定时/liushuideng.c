#include "myhead.h"

void liushuideng1()
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
		 delay_ms21(500);
		 *PF9_BitBand ^= 1; //λ��ʵ�ַ�ת����
		 delay_ms21(500);
		
		 *PF10_BitBand ^= 1; //λ��ʵ�ַ�ת����
		 delay_ms21(500);
		 *PF10_BitBand ^= 1; //λ��ʵ�ַ�ת����
		 delay_ms21(500);
		
		 *PE13_BitBand ^= 1; //λ��ʵ�ַ�ת����
		 delay_ms21(500);
		 *PE13_BitBand ^= 1; //λ��ʵ�ַ�ת����
		 delay_ms21(500);		
		
		 *PE14_BitBand ^= 1; //λ��ʵ�ַ�ת����
		 delay_ms21(500);
		 *PE14_BitBand ^= 1; //λ��ʵ�ַ�ת����
		 delay_ms21(500);
}



void liushuideng2()
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