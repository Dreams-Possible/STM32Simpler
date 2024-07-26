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
#include<iconv.h>//包含格式转换的头文件
//引入驱动文件
#include"SimpleMain.h"
#include"SimpleIO.h"
#include"USART_UART.h"
#include"Timer.h"
#include"IIC.h"
#include"SimpleOLED096_IIC.h"
#include"24C02_IIC.h"
#include"OLED096_IIC.h"
#include"OLED096_SPI.h"
#include"SPI.h"
#include"OLED096_GUI.h"
#include"W25Qxx.h"
#include"SYN6288.h"
#include"USART_JDY31.h"
#include"Encoder.h"
#include"Motor.h"
#include"Controller.h"
#include"USART_OpenMV.h"
#include"MPU6050.h"
#include"MainSystem.h"
#include"SingTownAI.h"

//全局初始化
//所有的初始化函数放在这里
void MainInitization();

//可以在这里写Main函数
//效果等同于在main.c中写
void MainSimple();










//在这里重定义一些可选的简化项目

/*
typedef uint8_t u8;
typedef int8_t i8;

typedef uint16_t u16;
typedef int16_t i16;

typedef uint32_t u32;
typedef int32_t i32;
*/



#endif//SimpleMain_H
#endif//0
