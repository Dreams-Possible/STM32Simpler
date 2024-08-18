#if 0
#ifndef SimpleIO_H
#define SimpleIO_H

#include"SimpleMain.h"

//该驱动代码已经过时
//目前已不再进行维护

//提供一个简化的IO引脚重定义实例
//可以实现控制小灯亮灭和按键扫描等功能
//IO引脚名称默认为Pinx

//Pin1引脚，推挽输出，初始高，默认上拉
//Pin2引脚，推挽输出，初始高，默认上拉

#define Pin1_Out(x) HAL_GPIO_WritePin(Pin1_GPIO_Port,Pin1_Pin,(GPIO_PinState)(x))
#define Pin1_In HAL_GPIO_ReadPin(Pin1_GPIO_Port,Pin1_Pin)

#define Pin2_Out(x) HAL_GPIO_WritePin(Pin2_GPIO_Port,Pin2_Pin,(GPIO_PinState)(x))
#define Pin2_In HAL_GPIO_ReadPin(Pin2_GPIO_Port,Pin2_Pin)

//Pin3引脚，推挽输出，初始高，默认上拉
//Pin4引脚，推挽输出，初始高，默认上拉
#define Pin3_Out(x) HAL_GPIO_WritePin(Pin3_GPIO_Port,Pin3_Pin,(GPIO_PinState)(x))
#define Pin3_In HAL_GPIO_ReadPin(Pin3_GPIO_Port,Pin3_Pin)

#define Pin4_Out(x) HAL_GPIO_WritePin(Pin4_GPIO_Port,Pin4_Pin,(GPIO_PinState)(x))
#define Pin4_In HAL_GPIO_ReadPin(Pin4_GPIO_Port,Pin4_Pin)

//Pin5引脚，推挽输出，初始高，默认上拉
#define Pin5_Out(x) HAL_GPIO_WritePin(Pin5_GPIO_Port,Pin5_Pin,(GPIO_PinState)(x))
#define Pin5_In HAL_GPIO_ReadPin(Pin5_GPIO_Port,Pin5_Pin)

//声明按键的状态
extern uint8_t SimpleIO_Key1_State;
extern uint8_t SimpleIO_Key2_State;

//LED1电平翻转
void SimpleIO_LED1();

//LED2电平翻转
void SimpleIO_LED2();

//Key1按键扫描
void SimpleIO_Key1();

//Key2按键扫描
void SimpleIO_Key2();

#endif//SimpleIO_H

#endif//0
