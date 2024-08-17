#if 1
#ifndef Key_H
#define Key_H
#include"SimpleMain.h"




//配置如下
////////////////////////////////////////////////////////////////
//

//默认硬件上按键接地

//任意引脚命名为：Key_x
//推挽输出，初始高，默认上拉

//
////////////////////////////////////////////////////////////////
//结束配置





//开始按键配置
////////////////////////////////////////////////////////////////
//

//Key_x引脚，推挽输出，初始高，默认上拉
#define Key_1 HAL_GPIO_ReadPin(Key_1_GPIO_Port,Key_1_Pin)
#define Key_2 HAL_GPIO_ReadPin(Key_2_GPIO_Port,Key_2_Pin)
#define Key_3 HAL_GPIO_ReadPin(Key_3_GPIO_Port,Key_3_Pin)
#define Key_4 HAL_GPIO_ReadPin(Key_4_GPIO_Port,Key_4_Pin)
#define Key_5 HAL_GPIO_ReadPin(Key_5_GPIO_Port,Key_5_Pin)
#define Key_6 HAL_GPIO_ReadPin(Key_6_GPIO_Port,Key_6_Pin)
#define Key_7 HAL_GPIO_ReadPin(Key_7_GPIO_Port,Key_7_Pin)
#define Key_8 HAL_GPIO_ReadPin(Key_8_GPIO_Port,Key_8_Pin)


//声明按键的状态
extern uint8_t SimpleIO_Key_1_State;
extern uint8_t SimpleIO_Key_2_State;
extern uint8_t SimpleIO_Key_3_State;
extern uint8_t SimpleIO_Key_4_State;
extern uint8_t SimpleIO_Key_5_State;
extern uint8_t SimpleIO_Key_6_State;
extern uint8_t SimpleIO_Key_7_State;
extern uint8_t SimpleIO_Key_8_State;


//按键扫描
void Key_Scan_All();


//
////////////////////////////////////////////////////////////////
//结束按键配置



#endif//Key_H

#endif//0
