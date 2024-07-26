#include"ExternalInterrupt.h"
#ifdef ExternalInterrup_H


//所有外部中断（借助HAL库实现部分，在HAL库中，所有的外部中断被集中在一个函数里处理）
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	#if 0
	//超声波距离检测结果接收
	if(GPIO_Pin==HCSR04_Interrupt)
	{
		uint16_t Count;//记录时间
		if(HCSR04_Echo_Read)
		{
			__HAL_TIM_SetCounter(&HCSR04_Echo_Timer,0);//时间清零
			HAL_TIM_Base_Start(&HCSR04_Echo_Timer);//开始计时
		}else
		{
			HAL_TIM_Base_Stop(&HCSR04_Echo_Timer);//停止计时
			Count=__HAL_TIM_GetCounter(&HCSR04_Echo_Timer);//读取时间
			HCSR04_Distance=(uint16_t)Count*0.017;//Distance=Count/1000000*340*100/2
		}
	}
	#endif

	#if 1
	//MPU6050定时刷新数据
	if(GPIO_Pin==MPU6050_Interrupt&&MPU6050_State)
	{
		//不一定要全部读取，只需要读取需要的数据即可
		//MPU6050读取温度值
		//MPU6050_GetTemperature();

		//MPU6050读取陀螺仪值
		//MPU6050_GetGyroscope();

		//MPU6050读取加速度值
		//MPU6050_GetAccelerometer();

		//MPU6050读取姿态角数据
		MPU6050_GetAttitudeAngle();

	}
	#endif
}
#endif//ExternalInterrup_H
