#ifndef __LED_H__
#define __LED_H__

#include "stm32f4xx.h"
#include "bitband.h"

void Led_Init(void);	//PF9,PF10,PE13,PE14
void Led_flash1(void);	//PF9����˸
void Led_flash2(void);	//PF10����˸
void Led_flash3(void);	//PE13����˸
void Led_flash4(void);	//PE14����˸
void Led_flash5(void);	//�ĵ���˸

#endif /*__LED_H__*/
