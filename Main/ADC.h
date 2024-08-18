#if 0
#ifndef ADC_H
#define ADC_H

#include"SimpleMain.h"


//该驱动代码已经过时
//目前已不再进行维护


//解释所使用的ADC
extern ADC_HandleTypeDef hadc1;

//使用的ADC数量
#define ADC_Number 1

//声明ADC数组
extern uint16_t ADC1_Data[ADC_Number];

//ADC1读取数据
void ADC1_Enable();

#endif//ADC_H
#endif//0
