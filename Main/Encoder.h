#if 1
#ifndef Encoder_H
#define Encoder_H

#include"SimpleMain.h"


//配置如下
////////////////////////////////////////////////////////////////
//

//设置如下：
//使能定时器为编码器模式
//选择编码器模式TI1和TI2
//其余默认即可

//将下方的定时器Timerx更改为你实际使用的定时器即可

//
////////////////////////////////////////////////////////////////
//结束配置



//开始编码器配置
////////////////////////////////////////////////////////////////
//

//解释所用的定时器
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;

//重定义编码器所用的定时器
#define Encoder_Timer_1 htim1
#define Encoder_Timer_2 htim2
#define Encoder_Timer_3 htim3
#define Encoder_Timer_4 htim4

//测得的速度（自带正负）
extern float Encoder_Speed_1;
extern float Encoder_Speed_2;
extern float Encoder_Speed_3;
extern float Encoder_Speed_4;

//编码器初始化（定时器接收方波）
void Encoder_Initialization();

//触发编码器检测
void Encoder_Detection();

//编码器数值显示
void Encoder_Printf();



//
////////////////////////////////////////////////////////////////
//结束编码器配置

#endif//Encoder_H
#endif//0

