#if 1
#ifndef Motors_H
#define Motors_H

#include"SimpleMain.h"


//配置如下
////////////////////////////////////////////////////////////////
//

//配置定时器为
//预分频系数0，计数周期Motor_TimerFullCounter-1，频率均为0-Motor_TimerFullCounter
//分配对应PWM通道

//将下方的htime1更改为你实际使用的定时器即可


//配置任意引脚名称为
//Motor1_Ain1，Motor1_Ain2，Motor1_Bin1，Motor1_Bin2，以此类推
//推挽输出，默认低，拉低

//
////////////////////////////////////////////////////////////////
//结束配置



//选择电机驱动模式
////////////////////////////////////////////////////////////////
//

//全局变量模式
//#define Motor_GlobalMode
//参数传递模式
#define Motor_ParameterMode

//
////////////////////////////////////////////////////////////////
//结束选择电机驱动模式



//开始电机配置
////////////////////////////////////////////////////////////////
//

//重定义方向控制引脚
//推挽输出，默认低，拉低
#define Motor1_Ain1(x) HAL_GPIO_WritePin(Motor1_Ain1_GPIO_Port,Motor1_Ain1_Pin,(GPIO_PinState)(x))
#define Motor1_Ain2(x) HAL_GPIO_WritePin(Motor1_Ain2_GPIO_Port,Motor1_Ain2_Pin,(GPIO_PinState)(x))
#define Motor1_Bin1(x) HAL_GPIO_WritePin(Motor1_Bin1_GPIO_Port,Motor1_Bin1_Pin,(GPIO_PinState)(x))
#define Motor1_Bin2(x) HAL_GPIO_WritePin(Motor1_Bin2_GPIO_Port,Motor1_Bin2_Pin,(GPIO_PinState)(x))


#define Motor2_Ain1(x) HAL_GPIO_WritePin(Motor2_Ain1_GPIO_Port,Motor2_Ain1_Pin,(GPIO_PinState)(x))
#define Motor2_Ain2(x) HAL_GPIO_WritePin(Motor2_Ain2_GPIO_Port,Motor2_Ain2_Pin,(GPIO_PinState)(x))
#define Motor2_Bin1(x) HAL_GPIO_WritePin(Motor2_Bin1_GPIO_Port,Motor2_Bin1_Pin,(GPIO_PinState)(x))
#define Motor2_Bin2(x) HAL_GPIO_WritePin(Motor2_Bin2_GPIO_Port,Motor2_Bin2_Pin,(GPIO_PinState)(x))


//解释所使用的定时器（通常只需要一个定时器）
extern TIM_HandleTypeDef htim8;

//重定义速度控制所用的定时器和通道（通常需要一个定时器的两个通道）
//预分频系数0，计数周期Motor_TimerFullCounter-1，频率均为0-Motor_TimerFullCounter
#define Motors_Timer1 htim8
#define Motor1_Timer TIM_CHANNEL_1
#define Motor2_Timer TIM_CHANNEL_2
#define Motor3_Timer TIM_CHANNEL_3
#define Motor4_Timer TIM_CHANNEL_4

//全速PWM阈值
#define Motor_FullSpeed 100
#define Motor_TimerFullCounter 16800

//电机显示敏感阈值
//仅当电机数值大于其时才会显示
#define Motor1_SensitiveThreshold 1
#define Motor2_SensitiveThreshold 1
#define Motor3_SensitiveThreshold 1
#define Motor4_SensitiveThreshold 1






//电机1初始化（定时器开启输出PWM）
void Motor1_Initialization();
//电机1初始化（定时器开启输出PWM）
void Motor2_Initialization();
//电机1初始化（定时器开启输出PWM）
void Motor3_Initialization();
//电机1初始化（定时器开启输出PWM）
void Motor4_Initialization();
//所有电机初始化（定时器开启输出PWM）
void Motors_Initialization();


//如果是全局变量模式
#ifdef Motor_GlobalMode

//定义电机速度
extern float volatile Motor1_Speed;
extern float volatile Motor2_Speed;
extern float volatile Motor3_Speed;
extern float volatile Motor4_Speed;


//电机1驱动
void Motor1_Driver();
//电机2驱动
void Motor2_Driver();
//电机3驱动
void Motor3_Driver();
//电机4驱动
void Motor4_Driver();
//所有电机驱动
void Motors_Driver();


//电机1数值显示
void Motor1_Printf();
//电机2数值显示
void Motor2_Printf();
//电机3数值显示
void Motor3_Printf();
//电机4数值显示
void Motor4_Printf();
//所有电机数值显示
void Motors_Printf();

#endif//Motor_GlobalMode

//如果是参数传递模式
#ifdef Motor_ParameterMode

//电机1驱动
void Motor1_Driver(float Motor1_Speed);
//电机2驱动
void Motor2_Driver(float Motor2_Speed);
//电机3驱动
void Motor3_Driver(float Motor3_Speed);
//电机4驱动
void Motor4_Driver(float Motor4_Speed);
//所有电机驱动
void Motors_Driver(float Motor1_Speed,float Motor2_Speed,float Motor3_Speed,float Motor4_Speed);


//电机1数值显示
void Motor1_Printf(float Motor1_Speed);
//电机2数值显示
void Motor2_Printf(float Motor2_Speed);
//电机3数值显示
void Motor3_Printf(float Motor3_Speed);
//电机4数值显示
void Motor4_Printf(float Motor4_Speed);
//所有电机数值显示
void Motors_Printf(float Motor1_Speed,float Motor2_Speed,float Motor3_Speed,float Motor4_Speed);


#endif//Motor_ParameterMode

//
////////////////////////////////////////////////////////////////
//结束电机配置

#endif//Motor_H
#endif//0
