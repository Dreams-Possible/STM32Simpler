#include"Timers.h"
#ifdef Timers_H



//开始定义定时器部分
////////////////////////////////////////////////////////////////
//


//计数器1的计数值1
uint32_t Timer1_Counter1=0;

//计数器1的帧数1
//用于统计while中的程序每个单位时间内能运行多少次
uint32_t Timer1_FPS1=0;

//计数器1的标志位1
//用于在while中定时运行程序
uint8_t Timer1_Flag1=0;

//计数器初始化
void Timer_Initialization()
{
	HAL_TIM_Base_Start_IT(&Timer_1);
}

//定时器中断函数（借助HAL库实现部分，在HAL库中，所有的定时器中断被集中在一个函数里处理）
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef*htim)
{
	#if 1
	if(Main_InitizationFlag)
	{
		//每0.001秒（一毫秒）进入一次中断（不建议需要周期性执行的程序放在此处执行，可能造成中断嵌套）
		if(htim->Instance==Timer_1.Instance)
		{
			++Timer1_Counter1;

			//建议选择合理的周期来运行需要周期性运行的程序，以避免形成中断嵌套
			//每0.01秒进入一次中断
			if(Timer1_Counter1%10==0)
			{
				//使用标志位避免中断嵌套
				Timer1_Flag1=1;

				//按键扫描
				Keys_Scan();

				//每0.1秒进入一次中断
				if(Timer1_Counter1%100==0)
				{

					//LED流水灯Dmeo
					LEDs_Dmeo();
					//Encoders_Detection();

					//每1秒进入一次中断
					if(Timer1_Counter1%1000==0)
					{
						//程序每秒运行次数显示
						Timer_Record(1);
					}
				}
			}
		}
	}
	#endif//0
}


//程序每秒运行次数显示
void Timer_Record(uint8_t Flag)
{
	//显示帧数
	if(Flag)
	{
		Error_Printf("T_F=%d\n",Timer1_FPS1);
		Timer1_FPS1=0;
	}
	else//每次运行后调用
	{
		++Timer1_FPS1;
	}

}



//
////////////////////////////////////////////////////////////////
//结束定义定时器部分

#endif//Timer_H
