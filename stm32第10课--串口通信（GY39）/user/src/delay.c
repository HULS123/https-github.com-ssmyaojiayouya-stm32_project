#include "delay.h"

void delay_ms(uint16_t nms)
{
	uint32_t tmp;
	int n,m,i,k=500;
	n = nms/500;
	m = nms%500;
	n = (m?n:n-1);
	
	for(i=0;i<n+1;i++)
	{
		if(m && i == n)
		{
			k = m;
		}
		SysTick->LOAD = SystemCoreClock/8/1000*k;//ʱ�����(SysTick->LOADΪ24bits)
		SysTick->VAL = 0x00;
		SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;//��શ�ʱ����ʼ����ʹ��
		do
		{
			tmp = SysTick->CTRL;
		}while((tmp&0x01) && !(tmp&(1<<16)));//�ȴ�ʱ�䵽��
		SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;//�رռ�����
		SysTick->VAL = 0x00;
	}
}

void delay_us(uint16_t nus)
{
	uint32_t tmp;
	SysTick->LOAD = SystemCoreClock/8/1000000*nus;//ʱ�����(SysTick->LOADΪ24bits)
	SysTick->VAL = 0x00;
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;//��શ�ʱ����ʼ����ʹ��
	do
	{
		tmp = SysTick->CTRL;
	}while((tmp&0x01) && !(tmp&(1<<16)));//�ȴ�ʱ�䵽��
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;//�رռ�����
	SysTick->VAL = 0x00;
}
