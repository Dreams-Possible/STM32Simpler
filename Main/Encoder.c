#include"Encoder.h"
#ifdef Encoder_H


//测得的速度（自带正负）
float Encoder1_Speed=0;
float Encoder2_Speed=0;



//编码器初始化（定时器接收方波）
void Encoder_Initialization()
{
	HAL_TIM_Encoder_Start(&Encoder1_Timer,TIM_CHANNEL_ALL);
	HAL_TIM_Encoder_Start(&Encoder2_Timer,TIM_CHANNEL_ALL);
}



//触发编码器检测
void Encoder_Detection()
{
	//检测
	int16_t Encoder1_Speed_New=(int16_t)__HAL_TIM_GetCounter(&Encoder1_Timer);
	//滤波
	Encoder1_Speed=0.3*Encoder1_Speed+0.7*Encoder1_Speed_New;
	//重置
	__HAL_TIM_SetCounter(&Encoder1_Timer,0);
	//检测
	int16_t Encoder2_Speed_New=(int16_t)__HAL_TIM_GetCounter(&Encoder2_Timer);
//	//硬件调整
//	Encoder2_Speed_New=-Encoder2_Speed_New;
	//滤波
	Encoder2_Speed=0.3*Encoder2_Speed+0.7*Encoder2_Speed_New;
	//重置
	__HAL_TIM_SetCounter(&Encoder2_Timer,0);
}

//编码器数值显示
void Encoder_Printf()
{
	if(fabs(Encoder1_Speed)>1)
	{
		USART_UART_Printf("ES1=%.2f\n",Encoder1_Speed);
	}

	if(fabs(Encoder2_Speed)>1)
	{
		USART_UART_Printf("ES2=%.2f\n",Encoder2_Speed);
	}
}

#endif//Encoder_H
