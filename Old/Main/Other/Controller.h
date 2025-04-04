#if 0
#ifndef Controller_H
#define Controller_H

#include"SimpleMain.h"

//该驱动代码已经过时
//目前已不再进行维护

//重定义速度等级
#define SpeedLevel_Low 8
#define SpeedLevel_Medium 10
#define SpeedLevel_High 12


//PID初始化
void PID_Initization();

//主控制函数
void PID_Control();

//遥控接收部分
void RemoteReceiver();



#endif//Controller_H
#endif//0
