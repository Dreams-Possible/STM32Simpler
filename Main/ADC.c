#include"ADC.h"
#ifdef ADC_H

uint16_t ADC1_Data[ADC_Number]=
{
	0
};


//ADC1读取数据
void ADC1_Enable()
{
	HAL_ADCEx_Calibration_Start(&hadc1);//开启ADC之前校准一下
	HAL_ADC_Start(&hadc1);//软件开启ADC1
	HAL_ADC_PollForConversion(&hadc1,10);//轮询等待ADC转换完成
	ADC1_Data[0]=HAL_ADC_GetValue(&hadc1);//将两个通道的采样值存在数组里
	HAL_ADC_Stop(&hadc1);//软件关闭ADC1
}

#endif//ADC_H
