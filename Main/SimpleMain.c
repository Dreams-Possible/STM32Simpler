#include"SimpleMain.h"
#ifdef SimpleMain_H

//初始化完成标志
uint8_t volatile MainInitization_Flag=0;


//用于在Main.c中替换主函数
void Main_Simple()
{
	//全局初始化
	Main_Initization();
	//初始化完成标准位
	MainInitization_Flag=1;
	while (1)
	{
		//主函数
		Main_While();
		//如果启用了定时器
		//记录秒程序运行次数
		#ifdef Timers_H
		Timer_Record(0);
		#endif//Timers_H
	}
}



//全局初始化
//所有的初始化函数放在这里
void Main_Initization()
{
	//开始初始化
	Error_Printf("InitStt\n");

	//定时器初始化
	Timer_Initialization();

	//串口1接收初始化
	UART1_Initialization();

	//编码器初始化（定时器接收方波）
	Encoders_Initialization();

	//电机初始化（定时器开启输出PWM）
	Motors_Initialization();

	//MPU6050初始化
	//MPU6050_Initialization();

	//屏幕初始化
	//OLED096_Initialization_IIC();

	//全部初始化完成
	Error_Printf("InitSucc\n");
	//

}


//主函数
//可以在这里写Main中的While函数
void Main_While()
{
	uint32_t ID=0;

	W25Qx_ReadID(&ID);
	HAL_Delay(500);
	Error_Printf("ID=%d\n",ID);
	HAL_Delay(500);

}















#endif//SimpleMain_H
