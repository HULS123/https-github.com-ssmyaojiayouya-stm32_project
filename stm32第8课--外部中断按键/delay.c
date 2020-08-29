#include "myhead.h"

void delay_ms168(uint32_t n)
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


void delay_ms21(uint32_t n)
{
  while(n--) {
		SysTick->CTRL = 0; // �رն�ʱ��		
		SysTick->LOAD = (21000000/1000); //1ms
		SysTick->VAL = 0; // �����־λ
		SysTick->CTRL = 1; // ʹ�ܶ�ʱ����������ʼ�������Ĵ�����21M��
		
		while ((SysTick->CTRL & 0x00010000)==0);// �ȴ���ʱ���������
		SysTick->CTRL = 0; // �رն�ʱ��				
	}
	

}


//΢����ʱ
void delay_us21(uint32_t n)
{
  while(n--) {
		SysTick->CTRL = 0; // �رն�ʱ��		
		SysTick->LOAD = (21); //1ms
		SysTick->VAL = 0; // �����־λ
		SysTick->CTRL = 1; // ʹ�ܶ�ʱ����������ʼ�������Ĵ�����21M��
		
		while ((SysTick->CTRL & 0x00010000)==0);// �ȴ���ʱ���������
		SysTick->CTRL = 0; // �رն�ʱ��				
	}
	

}


