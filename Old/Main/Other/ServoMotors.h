#if 0
#ifndef ServoMotors_H
#define ServoMotors_H
#include"SimpleMain.h"


//该驱动代码已经过时
//目前已不再进行维护


//配置如下
////////////////////////////////////////////////////////////////
//

//通常需要一个定时器的两个通道
//预分频系数72-1，计数周期20000-1，频率均为50

//
////////////////////////////////////////////////////////////////
//结束配置


//解释所使用的定时器（通常只需要一个定时器）
extern TIM_HandleTypeDef htim2;

//重定义角度控制所用的定时器和通道（通常需要一个定时器的两个通道）
//预分频系数72-1，计数周期20000-1，频率均为50
#define ServoMotors_Timer1 htim2
#define ServoMotor1_Timer TIM_CHANNEL_1
#define ServoMotor2_Timer TIM_CHANNEL_2

//最大角度（180度）PWM阈值
#define ServoMotor1_FullAngle 180
#define ServoMotor2_FullAngle 270

//舵机角度
extern float ServoMotor1_Angle;
extern float ServoMotor2_Angle;

//电机1初始化（定时器开启输出PWM）
void ServoMotor1_Initialization();
//电机2初始化（定时器开启输出PWM）
void ServoMotor2_Initialization();
//所有电机初始化（定时器开启输出PWM）
void ServoMotors_Initialization();

//舵机驱动
//舵机1驱动（180度舵机）
void ServoMotor1_Driver(float ServoMotorAngle1);
//舵机2驱动（270度舵机）
void ServoMotor2_Driver(float ServoMotorAngle2);

#endif//ServoMotor_H
#endif//0

