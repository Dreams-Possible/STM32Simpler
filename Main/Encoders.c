#include"Encoders.h"
#ifdef Encoders_H



//开始定义串编码器部分
////////////////////////////////////////////////////////////////
//

//测得的速度（自带正负）
float Encoder1_Speed=0;
float Encoder2_Speed=0;
float Encoder3_Speed=0;
float Encoder4_Speed=0;



//编码器1初始化（定时器接收方波）
void Encoder1_Initialization()
{
	HAL_TIM_Encoder_Start(&Encoder1_Timer,TIM_CHANNEL_ALL);
}

//编码器2初始化（定时器接收方波）
void Encoder2_Initialization()
{
	HAL_TIM_Encoder_Start(&Encoder2_Timer,TIM_CHANNEL_ALL);
}

//编码器3初始化（定时器接收方波）
void Encoder3_Initialization()
{
	HAL_TIM_Encoder_Start(&Encoder3_Timer,TIM_CHANNEL_ALL);
}

//编码器4初始化（定时器接收方波）
void Encoder4_Initialization()
{
	HAL_TIM_Encoder_Start(&Encoder4_Timer,TIM_CHANNEL_ALL);
}



//所有编码器初始化（定时器接收方波）
void Encoders_Initialization()
{
	Encoder1_Initialization();
	Encoder2_Initialization();
	Encoder3_Initialization();
	Encoder4_Initialization();
}




//触发编码器1检测
void Encoder1_Detection()
{
	//检测
	int16_t Encoder1_Speed_New=(int16_t)__HAL_TIM_GetCounter(&Encoder1_Timer);
	//滤波
	Encoder1_Speed=0.3*Encoder1_Speed+0.7*Encoder1_Speed_New;
	//重置
	__HAL_TIM_SetCounter(&Encoder1_Timer,0);
}

//触发编码器2检测
void Encoder2_Detection()
{
	//检测
	int16_t Encoder2_Speed_New=(int16_t)__HAL_TIM_GetCounter(&Encoder2_Timer);
	//滤波
	Encoder2_Speed=0.3*Encoder2_Speed+0.7*Encoder2_Speed_New;
	//重置
	__HAL_TIM_SetCounter(&Encoder2_Timer,0);
}


//触发编码器3检测
void Encoder3_Detection()
{
	//检测
	int16_t Encoder3_Speed_New=(int16_t)__HAL_TIM_GetCounter(&Encoder3_Timer);
	//滤波
	Encoder3_Speed=0.3*Encoder3_Speed+0.7*Encoder3_Speed_New;
	//重置
	__HAL_TIM_SetCounter(&Encoder3_Timer,0);
}

//触发编码器4检测
void Encoder4_Detection()
{
	//检测
	int16_t Encoder4_Speed_New=(int16_t)__HAL_TIM_GetCounter(&Encoder4_Timer);
	//滤波
	Encoder4_Speed=0.3*Encoder4_Speed+0.7*Encoder4_Speed_New;
	//重置
	__HAL_TIM_SetCounter(&Encoder4_Timer,0);
}




//触发所有编码器检测
void Encoders_Detection()
{
	Encoder1_Detection();
	Encoder2_Detection();
	Encoder3_Detection();
	Encoder4_Detection();
}



//编码器1数值显示
void Encoder1_Printf()
{
	if(fabs(Encoder1_Speed)>Encoder1_SensitiveThreshold)
	{
		USART_UART_Printf("ES1=%.2f\n",Encoder1_Speed);
	}

}

//编码器2数值显示
void Encoder2_Printf()
{
	if(fabs(Encoder2_Speed)>Encoder2_SensitiveThreshold)
	{
		USART_UART_Printf("ES2=%.2f\n",Encoder2_Speed);
	}

}

//编码器3数值显示
void Encoder3_Printf()
{
	if(fabs(Encoder3_Speed)>Encoder3_SensitiveThreshold)
	{
		USART_UART_Printf("ES3=%.2f\n",Encoder3_Speed);
	}

}

//编码器4数值显示
void Encoder4_Printf()
{
	if(fabs(Encoder4_Speed)>Encoder4_SensitiveThreshold)
	{
		USART_UART_Printf("ES4=%.2f\n",Encoder4_Speed);
	}

}





//所有编码器数值显示
void Encoders_Printf()
{
	Encoder1_Printf();
	Encoder2_Printf();
	Encoder3_Printf();
	Encoder4_Printf();
}

//
////////////////////////////////////////////////////////////////
//结束定义串编码器部分

#endif//Encoder_H
