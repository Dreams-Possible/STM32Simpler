#include"SimpleMain.h"
#ifdef SimpleMain_H

//初始化完成标志
uint8_t MainInitization_Flag=0;


//全局初始化
//所有的初始化函数放在这里
void MainInitization()
{
	//开始初始化
	USART_UART_Printf("InitStt\n");

	//定时器初始化
	Timer_Initialization();

	//串口接收初始化
	USART_UART_Initialization();

	//编码器初始化（定时器接收方波）
	Encoder_Initialization();

	//电机初始化（定时器开启输出PWM）
	Motor_Initialization();

	//MPU6050初始化
	//MPU6050_Initialization();

	//屏幕初始化
	//OLED096_Initialization_IIC();

	//全部初始化完成
	USART_UART_Printf("InitSucc\n");
	MainInitization_Flag=1;
	//OLED096_Printf_IIC("Run");

}


//可以在这里写Main中的While函数
//效果等同于在main.c中写
void MainSimple()
{
//
//	MotorSpeed_1=50;
//	MotorSpeed_2=50;
//	MotorSpeed_3=50;
//	MotorSpeed_4=50;
//
//	Motor_Driver();

	uint32_t ID=0;

	while(1)
	{



		//Encoder_Printf();
		//USART_JDY31_Printf("here\n");
		//MPU6050数值显示
		//MPU6050_Printf();

		W25Qxx_ReadID(&ID);
		HAL_Delay(500);
		USART_UART_Printf("ID=%d\n",ID);
		HAL_Delay(500);


		++Timer1_FPS1;
	}

}












#endif//SimpleMain_H
