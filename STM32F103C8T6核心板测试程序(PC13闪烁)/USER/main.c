//=============================================================================
//文件名称：main.h
//功能概要：STM32F103C8核心检测
//版权所有：源地工作室www.vcc-gnd.com
//版权更新：2013-02-20
//调试方式：J-Link OB ARM SW方式 5MHz
//=============================================================================

//头文件
#include "stm32f10x.h"
#include "stm32f10x_exti.h"
#include "GPIOLIKE51.h"
#include "misc.h"
#include "main.h"
#include "exti.h"
#include "led.h"


void OUT_IO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE); 
    //=============================================================================
    //PB 6 7 89
    //=============================================================================          
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    


}

//pb 6789 按照二进制编码 6为最低位

void interrupt_handle(void)
{

    switch(TIFlag)
    {
        case 0:
        {
            //GPIO_SetBits(GPIOB, GPIO_Pin_6);
            GPIO_ResetBits(GPIOB, GPIO_Pin_6);
            GPIO_ResetBits(GPIOB, GPIO_Pin_7);
            GPIO_ResetBits(GPIOB, GPIO_Pin_8);
            GPIO_ResetBits(GPIOB, GPIO_Pin_9);
            


        }break;
        case 1:
        {
            GPIO_SetBits(GPIOB, GPIO_Pin_6);
            GPIO_ResetBits(GPIOB, GPIO_Pin_7);
            GPIO_ResetBits(GPIOB, GPIO_Pin_8);
            GPIO_ResetBits(GPIOB, GPIO_Pin_9);


        }break;
        
        case 2:
        {
            GPIO_ResetBits(GPIOB, GPIO_Pin_6);
            GPIO_SetBits(GPIOB, GPIO_Pin_7);
            GPIO_ResetBits(GPIOB, GPIO_Pin_8);
            GPIO_ResetBits(GPIOB, GPIO_Pin_9);


        }break;
        
        case 3:
        {
            GPIO_SetBits(GPIOB, GPIO_Pin_6);
            GPIO_SetBits(GPIOB, GPIO_Pin_7);
            GPIO_ResetBits(GPIOB, GPIO_Pin_8);
            GPIO_ResetBits(GPIOB, GPIO_Pin_9);


        }break;
        
        case 4:
        {
            GPIO_ResetBits(GPIOB, GPIO_Pin_6);
            GPIO_ResetBits(GPIOB, GPIO_Pin_7);
            GPIO_SetBits(GPIOB, GPIO_Pin_8);
            GPIO_ResetBits(GPIOB, GPIO_Pin_9);


        }break;
        case 5:
        {
            GPIO_SetBits(GPIOB, GPIO_Pin_6);
            GPIO_ResetBits(GPIOB, GPIO_Pin_7);
            GPIO_SetBits(GPIOB, GPIO_Pin_8);
            GPIO_ResetBits(GPIOB, GPIO_Pin_9);


        }break;
        
        case 6:
        {
            GPIO_ResetBits(GPIOB, GPIO_Pin_6);
            GPIO_SetBits(GPIOB, GPIO_Pin_7);
            GPIO_SetBits(GPIOB, GPIO_Pin_8);
            GPIO_ResetBits(GPIOB, GPIO_Pin_9);


        }break;
        case 7:
        {
            GPIO_SetBits(GPIOB, GPIO_Pin_6);
            GPIO_SetBits(GPIOB, GPIO_Pin_7);
            GPIO_SetBits(GPIOB, GPIO_Pin_8);
            GPIO_ResetBits(GPIOB, GPIO_Pin_9);


        }break;
        
        case 8:
        {
            GPIO_ResetBits(GPIOB, GPIO_Pin_6);
            GPIO_ResetBits(GPIOB, GPIO_Pin_7);
            GPIO_ResetBits(GPIOB, GPIO_Pin_8);
            GPIO_SetBits(GPIOB, GPIO_Pin_9);


        }break;

        case 9:
        {
            GPIO_SetBits(GPIOB, GPIO_Pin_6);
            GPIO_ResetBits(GPIOB, GPIO_Pin_7);
            GPIO_ResetBits(GPIOB, GPIO_Pin_8);
            GPIO_SetBits(GPIOB, GPIO_Pin_9);


        }break;
        
        default : break;
    }
}


void LED_Run(void)
{
    LED_ON;
    delay_ms(1000);
    LED_OFF;
    delay_ms(1000);
}

//=============================================================================
//文件名称：main
//功能概要：主函数
//参数说明：无
//函数返回：int
//=============================================================================
int main(void)
{
    OUT_IO_Init();
    LED_Init();
    EXTIX_Init();
    TIFlag =0;
    while (1)
    {
        
        LED_Run();
	    interrupt_handle();
    }
}




