#include"Encoder.h"
#ifdef Encoder_H



//开始定义串编码器部分
////////////////////////////////////////////////////////////////
//

//测得的速度（自带正负）
float Encoder_Speed_1=0;
float Encoder_Speed_2=0;
float Encoder_Speed_3=0;
float Encoder_Speed_4=0;



//编码器初始化（定时器接收方波）
void Encoder_Initialization()
{
	HAL_TIM_Encoder_Start(&Encoder_Timer_1,TIM_CHANNEL_ALL);
	HAL_TIM_Encoder_Start(&Encoder_Timer_2,TIM_CHANNEL_ALL);
	HAL_TIM_Encoder_Start(&Encoder_Timer_3,TIM_CHANNEL_ALL);
	HAL_TIM_Encoder_Start(&Encoder_Timer_4,TIM_CHANNEL_ALL);
}



//触发编码器检测
void Encoder_Detection()
{
	//检测
	int16_t Encoder_Speed_New_1=(int16_t)__HAL_TIM_GetCounter(&Encoder_Timer_1);
	//滤波
	Encoder_Speed_1=0.3*Encoder_Speed_1+0.7*Encoder_Speed_New_1;
	//重置
	__HAL_TIM_SetCounter(&Encoder_Timer_1,0);

	//检测
	int16_t Encoder_Speed_New_2=(int16_t)__HAL_TIM_GetCounter(&Encoder_Timer_2);
	//滤波
	Encoder_Speed_2=0.3*Encoder_Speed_2+0.7*Encoder_Speed_New_2;
	//重置
	__HAL_TIM_SetCounter(&Encoder_Timer_2,0);


	//检测
	int16_t Encoder_Speed_New_3=(int16_t)__HAL_TIM_GetCounter(&Encoder_Timer_3);
	//滤波
	Encoder_Speed_3=0.3*Encoder_Speed_3+0.7*Encoder_Speed_New_3;
	//重置
	__HAL_TIM_SetCounter(&Encoder_Timer_3,0);

	//检测
	int16_t Encoder_Speed_New_4=(int16_t)__HAL_TIM_GetCounter(&Encoder_Timer_4);
	//滤波
	Encoder_Speed_4=0.3*Encoder_Speed_4+0.7*Encoder_Speed_New_4;
	//重置
	__HAL_TIM_SetCounter(&Encoder_Timer_4,0);
}

//编码器数值显示
void Encoder_Printf()
{
	if(fabs(Encoder_Speed_1)>1)
	{
		USART_UART_Printf("ES1=%.2f\n",Encoder_Speed_1);
	}

	if(fabs(Encoder_Speed_2)>1)
	{
		USART_UART_Printf("ES2=%.2f\n",Encoder_Speed_2);
	}

	if(fabs(Encoder_Speed_3)>1)
	{
		USART_UART_Printf("ES3=%.2f\n",Encoder_Speed_3);
	}

	if(fabs(Encoder_Speed_4)>1)
	{
		USART_UART_Printf("ES4=%.2f\n",Encoder_Speed_4);
	}
}

//
////////////////////////////////////////////////////////////////
//结束定义串编码器部分

#endif//Encoder_H
