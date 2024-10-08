#if 1
#ifndef SimpleMain_H
#define SimpleMain_H
#include"SimpleMain.h"


//所有的头文件引入
//引入C库头文件
#include"main.h"
#include<stdio.h>//包含标准库头文件（输入输出）
#include<stdlib.h>//包含标准库头文件（常用函数）
#include<stdarg.h>//包含可变参数的头文件
#include<string.h>//包含内存复制的头文件
#include<math.h>//包含数学公式的头文件
#include<stdint.h>//包含格式定义的头文件
//#include<iconv.h>//包含格式转换的头文件
//引入驱动文件
#include"SimpleMain.h"

#include"LEDs.h"
#include"Keys.h"
#include"UARTs.h"
#include"Timers.h"
#include"IICs.h"
#include"SPIs.h"

#include"OLED096_Character.h"
#include"SimpleOLED096s_IIC.h"
#include"SimpleOLED096s_SPI.h"

#include"OLED096s_IIC.h"
#include"OLED096s_SPI.h"
#include"OLED096s_GUI.h"


#include"Encoders.h"
#include"Motors.h"

#include"MPU6050.h"

#include"W25Qx.h"

//全局初始化
//所有的初始化函数放在这里
void MainInitization();

//可以在这里写Main函数
//效果等同于在main.c中写
void MainSimple();

//初始化完成标志
extern uint8_t volatile Main_InitizationFlag;


//用于在Main.c中替换主函数
void Main_Simple();

//全局初始化
//所有的初始化函数放在这里
void Main_Initization();

//主函数
//可以在这里写Main中的While函数
void Main_While();





//在这里重定义一些可选的简化项目


typedef uint8_t u8;
typedef int8_t i8;

typedef uint16_t u16;
typedef int16_t i16;

typedef uint32_t u32;
typedef int32_t i32;



#endif//SimpleMain_H
#endif//0
