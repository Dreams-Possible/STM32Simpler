#if 1
#ifndef ExternalInterrup_H
#define ExternalInterrup_H

#include"SimpleMain.h"

//重定义MPU6050外部中断引脚
//下降沿中断，默认拉高
#define MPU6050_Interrupt MPU6050_Interrupt_Pin

//重定义Hcsr0外部中断引脚
//#define HCSR04_Interrupt GPIO_PIN_5

#endif//ExternalInterrup_H
#endif//0
