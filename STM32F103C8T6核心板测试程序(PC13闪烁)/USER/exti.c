#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_exti.h"
#include "exti.h"
#include "led.h"
#include "function.h"


u8  TIFlag;
u32 count;





//�ⲿ�ж�5�������
void EXTIX_Init(void)
{

    EXTI_InitTypeDef EXTI_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);


    GPIO_InitStructure.GPIO_Pin =GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
    GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOE4
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE); //ʹ�ܸ��ù���ʱ��

    //GPIOB.5      �ж����Լ��жϳ�ʼ������  �½��ش��� //KEY0
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource1);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource2);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource3);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource4);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource5);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource6);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource7);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource8);
    EXTI_InitStructure.EXTI_Line=EXTI_Line0|EXTI_Line1|EXTI_Line2|EXTI_Line3|EXTI_Line4|EXTI_Line5|EXTI_Line6|EXTI_Line7|EXTI_Line8;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_InitStructure.EXTI_Mode =EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger =EXTI_Trigger_Falling;
    EXTI_Init(&EXTI_InitStructure);   //����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���

    //NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn|EXTI1_IRQn|EXTI2_IRQn|EXTI3_IRQn|EXTI4_IRQn|EXTI9_5_IRQn;            //ʹ�ܰ���KEY0���ڵ��ⲿ�ж�ͨ��
    NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;            //ʹ�ܰ���KEY0���ڵ��ⲿ�ж�ͨ��
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;    //��ռ���ȼ�2 
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;                   //�����ȼ�0 
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                             //ʹ���ⲿ�ж�ͨ��
    NVIC_Init(&NVIC_InitStructure);       //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���

    NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;            //ʹ�ܰ���KEY0���ڵ��ⲿ�ж�ͨ��
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;    //��ռ���ȼ�2 
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;                   //�����ȼ�0 
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                             //ʹ���ⲿ�ж�ͨ��
    NVIC_Init(&NVIC_InitStructure);       //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���
       
    NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;            //ʹ�ܰ���KEY0���ڵ��ⲿ�ж�ͨ��
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;    //��ռ���ȼ�2 
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;                   //�����ȼ�0 
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                             //ʹ���ⲿ�ж�ͨ��
    NVIC_Init(&NVIC_InitStructure);       //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���
        
    NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;            //ʹ�ܰ���KEY0���ڵ��ⲿ�ж�ͨ��
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;    //��ռ���ȼ�2 
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;                   //�����ȼ�0 
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                             //ʹ���ⲿ�ж�ͨ��
    NVIC_Init(&NVIC_InitStructure);       //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���

    NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;            //ʹ�ܰ���KEY0���ڵ��ⲿ�ж�ͨ��
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;    //��ռ���ȼ�2 
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;                   //�����ȼ�0 
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                             //ʹ���ⲿ�ж�ͨ��
    NVIC_Init(&NVIC_InitStructure);       //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���

    NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;            //ʹ�ܰ���KEY0���ڵ��ⲿ�ж�ͨ��
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;    //��ռ���ȼ�2 
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;                   //�����ȼ�0 
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                             //ʹ���ⲿ�ж�ͨ��
    NVIC_Init(&NVIC_InitStructure);       //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���


}



void EXTI0_IRQHandler()
{
    delay_ms(10);
    TIFlag =1;
    EXTI_ClearITPendingBit(EXTI_Line0);//����жϱ�־
}

void EXTI1_IRQHandler()
{
    delay_ms(10);
    TIFlag =2;
    EXTI_ClearITPendingBit(EXTI_Line1);//����жϱ�־

}
void EXTI2_IRQHandler()
{
    delay_ms(10);
    TIFlag =3;
	EXTI_ClearITPendingBit(EXTI_Line2);//����жϱ�־
}
void EXTI3_IRQHandler()
{
    delay_ms(10);
    TIFlag =4;
    EXTI_ClearITPendingBit(EXTI_Line3);//����жϱ�־

}
void EXTI4_IRQHandler()
{
    delay_ms(10);
    TIFlag =5;
    EXTI_ClearITPendingBit(EXTI_Line4);//����жϱ�־

}

//�ⲿ�ж�4�������
void EXTI9_5_IRQHandler(void)
{
    if(EXTI_GetITStatus(EXTI_Line5)!= RESET)  
    {  
        delay_ms(10);
        TIFlag =6;
        count++;
        if( count %2 == 0)
        {
            //LED_OFF;
        }else
        {
            //LED_ON;
        }

        EXTI_ClearITPendingBit(EXTI_Line5);

    }  

    if(EXTI_GetITStatus(EXTI_Line6)!= RESET)  
    {  
        delay_ms(10);
        TIFlag =7;
        count++;
        if( count %2 == 0)
        {
            //LED_OFF;
        }else
        {
            //LED_ON;
        }

        EXTI_ClearITPendingBit(EXTI_Line6);

    }

    if(EXTI_GetITStatus(EXTI_Line7)!= RESET)  
    {  
        delay_ms(10);
        TIFlag =8;
        count++;
        if( count %2 == 0)
        {
            //LED_OFF;
        }else
        {
            //LED_ON;
        }

        EXTI_ClearITPendingBit(EXTI_Line7);

    }   

    if(EXTI_GetITStatus(EXTI_Line8)!= RESET)  
    {  
        delay_ms(10);
        TIFlag =9;
        count++;
        if( count %2 == 0)
        {
            //LED_OFF;
        }else
        {
            //LED_ON;
        }

        EXTI_ClearITPendingBit(EXTI_Line8);

    }   

}





