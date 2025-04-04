#if 0
#ifndef Infrared_H
#define Infrared_H
#include"SimpleMain.h"

//该驱动代码已经过时
//目前已不再进行维护


//红外检测结果
extern uint8_t Infrared_S1;//S1检测结果
extern uint8_t Infrared_S2;//S2检测结果
extern uint8_t Infrared_S3;//S3检测结果
extern uint8_t Infrared_S4;//S4检测结果

//重定义检测引脚
//引脚配置为输入模式
//名称为Infrared_Sx
//S1检测结果读取
#define Infrared_S1_In HAL_GPIO_ReadPin(Infrared_S1_GPIO_Port,Infrared_S1_Pin)
//S2检测结果读取
#define Infrared_S2_In HAL_GPIO_ReadPin(Infrared_S2_GPIO_Port,Infrared_S2_Pin)
//S3检测结果读取
#define Infrared_S3_In HAL_GPIO_ReadPin(Infrared_S3_GPIO_Port,Infrared_S3_Pin)
//S4检测结果读取
#define Infrared_S4_In HAL_GPIO_ReadPin(Infrared_S4_GPIO_Port,Infrared_S4_Pin)

//红外检测
void Infrared_Detection();

#endif//Infrared_H
#endif//0

