#include "stm32f10x_gpio.h"
#include "led.h"




void LED_Init(void)
{    
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd( LED_RCC, ENABLE); 
    //=============================================================================
    //PC13
    //=============================================================================          
    GPIO_InitStructure.GPIO_Pin = LED_Pin;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
    GPIO_Init(LED_Port, &GPIO_InitStructure);

}





