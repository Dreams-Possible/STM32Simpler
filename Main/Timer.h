#if 1
#ifndef Timer_H
#define Timer_H
#include"SimpleMain.h"



//提供了一个定时任务的功能
//每隔一段时间自动运行某一函数

//使用前务必打开对应定时器NVIC全局中断
//每0.001秒进入一次中断
//配置预分频系数72-1
//计数周期1000-1

//解释所使用的定时器
extern TIM_HandleTypeDef htim1;

//计数器器所用定时器
#define Timer_1 htim1

//声明计数器1的计数值1
extern uint32_t Timer1_Counter1;

//定时器初始化
void Timer_Initialization();



#endif//Timer_H
#endif//0
