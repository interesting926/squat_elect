#ifndef __LED_H
#define __LED_H

#define LED_RCC RCC_APB2Periph_GPIOC
#define LED_Port GPIOC
#define LED_Pin GPIO_Pin_13

#define LED_ON GPIO_ResetBits(LED_Port,LED_Pin)
#define LED_OFF GPIO_SetBits(LED_Port,LED_Pin)
#define LED_TRRIGER 



void LED_Init(void);


#endif


