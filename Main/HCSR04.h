#if 0
#ifndef HCSR04_H
#define HCSR04_H

#include"SimpleMain.h"

//该驱动代码已经过时
//目前已不再进行维护


//解释所用的定时器定时器（通常需要一个定时器）
extern TIM_HandleTypeDef htim4;

//HCSR04_Trig发送触发信号，HCSR04_Echo接收返回信号
//HCSR04_Trig引脚，推挽输出，默认低，拉低，速度高
//HCSR04_Echo引脚，外部中断，上升沿下降沿均触发，不拉高或者拉低（记得打开NVIC外部中断）
#define HCSR04_Trig(x) HAL_GPIO_WritePin(HCSR04_Trig_GPIO_Port,HCSR04_Trig_Pin,(GPIO_PinState)(x))//发起检测
#define HCSR04_Echo_Read HAL_GPIO_ReadPin(HCSR04_Echo_GPIO_Port,HCSR04_Echo_Pin)//检测

//检测距离所用的定时器
//预分频系数71（1纳秒自增一次），计数周期默认65535
#define HCSR04_Echo_Timer htim4

//测得的距离
extern float HCSR04_Distance;

//触发距离检测
void HCSR04_Trigger();

#endif//HCSR04_H
#endif//0

