#if 1
#ifndef Keys_H
#define Keys_H
#include"SimpleMain.h"




//配置如下
////////////////////////////////////////////////////////////////
//

//默认硬件上按键接地

//任意引脚命名为：Keyx
//推挽输出，初始高，默认上拉

//
////////////////////////////////////////////////////////////////
//结束配置





//开始按键配置
////////////////////////////////////////////////////////////////
//

//Key_x引脚，推挽输出，初始高，默认上拉
#define Key1 HAL_GPIO_ReadPin(Key1_GPIO_Port,Key1_Pin)
#define Key2 HAL_GPIO_ReadPin(Key2_GPIO_Port,Key2_Pin)
#define Key3 HAL_GPIO_ReadPin(Key3_GPIO_Port,Key3_Pin)
#define Key4 HAL_GPIO_ReadPin(Key4_GPIO_Port,Key4_Pin)
#define Key5 HAL_GPIO_ReadPin(Key5_GPIO_Port,Key5_Pin)
#define Key6 HAL_GPIO_ReadPin(Key6_GPIO_Port,Key6_Pin)
#define Key7 HAL_GPIO_ReadPin(Key7_GPIO_Port,Key7_Pin)
#define Key8 HAL_GPIO_ReadPin(Key8_GPIO_Port,Key8_Pin)


//声明按键的状态
extern uint8_t SimpleIO_Key1_State;
extern uint8_t SimpleIO_Key2_State;
extern uint8_t SimpleIO_Key3_State;
extern uint8_t SimpleIO_Key4_State;
extern uint8_t SimpleIO_Key5_State;
extern uint8_t SimpleIO_Key6_State;
extern uint8_t SimpleIO_Key7_State;
extern uint8_t SimpleIO_Key8_State;


//按键1扫描
void Key1_Scan();
//按键2扫描
void Key2_Scan();
//按键3扫描
void Key3_Scan();
//按键4扫描
void Key4_Scan();
//按键5扫描
void Key5_Scan();
//按键6扫描
void Key6_Scan();
//按键7扫描
void Key7_Scan();
//按键8扫描
void Key8_Scan();

//所有按键扫描
void Keys_Scan();


//
////////////////////////////////////////////////////////////////
//结束按键配置



#endif//Key_H

#endif//0
