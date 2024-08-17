#if 1
#ifndef Motor_H
#define Motor_H

#include"SimpleMain.h"


//配置如下
////////////////////////////////////////////////////////////////
//

//配置定时器为
//预分频系数0，计数周期7200-1，频率均为0-7200
//分配对应PWM通道

//将下方的htime1更改为你实际使用的定时器即可


//配置任意引脚名称为
//Motor_Ain1_1，Motor_Ain2_1，Motor_Bin1_1，Motor_Bin2_1，以此类推
//推挽输出，默认低，拉低

//
////////////////////////////////////////////////////////////////
//结束配置





//开始电机配置
////////////////////////////////////////////////////////////////
//

//重定义方向控制引脚
//推挽输出，默认低，拉低
#define Motor_Ain1_1(x) HAL_GPIO_WritePin(Motor_Ain1_1_GPIO_Port,Motor_Ain1_1_Pin,(GPIO_PinState)(x))
#define Motor_Ain2_1(x) HAL_GPIO_WritePin(Motor_Ain2_1_GPIO_Port,Motor_Ain2_1_Pin,(GPIO_PinState)(x))
#define Motor_Bin1_1(x) HAL_GPIO_WritePin(Motor_Bin1_1_GPIO_Port,Motor_Bin1_1_Pin,(GPIO_PinState)(x))
#define Motor_Bin2_1(x) HAL_GPIO_WritePin(Motor_Bin2_1_GPIO_Port,Motor_Bin2_1_Pin,(GPIO_PinState)(x))


#define Motor_Ain1_2(x) HAL_GPIO_WritePin(Motor_Ain1_2_GPIO_Port,Motor_Ain1_2_Pin,(GPIO_PinState)(x))
#define Motor_Ain2_2(x) HAL_GPIO_WritePin(Motor_Ain2_2_GPIO_Port,Motor_Ain2_2_Pin,(GPIO_PinState)(x))
#define Motor_Bin1_2(x) HAL_GPIO_WritePin(Motor_Bin1_2_GPIO_Port,Motor_Bin1_2_Pin,(GPIO_PinState)(x))
#define Motor_Bin2_2(x) HAL_GPIO_WritePin(Motor_Bin2_2_GPIO_Port,Motor_Bin2_2_Pin,(GPIO_PinState)(x))


//解释所使用的定时器（通常只需要一个定时器）
extern TIM_HandleTypeDef htim8;

//重定义速度控制所用的定时器和通道（通常需要一个定时器的两个通道）
//预分频系数0，计数周期7200-1，频率均为0-7200
#define Motor_Timer htim8
#define Motor_Timer_Channel_1 TIM_CHANNEL_1
#define Motor_Timer_Channel_2 TIM_CHANNEL_2
#define Motor_Timer_Channel_3 TIM_CHANNEL_3
#define Motor_Timer_Channel_4 TIM_CHANNEL_4

//全速PWM阈值
#define Motor_FullSpeed 100
#define PWM_FullCounter 16800




//定义电机速度
extern float MotorSpeed_1;
extern float MotorSpeed_2;
extern float MotorSpeed_3;
extern float MotorSpeed_4;




//电机初始化（定时器开启输出PWM）
void Motor_Initialization();

//电机驱动
void Motor_Driver();


//
////////////////////////////////////////////////////////////////
//结束电机配置

#endif//Motor_H
#endif//0
