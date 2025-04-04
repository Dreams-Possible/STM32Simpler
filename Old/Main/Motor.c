#include"Motor.h"
#ifdef Motor_H



//开始定义电机部分
////////////////////////////////////////////////////////////////
//

//定义电机速度
float MotorSpeed_1=0;
float MotorSpeed_2=0;
float MotorSpeed_3=0;
float MotorSpeed_4=0;


//电机初始化（定时器开启输出PWM）
void Motor_Initialization()
{
	HAL_TIM_PWM_Start(&Motor_Timer,Motor_Timer_Channel_1);
	HAL_TIM_PWM_Start(&Motor_Timer,Motor_Timer_Channel_2);
	HAL_TIM_PWM_Start(&Motor_Timer,Motor_Timer_Channel_3);
	HAL_TIM_PWM_Start(&Motor_Timer,Motor_Timer_Channel_4);
}

//电机驱动
void Motor_Driver()
{

	//硬件调整
	MotorSpeed_1=-MotorSpeed_1;

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

	if(MotorSpeed_3>Motor_FullSpeed)
	{
		MotorSpeed_3=Motor_FullSpeed;
	}
	if(MotorSpeed_3<-Motor_FullSpeed)
	{
		MotorSpeed_3=-Motor_FullSpeed;
	}
	if(MotorSpeed_4>Motor_FullSpeed)
	{
		MotorSpeed_4=Motor_FullSpeed;
	}
	if(MotorSpeed_4<-Motor_FullSpeed)
	{
		MotorSpeed_4=-Motor_FullSpeed;
	}

	//控制电机速度
	if(MotorSpeed_1>=0)
	{
		Motor_Ain1_1(1);
		Motor_Ain2_1(0);//设置正反转
		//设置速度
		__HAL_TIM_SetCompare(&Motor_Timer,Motor_Timer_Channel_1,(int16_t)(MotorSpeed_1/100*PWM_FullCounter));

	}
	if(MotorSpeed_2>=0)
	{
		Motor_Bin1_1(1);
		Motor_Bin2_1(0);//设置正反转
		//设置速度
		__HAL_TIM_SetCompare(&Motor_Timer,Motor_Timer_Channel_2,(int16_t)(MotorSpeed_2/100*PWM_FullCounter));
	}

	if(MotorSpeed_1<=0)
	{
		Motor_Ain1_1(0);
		Motor_Ain2_1(1);//设置正反转
		//设置速度
		__HAL_TIM_SetCompare(&Motor_Timer,Motor_Timer_Channel_1,(int16_t)(-MotorSpeed_1/100*PWM_FullCounter));
	}

	if(MotorSpeed_2<=0)
	{
		Motor_Bin1_1(0);
		Motor_Bin2_1(1);//设置正反转
		//设置速度
		__HAL_TIM_SetCompare(&Motor_Timer,Motor_Timer_Channel_2,(int16_t)(-MotorSpeed_2/100*PWM_FullCounter));
	}






	if(MotorSpeed_3>=0)
	{
		Motor_Ain1_2(1);
		Motor_Ain2_2(0);//设置正反转
		//设置速度
		__HAL_TIM_SetCompare(&Motor_Timer,Motor_Timer_Channel_3,(int16_t)(MotorSpeed_3/100*PWM_FullCounter));

	}
	if(MotorSpeed_3>=0)
	{
		Motor_Bin1_2(1);
		Motor_Bin2_2(0);//设置正反转
		//设置速度
		__HAL_TIM_SetCompare(&Motor_Timer,Motor_Timer_Channel_4,(int16_t)(MotorSpeed_4/100*PWM_FullCounter));
	}

	if(MotorSpeed_4<=0)
	{
		Motor_Ain1_2(0);
		Motor_Ain2_2(1);//设置正反转
		//设置速度
		__HAL_TIM_SetCompare(&Motor_Timer,Motor_Timer_Channel_3,(int16_t)(-MotorSpeed_3/100*PWM_FullCounter));
	}

	if(MotorSpeed_4<=0)
	{
		Motor_Bin1_2(0);
		Motor_Bin2_2(1);//设置正反转
		//设置速度
		__HAL_TIM_SetCompare(&Motor_Timer,Motor_Timer_Channel_4,(int16_t)(-MotorSpeed_4/100*PWM_FullCounter));
	}


}







//电机数值显示
void Motor_Printf()
{
	if(fabs(MotorSpeed_1)>1)
	{
		USART_UART_Printf("MS1=%.2f\n",MotorSpeed_1);
	}

	if(fabs(MotorSpeed_1)>1)
	{
		USART_UART_Printf("MS2=%.2f\n",MotorSpeed_2);
	}

	if(fabs(MotorSpeed_3)>1)
	{
		USART_UART_Printf("MS1=%.2f\n",MotorSpeed_3);
	}

	if(fabs(MotorSpeed_4)>1)
	{
		USART_UART_Printf("MS2=%.2f\n",MotorSpeed_4);
	}
}


//
////////////////////////////////////////////////////////////////
//结束定义电机部分


#endif//Motor_H
