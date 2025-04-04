#if 0
#ifndef SimpleOLED096s_SPI_H
#define SimpleOLED096s_SPI_H
#include"SimpleMain.h"



//配置如下
////////////////////////////////////////////////////////////////
//

//与SPIs一起使用
//需要将驱动重定义到SPIs


//
////////////////////////////////////////////////////////////////
//结束配置


//开始选择显示模式
////////////////////////////////////////////////////////////////
//


//选择工作模式：
//字符串模式，用于在特定位置显示字符串。
//#define OLED0961_SPI_CharacterStringMode
//Printf模式，用于模拟Printf命令行输出。
#define OLED0961_SPI_PrintfMode


//
////////////////////////////////////////////////////////////////
//结束选择显示模式


#ifdef SPIs_H



//开始重定义驱动
////////////////////////////////////////////////////////////////
//

//将驱动重定义到SPIs
#define OLED0961_SPI_SendData SPI1_SendData
#define OLED0961_SPI_Start SPI1_Start
#define OLED0961_SPI_End SPI1_End

//
////////////////////////////////////////////////////////////////
//结束重定义驱动



//该OLED屏幕使用非标准SPI协议，该引脚用来表示0指令/1数据选择
#define OLED0961_SPI_DC(x) HAL_GPIO_WritePin(OLED0961_SPI_DC_GPIO_Port,OLED0961_SPI_DC_Pin,(GPIO_PinState)(x))
//该OLED屏幕使用非标准SPI协议，该引脚用来表示0复位
#define OLED0961_SPI_RES(x) HAL_GPIO_WritePin(OLED0961_SPI_RES_GPIO_Port,OLED0961_SPI_RES_Pin,(GPIO_PinState)(x))



//屏幕初始化
void OLED0961_SPI_Initialization();
//屏幕睡眠（关闭）
void OLED0961_SPI_Sleep();
//屏幕唤醒
void OLED0961_SPI_Wake();
//全局刷新（快速）
void OLED0961_SPI_Refresh();




#ifdef OLED0961_SPI_CharacterStringMode
//固定位置显示字符串
//位置：行数：1-8；列数：1-128，字符串
void OLED0961_SPI_CharacterString(uint8_t OLED096_Axle_A,uint8_t OLED096_Axle_B,char*CharacterString,...);
#endif//OLED0961_SPI_CharacterStringMode



#ifdef OLED0961_SPI_PrintfMode
//OLED096显示输出
void OLED0961_SPI_Printf(const char*CharacterString,...);
#endif//OLED0961_SPI_PrintfMode



#endif//SPIs_H
#endif//OLED096s_SPI_H
#endif//0


