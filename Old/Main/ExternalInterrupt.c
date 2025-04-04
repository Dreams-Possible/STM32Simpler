#include"ExternalInterrupt.h"
#ifdef ExternalInterrup_H


//开始配置所有外部中断
////////////////////////////////////////////////////////////////
//

//所有外部中断（借助HAL库实现部分，在HAL库中，所有的外部中断被集中在一个函数里处理）
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	#ifdef MPU6050_H
	//MPU6050定时刷新数据
	if(GPIO_Pin==MPU6050_Interrupt)
	{
		if(MPU6050_State)
		{
			//不一定要全部读取，只需要读取需要的数据即可
			//MPU6050读取温度值
			//MPU6050_GetTemperature();

			//MPU6050读取陀螺仪值
			//MPU6050_GetGyroscope();

			//MPU6050读取加速度值
			//MPU6050_GetAccelerometer();

			//MPU6050读取姿态角数据
			//MPU6050_GetAttitudeAngle();
			MPU6050_DataFlag=1;
		}
	}
	#endif//MPU6050_H
}


//
////////////////////////////////////////////////////////////////
//结束配置所有外部中断


#endif//ExternalInterrup_H
