#if 1
#ifndef OLED096s_IIC_H
#define OLED096s_IIC_H
#include"SimpleMain.h"


//配置如下
////////////////////////////////////////////////////////////////
//

//与IICs一起使用
//需要将驱动重定义到IICs


//
////////////////////////////////////////////////////////////////
//结束配置

#ifdef IICs_H
//开始重定义驱动
////////////////////////////////////////////////////////////////
//

//将驱动重定义到IICs
#define OLED0961_IIC_SendData IIC1_SendData

//将驱动重定义到GUIs
#define OLED0961_IIC_Width OLED0961_GUI_Width
#define OLED0961_IIC_Length OLED0961_GUI_Length
#define OLED0961_IIC_Frame_Data OLED0961_GUI_Frame_Data

//
////////////////////////////////////////////////////////////////
//结束重定义驱动



//重定义设备地址
#define OLED0961_Address 0x78

//屏幕初始化
void OLED0961_IIC_Initialization();
//屏幕睡眠（关闭）
void OLED0961_IIC_Sleep();
//屏幕唤醒
void OLED0961_IIC_Wake();
//全局刷新（0x00为全黑，0xff为全白）
void OLED0961_IIC_Refresh(uint8_t Display);
//设置对比度
void OLED0961_IIC_ContrastRatio(uint8_t ContrastRatio);
//设置正反显，1正0反
void OLED0961_IIC_DisplayMode(uint8_t DisplayMode);

//输出缓冲帧
void OLED0961_IIC_PushFrame();


#endif//IICs_H
#endif//OLED096_IIC_H
#endif//0


