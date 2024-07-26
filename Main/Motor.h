#if 1
#ifndef Motor_H
#define Motor_H

#include"SimpleMain.h"



//重定义方向控制引脚
//推挽输出，默认低，拉低
#define Motor_Ain1(x) HAL_GPIO_WritePin(Motor_Ain1_GPIO_Port,Motor_Ain1_Pin,(GPIO_PinState)(x))
#define Motor_Ain2(x) HAL_GPIO_WritePin(Motor_Ain2_GPIO_Port,Motor_Ain2_Pin,(GPIO_PinState)(x))
#define Motor_Bin1(x) HAL_GPIO_WritePin(Motor_Bin1_GPIO_Port,Motor_Bin1_Pin,(GPIO_PinState)(x))
#define Motor_Bin2(x) HAL_GPIO_WritePin(Motor_Bin2_GPIO_Port,Motor_Bin2_Pin,(GPIO_PinState)(x))


//解释所使用的定时器（通常只需要一个定时器）
extern TIM_HandleTypeDef htim1;

//重定义速度控制所用的定时器和通道（通常需要一个定时器的两个通道）
//预分频系数0，计数周期7200-1，频率均为0-7200
#define Motor_Timer htim1
#define Motor_Timer_Channel_1 TIM_CHANNEL_1
#define Motor_Timer_Channel_2 TIM_CHANNEL_4

//全速PWM阈值
#define Motor_FullSpeed 100
#define PWM_FullCounter 7200

//电机初始化（定时器开启输出PWM）
void Motor_Initialization();

//电机驱动
void Motor_Driver(float MotorSpeed_1,float MotorSpeed_2);

#endif//Motor_H
#endif//0
