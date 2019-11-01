#include "stm32f10x.h"
#include "function.h"

//=============================================================================
//文件名称：Delay
//功能概要：延时
//参数说明：nCount：延时长短
//函数返回：无
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


