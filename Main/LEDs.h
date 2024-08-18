#if 1
#ifndef LEDs_H
#define LEDs_H

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
#define LED1_R(x) HAL_GPIO_WritePin(LED1_R_GPIO_Port,LED1_R_Pin,(GPIO_PinState)(x))
#define LED1_G(x) HAL_GPIO_WritePin(LED1_G_GPIO_Port,LED1_G_Pin,(GPIO_PinState)(x))
#define LED1_B(x) HAL_GPIO_WritePin(LED1_B_GPIO_Port,LED1_B_Pin,(GPIO_PinState)(x))

#define LED2_R(x) HAL_GPIO_WritePin(LED2_R_GPIO_Port,LED2_R_Pin,(GPIO_PinState)(x))
#define LED2_G(x) HAL_GPIO_WritePin(LED2_G_GPIO_Port,LED2_G_Pin,(GPIO_PinState)(x))
#define LED2_B(x) HAL_GPIO_WritePin(LED2_B_GPIO_Port,LED2_B_Pin,(GPIO_PinState)(x))

#define LED3_R(x) HAL_GPIO_WritePin(LED3_R_GPIO_Port,LED3_R_Pin,(GPIO_PinState)(x))
#define LED3_G(x) HAL_GPIO_WritePin(LED3_G_GPIO_Port,LED3_G_Pin,(GPIO_PinState)(x))
#define LED3_B(x) HAL_GPIO_WritePin(LED3_B_GPIO_Port,LED3_B_Pin,(GPIO_PinState)(x))


//LED1
//0红1绿2蓝
void LED1(uint8_t Color,uint8_t Switch);

//LED1闪烁
void LED1_Scan(uint8_t Color);


//LED2
//0红1绿2蓝
void LED2(uint8_t Color,uint8_t Switch);

//LED2闪烁
void LED2_Scan(uint8_t Color);


//LED3
//0红1绿2蓝
void LED3(uint8_t Color,uint8_t Switch);

//LED3闪烁
void LED3_Scan(uint8_t Color);

//LED流水灯Dmeo
void LEDs_Dmeo();


#endif//SimpleIO_H

#endif//0
