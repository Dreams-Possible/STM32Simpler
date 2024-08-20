#if 1
#ifndef OLED096s_SPI_H
#define OLED096s_SPI_H
#include"SimpleMain.h"



//配置如下
////////////////////////////////////////////////////////////////
//

//与SPIs一起使用
//需要将驱动重定义到SPIs


//
////////////////////////////////////////////////////////////////
//结束配置

#ifdef SPIs_H

//开始重定义驱动
////////////////////////////////////////////////////////////////
//

//将驱动重定义到SPIs
#define OLED0961_SPI_SendData SPI1_SendData
#define OLED0961_SPI_Start SPI1_Start
#define OLED0961_SPI_End SPI1_End

//将驱动重定义到GUIs
#define OLED0961_SPI_Width OLED0961_GUI_Width
#define OLED0961_SPI_Length OLED0961_GUI_Length
#define OLED0961_SPI_Frame_Data OLED0961_GUI_Frame_Data
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
//全局刷新（0x00为全黑，0xff为全白）
void OLED0961_SPI_Refresh(uint8_t Display);
//设置对比度
void OLED0961_SPI_ContrastRatio(uint8_t ContrastRatio);
//设置正反显，1正0反
void OLED0961_SPI_DisplayMode(uint8_t DisplayMode);

//输出缓冲帧
void OLED0961_SPI_PushFrame();

#endif//SPIs_H
#endif//OLED096_SPI_H
#endif//0
