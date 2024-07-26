#if 0
#ifndef OLED096_IIC_H
#define OLED096_IIC_H
#include"SimpleMain.h"

//重定义设备地址
#define OLED096_Address 0x78

//屏幕初始化
void OLED096_Initialization_IIC();
//屏幕睡眠（关闭）
void OLED096_Sleep_IIC();
//屏幕唤醒
void OLED096_Wake_IIC();
//全局刷新（0x00为全黑，0xff为全白）
void OLED096_Refresh_IIC(uint8_t Display);
//设置对比度
void OLED096_ContrastRatio_IIC(uint8_t ContrastRatio);
//设置正反显，1正0反
void OLED096_DisplayMode_IIC(uint8_t DisplayMode);

//输出缓冲帧
void OLED096_PushFrame_IIC();

//帧数记录
void OLED096_FPSRecord_IIC();


#endif//OLED096_IIC_H
#endif//0


