#include"Motors.h"
#ifdef Motors_H



//开始定义电机部分
////////////////////////////////////////////////////////////////
//

//定义电机速度
float Motor1_Speed=0;
float Motor2_Speed=0;
float Motor3_Speed=0;
float Motor4_Speed=0;


//电机1初始化（定时器开启输出PWM）
void Motor1_Initialization()
{
	HAL_TIM_PWM_Start(&Motors_Timer1,Motor1_Timer);
}
//电机2初始化（定时器开启输出PWM）
void Motor2_Initialization()
{
	HAL_TIM_PWM_Start(&Motors_Timer1,Motor2_Timer);
}
//电机3初始化（定时器开启输出PWM）
void Motor3_Initialization()
{
	HAL_TIM_PWM_Start(&Motors_Timer1,Motor3_Timer);
}
//电机4初始化（定时器开启输出PWM）
void Motor4_Initialization()
{
	HAL_TIM_PWM_Start(&Motors_Timer1,Motor4_Timer);
}

//所有电机初始化（定时器开启输出PWM）
void Motors_Initialization()
{
	Motor1_Initialization();
	Motor2_Initialization();
	Motor3_Initialization();
	Motor4_Initialization();
}


//电机1驱动
void Motor1_Driver()
{
	//限制电机转速范围
	if(Motor1_Speed>Motor_FullSpeed)
	{
		Motor1_Speed=Motor_FullSpeed;
	}
	if(Motor1_Speed<-Motor_FullSpeed)
	{
		Motor1_Speed=-Motor_FullSpeed;
	}

	//设置电机速度
	if(Motor1_Speed>=0)
	{
		Motor1_Ain1(1);
		Motor1_Ain2(0);//设置正反转
		//设置速度
		__HAL_TIM_SetCompare(&Motors_Timer1,Motor1_Timer,(int16_t)(Motor1_Speed/100*Motor_TimerFullCounter));
	}
	if(Motor1_Speed<=0)
	{
		Motor1_Ain1(0);
		Motor1_Ain2(1);//设置正反转
		//设置速度
		__HAL_TIM_SetCompare(&Motors_Timer1,Motor1_Timer,(int16_t)(-Motor1_Speed/100*Motor_TimerFullCounter));
	}

	//清除电机速度
	Motor1_Speed=0;
}

//电机2驱动
void Motor2_Driver()
{
	//限制电机转速范围
	if(Motor2_Speed>Motor_FullSpeed)
	{
		Motor2_Speed=Motor_FullSpeed;
	}
	if(Motor2_Speed<-Motor_FullSpeed)
	{
		Motor2_Speed=-Motor_FullSpeed;
	}

	//设置电机速度
	if(Motor2_Speed>=0)
	{
		Motor1_Bin1(1);
		Motor1_Bin2(0);//设置正反转
		//设置速度
		__HAL_TIM_SetCompare(&Motors_Timer1,Motor2_Timer,(int16_t)(Motor2_Speed/100*Motor_TimerFullCounter));
	}
	if(Motor2_Speed<=0)
	{
		Motor1_Bin1(0);
		Motor1_Bin2(1);//设置正反转
		//设置速度
		__HAL_TIM_SetCompare(&Motors_Timer1,Motor2_Timer,(int16_t)(-Motor2_Speed/100*Motor_TimerFullCounter));
	}

	//清除电机速度
	Motor2_Speed=0;
}

//电机3驱动
void Motor3_Driver()
{
	//限制电机转速范围
	if(Motor3_Speed>Motor_FullSpeed)
	{
		Motor3_Speed=Motor_FullSpeed;
	}
	if(Motor3_Speed<-Motor_FullSpeed)
	{
		Motor3_Speed=-Motor_FullSpeed;
	}

	//设置电机速度
	if(Motor3_Speed>=0)
	{
		Motor2_Ain1(1);
		Motor2_Ain2(0);//设置正反转
		//设置速度
		__HAL_TIM_SetCompare(&Motors_Timer1,Motor3_Timer,(int16_t)(Motor3_Speed/100*Motor_TimerFullCounter));

	}
	if(Motor3_Speed<=0)
	{
		Motor2_Bin1(0);
		Motor2_Bin2(1);//设置正反转
		//设置速度
		__HAL_TIM_SetCompare(&Motors_Timer1,Motor3_Timer,(int16_t)(-Motor3_Speed/100*Motor_TimerFullCounter));
	}

	//清除电机速度
	Motor3_Speed=0;
}



//电机4驱动
void Motor4_Driver()
{
	//限制电机转速范围
	if(Motor4_Speed>Motor_FullSpeed)
	{
		Motor4_Speed=Motor_FullSpeed;
	}
	if(Motor4_Speed<-Motor_FullSpeed)
	{
		Motor4_Speed=-Motor_FullSpeed;
	}

	//设置电机速度
	if(Motor4_Speed>=0)
	{
		Motor2_Ain1(1);
		Motor2_Ain2(0);//设置正反转
		//设置速度
		__HAL_TIM_SetCompare(&Motors_Timer1,Motor4_Timer,(int16_t)(Motor4_Speed/100*Motor_TimerFullCounter));
	}

	if(Motor4_Speed<=0)
	{
		Motor2_Bin1(0);
		Motor2_Bin2(1);//设置正反转
		//设置速度
		__HAL_TIM_SetCompare(&Motors_Timer1,Motor4_Timer,(int16_t)(-Motor4_Speed/100*Motor_TimerFullCounter));
	}

	//清除电机速度
	Motor4_Speed=0;
}


//所有电机驱动
void Motors_Driver()
{
	Motor1_Driver();
	Motor2_Driver();
	Motor3_Driver();
	Motor4_Driver();
}




//电机1数值显示
void Motor1_Printf()
{
	if(fabs(Motor1_Speed)>Motor1_SensitiveThreshold)
	{
		USART_UART_Printf("MS1=%.2f\n",Motor1_Speed);
	}
}
//电机2数值显示
void Motor2_Printf()
{
	if(fabs(Motor2_Speed)>Motor2_SensitiveThreshold)
	{
		USART_UART_Printf("MS2=%.2f\n",Motor2_Speed);
	}
}
//电机3数值显示
void Motor3_Printf()
{
	if(fabs(Motor3_Speed)>Motor3_SensitiveThreshold)
	{
		USART_UART_Printf("MS3=%.2f\n",Motor3_Speed);
	}
}
//电机4数值显示
void Motor4_Printf()
{
	if(fabs(Motor4_Speed)>Motor4_SensitiveThreshold)
	{
		USART_UART_Printf("MS4=%.2f\n",Motor4_Speed);
	}
}



//所有电机数值显示
void Motors_Printf()
{
	Motor1_Printf();
	Motor2_Printf();
	Motor3_Printf();
	Motor4_Printf();
}


//
////////////////////////////////////////////////////////////////
//结束定义电机部分


#endif//Motor_H
