#include"Timer.h"
#ifdef Timer_H


//计数器1的计数值1
uint32_t Timer1_Counter1=0;


//计数器初始化
void Timer_Initialization()
{
	HAL_TIM_Base_Start_IT(&Timer_1);
}

//定时器中断函数（借助HAL库实现部分，在HAL库中，所有的定时器中断被集中在一个函数里处理）
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef*htim)
{
	#if 1
	//每0.001秒（一毫秒）进入一次中断（不建议需要周期性执行的程序放在此处执行，可能造成中断嵌套）
	if(htim->Instance==Timer_1.Instance)
	{
		++Timer1_Counter1;

		//建议选择合理的周期来运行需要周期性运行的程序，以避免形成中断嵌套
		//每0.01秒进入一次中断
		if(Timer1_Counter1%10==0)
		{
			//按键扫描
			SimpleIO_Key1();
			SimpleIO_Key2();



			//每0.1秒进入一次中断
			if(Timer1_Counter1%100==0)
			{
				if(MPU6050_State)
				{
					//LED1电平翻转
					SimpleIO_LED1();
				}

				//触发编码器检测
				Encoder_Detection();



				//每1秒进入一次中断
				if(Timer1_Counter1%1000==0)
				{
					//LED2电平翻转
					SimpleIO_LED2();
					//OLED096_FPSRecord_IIC();
					//OLED096_FPSRecord_SPI();
				}

			}

		}

	}
	#endif//0
}



#endif//Timer_H
