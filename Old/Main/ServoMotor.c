#include"ServoMotor.h"
#ifdef ServoMotor_H

//舵机角度
float ServoMotorAngle1=90;
float ServoMotorAngle2=135;

//舵机初始化（定时器开启输出PWM）
void ServoMotor_Initialization()
{
	HAL_TIM_PWM_Start(&ServoMotor_Timer,ServoMotor_Timer_Channel_1);
	HAL_TIM_PWM_Start(&ServoMotor_Timer,ServoMotor_Timer_Channel_2);
}

//舵机1驱动（180度舵机）
void ServoMotor1_Driver(float ServoMotorAngle1)
{
	//限制舵机转动范围
	if(ServoMotorAngle1>ServoMotor1_FullAngle)
	{
		ServoMotorAngle1=ServoMotor1_FullAngle;
	}
	if(ServoMotorAngle1<-ServoMotor1_FullAngle)
	{
		ServoMotorAngle1=-ServoMotor1_FullAngle;
	}

	 //USART_Printf("PWM=%d\n",(uint16_t)(ServoMotorAngle1/180*2000+500));;

	//设置速度
	__HAL_TIM_SetCompare(&ServoMotor_Timer,ServoMotor_Timer_Channel_1,(uint16_t)(ServoMotorAngle1/180*2000+500));

}

//舵机2驱动（270度舵机）
void ServoMotor2_Driver(float ServoMotorAngle2)
{
	//限制舵机转动范围
	if(ServoMotorAngle2>ServoMotor2_FullAngle)
	{
		ServoMotorAngle2=ServoMotor2_FullAngle;
	}
	if(ServoMotorAngle2<-ServoMotor2_FullAngle)
	{
		ServoMotorAngle2=-ServoMotor2_FullAngle;
	}

	//设置速度
	__HAL_TIM_SetCompare(&ServoMotor_Timer,ServoMotor_Timer_Channel_2,(uint16_t)(ServoMotorAngle2/270*2000+500));

}
#endif//ServoMotor_H
