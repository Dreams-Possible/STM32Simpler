#if 1
#ifndef LED_H
#define LED_H

#include"SimpleMain.h"


//配置如下
////////////////////////////////////////////////////////////////
//

//默认硬件上灯接地

//任意引脚命名为：LED_X_x
//推挽输出，初始低，默认下拉

//
////////////////////////////////////////////////////////////////
//结束配置





//开始灯配置
////////////////////////////////////////////////////////////////
//

//LED_X_x引脚，推挽输出，初始低，默认下拉
#define LED_R_1(x) HAL_GPIO_WritePin(LED_R_1_GPIO_Port,LED_R_1_Pin,(GPIO_PinState)(x))
#define LED_G_1(x) HAL_GPIO_WritePin(LED_G_1_GPIO_Port,LED_G_1_Pin,(GPIO_PinState)(x))
#define LED_B_1(x) HAL_GPIO_WritePin(LED_B_1_GPIO_Port,LED_B_1_Pin,(GPIO_PinState)(x))

#define LED_R_2(x) HAL_GPIO_WritePin(LED_R_2_GPIO_Port,LED_R_2_Pin,(GPIO_PinState)(x))
#define LED_G_2(x) HAL_GPIO_WritePin(LED_G_2_GPIO_Port,LED_G_2_Pin,(GPIO_PinState)(x))
#define LED_B_2(x) HAL_GPIO_WritePin(LED_B_2_GPIO_Port,LED_B_2_Pin,(GPIO_PinState)(x))

#define LED_R_3(x) HAL_GPIO_WritePin(LED_R_3_GPIO_Port,LED_R_3_Pin,(GPIO_PinState)(x))
#define LED_G_3(x) HAL_GPIO_WritePin(LED_G_3_GPIO_Port,LED_G_3_Pin,(GPIO_PinState)(x))
#define LED_B_3(x) HAL_GPIO_WritePin(LED_B_3_GPIO_Port,LED_B_3_Pin,(GPIO_PinState)(x))


//LED1
//0红1绿2蓝
void LED_1(uint8_t Color,uint8_t Switch);

//LED1闪烁
void LED_1_Scan(uint8_t Color);


//LED2
//0红1绿2蓝
void LED_2(uint8_t Color,uint8_t Switch);

//LED2闪烁
void LED_2_Scan(uint8_t Color);


//LED3
//0红1绿2蓝
void LED_3(uint8_t Color,uint8_t Switch);

//LED3闪烁
void LED_3_Scan(uint8_t Color);

//LED流水灯Dmeo
void LED_Dmeo();


#endif//SimpleIO_H

#endif//0
