#if 1
#ifndef Encoders_H
#define Encoders_H

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


//选择编码器模式
////////////////////////////////////////////////////////////////
//

//全局变量模式
#define Encoder_GlobalMode
//参数传递模式
//#define Encoder_ParameterMode

//
////////////////////////////////////////////////////////////////
//结束选择电机驱动模式


//开始编码器配置
////////////////////////////////////////////////////////////////
//

//解释所用的定时器
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;

//重定义编码器所用的定时器
#define Encoder1_Timer htim1
#define Encoder2_Timer htim2
#define Encoder3_Timer htim3
#define Encoder4_Timer htim4

//编码器显示敏感阈值
//仅当编码器数据大于其时才会显示
#define Encoder1_SensitiveThreshold 1
#define Encoder2_SensitiveThreshold 1
#define Encoder3_SensitiveThreshold 1
#define Encoder4_SensitiveThreshold 1


//编码器1初始化（定时器接收方波）
void Encoder1_Initialization();
//编码器2初始化（定时器接收方波）
void Encoder2_Initialization();
//编码器3初始化（定时器接收方波）
void Encoder3_Initialization();
//编码器4初始化（定时器接收方波）
void Encoder4_Initialization();
//所有编码器初始化（定时器接收方波）
void Encoders_Initialization();


//如果是全局变量模式
#ifdef Encoder_GlobalMode
//测得的速度（自带正负）
extern float volatile Encoder1_Speed;
extern float volatile Encoder2_Speed;
extern float volatile Encoder3_Speed;
extern float volatile Encoder4_Speed;

//触发编码器1检测
void Encoder1_Detection();
//触发编码器2检测
void Encoder2_Detection();
//触发编码器3检测
void Encoder3_Detection();
//触发编码器4检测
void Encoder4_Detection();
//触发编码器检测
void Encoders_Detection();

//编码器1数值显示
void Encoder1_Printf();
//编码器2数值显示
void Encoder2_Printf();
//编码器3数值显示
void Encoder3_Printf();
//编码器4数值显示
void Encoder4_Printf();
//所有编码器数值显示
void Encoders_Printf();

#endif//Encoder_GlobalMode


//如果是参数传递模式
#ifdef Encoder_ParameterMode

//触发编码器1检测
void Encoder1_Detection(float*Encoder1_Speed);
//触发编码器2检测
void Encoder2_Detection(float*Encoder2_Speed);
//触发编码器3检测
void Encoder3_Detection(float*Encoder3_Speed);
//触发编码器4检测
void Encoder4_Detection(float*Encoder4_Speed);
//触发编码器检测
void Encoders_Detection(float*Encoder1_Speed,float*Encoder2_Speed,float*Encoder3_Speed,float*Encoder4_Speed);

//编码器1数值显示
void Encoder1_Printf(float Encoder1_Speed);
//编码器2数值显示
void Encoder2_Printf(float Encoder2_Speed);
//编码器3数值显示
void Encoder3_Printf(float Encoder3_Speed);
//编码器4数值显示
void Encoder4_Printf(float Encoder4_Speed);
//所有编码器数值显示
void Encoders_Printf(float Encoder1_Speed,float Encoder2_Speed,float Encoder3_Speed,float Encoder4_Speed);


#endif//Encoder_ParameterMode

//
////////////////////////////////////////////////////////////////
//结束编码器配置

#endif//Encoder_H
#endif//0

