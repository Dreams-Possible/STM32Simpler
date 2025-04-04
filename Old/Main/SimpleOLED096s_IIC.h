#if 0
#ifndef SimpleOLED096s_IIC_H
#define SimpleOLED096s_IIC_H
#include"SimpleMain.h"



//配置如下
////////////////////////////////////////////////////////////////
//

//与IICs一起使用
//需要将驱动重定义到IICs


//
////////////////////////////////////////////////////////////////
//结束配置


//开始选择显示模式
////////////////////////////////////////////////////////////////
//


//选择工作模式：
//字符串模式，用于在特定位置显示字符串。
//#define OLED0961_IIC_CharacterStringMode
//Printf模式，用于模拟Printf命令行输出。
#define OLED0961_IIC_PrintfMode


//
////////////////////////////////////////////////////////////////
//结束选择显示模式

#ifdef IICs_H


//开始重定义驱动
////////////////////////////////////////////////////////////////
//

//将驱动重定义到IICs
#define OLED0961_IIC_SendData IIC1_SendData

//
////////////////////////////////////////////////////////////////
//结束重定义驱动




//重定义设备地址
#define OLED0961_Address 0x78
//屏幕初始化
void OLED0961_IIC_Initialization();

//全局刷新
void OLED0961_IIC_Refresh();




#ifdef OLED0961_IIC_CharacterStringMode
//固定位置显示字符串
//位置：行数：1-8；列数：1-128，字符串
void OLED0961_IIC_CharacterString(uint8_t OLED096_Axle_A,uint8_t OLED096_Axle_B,char*CharacterString,...);
#endif//OLED0961_IIC_CharacterStringMode



#ifdef OLED0961_IIC_PrintfMode
//OLED096显示输出
void OLED0961_IIC_Printf(const char*CharacterString,...);
#endif//OLED0961_IIC_PrintfMode



#endif//IICs_H
#endif//OLED096s_IIC_H
#endif//0


