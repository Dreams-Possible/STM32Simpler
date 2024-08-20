#include"ServoMotors.h"
#ifdef ServoMotors_H


//该驱动代码已经过时
//目前已不再进行维护


//舵机角度
float ServoMotor1_Angle=90;
float ServoMotor2_Angle=135;


//舵机1初始化（定时器开启输出PWM）
void ServoMotor1_Initialization()
{
	HAL_TIM_PWM_Start(&ServoMotors_Timer1,ServoMotor1_Timer);
}
//舵机2初始化（定时器开启输出PWM）
void ServoMotor2_Initialization()
{
	HAL_TIM_PWM_Start(&ServoMotors_Timer1,ServoMotor2_Timer);
}

//所有舵机初始化（定时器开启输出PWM）
void ServoMotors_Initialization()
{
	ServoMotor1_Initialization();
	ServoMotor2_Initialization();
}

//舵机1驱动（180度舵机）
void ServoMotor1_Driver(float ServoMotor1_Angle)
{
	//限制舵机转动范围
	if(ServoMotor1_Angle>ServoMotor1_FullAngle)
	{
		ServoMotor1_Angle=ServoMotor1_FullAngle;
	}
	if(ServoMotor1_Angle<-ServoMotor1_FullAngle)
	{
		ServoMotor1_Angle=-ServoMotor1_FullAngle;
	}
	//设置速度
	__HAL_TIM_SetCompare(&ServoMotor_Timer,ServoMotor_Timer_Channel_1,(uint16_t)(ServoMotor1_Angle/180*2000+500));

}

//舵机2驱动（270度舵机）
void ServoMotor2_Driver(float ServoMotor2_Angle)
{
	//限制舵机转动范围
	if(ServoMotor2_Angle>ServoMotor2_FullAngle)
	{
		ServoMotor2_Angle=ServoMotor2_FullAngle;
	}
	if(ServoMotor2_Angle<-ServoMotor2_FullAngle)
	{
		ServoMotor2_Angle=-ServoMotor2_FullAngle;
	}

	//设置速度
	__HAL_TIM_SetCompare(&ServoMotor_Timer,ServoMotor_Timer_Channel_2,(uint16_t)(ServoMotor2_Angle/270*2000+500));

}
#endif//ServoMotor_H
