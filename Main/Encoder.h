#if 1
#ifndef Encoder_H
#define Encoder_H

#include"SimpleMain.h"

//设置如下：
//使能定时器为编码器模式
//选择编码器模式TI1和TI2


//解释所用的定时器
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;

//重定义编码器所用的定时器
#define Encoder1_Timer htim3
#define Encoder2_Timer htim4

//测得的速度（自带正负）
extern float Encoder1_Speed;
extern float Encoder2_Speed;

//编码器初始化（定时器接收方波）
void Encoder_Initialization();

//触发编码器检测
void Encoder_Detection();

//编码器数值显示
void Encoder_Printf();

#endif//Encoder_H
#endif//0

