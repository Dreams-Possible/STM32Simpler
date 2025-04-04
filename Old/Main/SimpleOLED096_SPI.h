#if 0
#ifndef SimpleOLED096_SPI_H
#define SimpleOLED096_SPI_H
#include"SimpleMain.h"



//选择工作模式：
//OLED096_Mode_CharacterString：字符串模式，用于在特定位置显示字符串。
//OLED096_Mode_Printf：Printf模式，用于模拟Printf命令行输出。
#define OLED096_Mode_CharacterString
//#define OLED096_Mode_Printf


#if defined(SPI_Software)||defined(SPI_Hardware)

//该OLED屏幕使用非标准SPI协议，该引脚用来表示0指令/1数据选择
#define SPI_CD(x) HAL_GPIO_WritePin(SPI_CD_GPIO_Port,SPI_CD_Pin,(GPIO_PinState)(x))
//该OLED屏幕使用非标准SPI协议，该引脚用来表示0复位
#define SPI_RST(x) HAL_GPIO_WritePin(SPI_RST_GPIO_Port,SPI_RST_Pin,(GPIO_PinState)(x))

//写标志
#define OLED096_Command 0
#define OLED096_Data 1


//屏幕初始化
void OLED096_Initialization_SPI();
//屏幕睡眠（关闭）
void OLED096_Sleep_SPI();
//屏幕唤醒
void OLED096_Wake_SPI();
//全局刷新（快速）
void OLED096_Refresh_SPI();




#ifdef OLED096_Mode_CharacterString
//固定位置显示字符串
//位置：行数：1-8；列数：1-128，字符串
void OLED096_CharacterString(uint8_t OLED096_Axle_A,uint8_t OLED096_Axle_B,char*CharacterString,...);
#endif//OLED096_Mode_CharacterString



#ifdef OLED096_Mode_Printf
//OLED096显示输出
void OLED096_Printf(const char*CharacterString,...);
#endif//OLED096_Mode_Printf



#endif//defined(SPI_Software)||defined(SPI_Hardware)
#endif//OLED096_SPI_H
#endif//0


