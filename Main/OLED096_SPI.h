#if 0
#ifndef OLED096_SPI_H
#define OLED096_SPI_H
#include"SimpleMain.h"

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
//全局刷新（0x00为全黑，0xff为全白）
void OLED096_Refresh_SPI(uint8_t Display);
//设置对比度
void OLED096_ContrastRatio_SPI(uint8_t ContrastRatio);
//设置正反显，1正0反
void OLED096_DisplayMode_SPI(uint8_t DisplayMode);

//输出缓冲帧
void OLED096_PushFrame_SPI();

//帧数记录
void OLED096_FPSRecord_SPI();

#endif//OLED096_SPI_H
#endif//0
