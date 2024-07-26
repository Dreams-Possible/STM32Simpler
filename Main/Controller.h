#if 1
#ifndef Controller_H
#define Controller_H

#include"SimpleMain.h"


#define SpeedLevel_Low 25
#define SpeedLevel_Medium 50
#define SpeedLevel_High 75

//速度等级
extern int16_t SpeedLevel;


//遥控状态
//0停止，1前进，2后退
extern uint8_t Remote_State1;
//0停止，1左转，2右转
extern uint8_t Remote_State2;

//定义视觉辅助状态（0关闭1开启）
extern int8_t Auxiliary_State1;

//定义初始速度
extern float Speed1;
extern float Speed2;




extern uint8_t test1;






//遥控接收部分JDY31
void RemoteReceiver();

//遥控执行
void RemoteController();

//主控制模块
void MainController();

//视觉接收部分OpenMV
void AuxiliaryReceiver();

//视觉辅助
//用来帮助巡线，类似于自动辅助驾驶系统
void AuxiliaryController();

#endif//Controller_H
#endif//0
