#ifndef __KEY_H__
#define __KEY_H__

#include "stm32f4xx.h"
//�ṹ���ʼ��
static GPIO_InitTypeDef GPIO_InitStructure;
static EXTI_InitTypeDef EXTI_InitStructure;
static NVIC_InitTypeDef NVIC_InitStructure;

void Key_Init(void);
void Extern_Init(void);

#endif /*__KEY_H__*/
