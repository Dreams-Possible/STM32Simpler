#include"HCSR04.h"
#ifdef HCSR04_H

//该驱动代码已经过时
//目前已不再进行维护

//测得的距离
float HCSR04_Distance=0;

//触发距离检测
void HCSR04_Trigger()
{
	HCSR04_Trig(1);
	HAL_Delay(1);//10us即可，1ns太长了，但确实可用
	HCSR04_Trig(0);
}

//距离检测结果接收
//该部分在ExternalInterrup中
#endif//HCSR04_H
