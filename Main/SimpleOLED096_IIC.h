#if 1
#ifndef SimpleOLED096_IIC_H
#define SimpleOLED096_IIC_H
#include"SimpleMain.h"



//选择工作模式：
//OLED096_Mode_CharacterString：字符串模式，用于在特定位置显示字符串。
//OLED096_Mode_Printf：Printf模式，用于模拟Printf命令行输出。
//#define OLED096_Mode_CharacterString
#define OLED096_Mode_Printf



#if defined(IIC_Software)||defined(IIC_Hardware)
//重定义设备地址
#define OLED096_Address 0x78
//屏幕初始化
void OLED096_Initialization_IIC();

//全局刷新
void OLED096_Refresh_IIC();




#ifdef OLED096_Mode_CharacterString
//固定位置显示字符串
//位置：行数：1-8；列数：1-128，字符串
void OLED096_CharacterString_IIC(uint8_t OLED096_Axle_A,uint8_t OLED096_Axle_B,char*CharacterString,...);
#endif//OLED096_Mode_CharacterString



#ifdef OLED096_Mode_Printf
//OLED096显示输出
void OLED096_Printf_IIC(const char*CharacterString,...);
#endif//OLED096_Mode_Printf



#endif//defined(IIC_Software)||defined(IIC_Hardware)
#endif//OLED096_IIC_H
#endif//0


