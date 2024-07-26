#if 0
#ifndef ServoMotor_H
#define ServoMotor_H
#include"SimpleMain.h"


//解释所使用的定时器（通常只需要一个定时器）
extern TIM_HandleTypeDef htim2;

//重定义角度控制所用的定时器和通道（通常需要一个定时器的两个通道）
//预分频系数，计数周期，频率均为
#define ServoMotor_Timer htim2
#define ServoMotor_Timer_Channel_1 TIM_CHANNEL_1
#define ServoMotor_Timer_Channel_2 TIM_CHANNEL_2

//最大角度（180度）PWM阈值
#define ServoMotor1_FullAngle 180
#define ServoMotor2_FullAngle 270

//舵机角度
extern float ServoMotorAngle1;
extern float ServoMotorAngle2;

//电机初始化（定时器开启输出PWM）
void ServoMotor_Initialization();

//舵机驱动
//舵机1驱动（180度舵机）
void ServoMotor1_Driver(float ServoMotorAngle1);
//舵机2驱动（270度舵机）
void ServoMotor2_Driver(float ServoMotorAngle2);

#endif//ServoMotor_H
#endif//0

