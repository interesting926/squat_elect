//=============================================================================
//�ļ����ƣ�main.h
//���ܸ�Ҫ��STM32F103C8���ļ��
//��Ȩ���У�Դ�ع�����www.vcc-gnd.com
//��Ȩ���£�2013-02-20
//���Է�ʽ��J-Link OB ARM SW��ʽ 5MHz
//=============================================================================

//ͷ�ļ�
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

//pb 6789 ���ն����Ʊ��� 6Ϊ���λ

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
//�ļ����ƣ�main
//���ܸ�Ҫ��������
//����˵������
//�������أ�int
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




