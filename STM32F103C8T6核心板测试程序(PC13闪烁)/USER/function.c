#include "stm32f10x.h"
#include "function.h"

//=============================================================================
//�ļ����ƣ�Delay
//���ܸ�Ҫ����ʱ
//����˵����nCount����ʱ����
//�������أ���
//=============================================================================

void Delay(uint32_t nCount)
{
  for(; nCount != 0; nCount--);
}

void delay_us(unsigned int time)    
{
    unsigned int i;
    
    for (;time > 0;time--)
    {
        for (i = 3;i > 0;i--);    //??:i = 1145??16MHz?????
    }
        
}

void delay_ms(unsigned int time)
{
  
    unsigned int i;
    
    for (;time > 0;time--)
    {
        for (i = 7400;i > 0;i--);    //??:i = 1145??16MHz?????
    }
        
}


