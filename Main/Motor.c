#include"Motor.h"
#ifdef Motor_H


//电机初始化（定时器开启输出PWM）
void Motor_Initialization()
{
	HAL_TIM_PWM_Start(&Motor_Timer,Motor_Timer_Channel_1);
	HAL_TIM_PWM_Start(&Motor_Timer,Motor_Timer_Channel_2);
}

//电机驱动
void Motor_Driver(float MotorSpeed_1,float MotorSpeed_2)
{

	//硬件调整
	MotorSpeed_2=-MotorSpeed_2;

	//限制电机转速范围
	if(MotorSpeed_1>Motor_FullSpeed)
	{
		MotorSpeed_1=Motor_FullSpeed;
	}
	if(MotorSpeed_1<-Motor_FullSpeed)
	{
		MotorSpeed_1=-Motor_FullSpeed;
	}
	if(MotorSpeed_2>Motor_FullSpeed)
	{
		MotorSpeed_2=Motor_FullSpeed;
	}
	if(MotorSpeed_2<-Motor_FullSpeed)
	{
		MotorSpeed_2=-Motor_FullSpeed;
	}

	if(MotorSpeed_1>=0)
	{
		Motor_Ain1(1);
		Motor_Ain2(0);//设置正反转
		//设置速度
		__HAL_TIM_SetCompare(&Motor_Timer,Motor_Timer_Channel_1,(int16_t)(MotorSpeed_1/100*PWM_FullCounter));

	}
	if(MotorSpeed_2>=0)
	{
		Motor_Bin1(1);
		Motor_Bin2(0);//设置正反转
		//设置速度
		__HAL_TIM_SetCompare(&Motor_Timer,Motor_Timer_Channel_2,(int16_t)(MotorSpeed_2/100*PWM_FullCounter));
	}

	if(MotorSpeed_1<=0)
	{
		Motor_Ain1(0);
		Motor_Ain2(1);//设置正反转
		//设置速度
		__HAL_TIM_SetCompare(&Motor_Timer,Motor_Timer_Channel_1,(int16_t)(-MotorSpeed_1/100*PWM_FullCounter));
	}

	if(MotorSpeed_2<=0)
	{
		Motor_Bin1(0);
		Motor_Bin2(1);//设置正反转
		//设置速度
		__HAL_TIM_SetCompare(&Motor_Timer,Motor_Timer_Channel_2,(int16_t)(-MotorSpeed_2/100*PWM_FullCounter));
	}


	#if 0
	if(MotorSpeed_1)
	{
		USART_UART_Printf("MS1=%.2f\n",MotorSpeed_1);
	}

	if(MotorSpeed_2)
	{
		USART_UART_Printf("MS2=%.2f\n",MotorSpeed_2);
	}

	#endif//0
}

#endif//Motor_H
