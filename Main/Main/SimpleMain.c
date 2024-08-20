#include"SimpleMain.h"
#ifdef SimpleMain_H

//初始化完成标志
uint8_t volatile Main_InitizationFlag=0;


//用于在Main.c中替换主函数
void Main_Simple()
{
	//全局初始化
	Main_Initization();
	//初始化完成标准位
	Main_InitizationFlag=1;
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

	//屏幕初始化
	OLED0961_IIC_Initialization();
	OLED0961_SPI_Initialization();

	//MPU6050初始化
	MPU6050_Initialization();


	//全部初始化完成
	Error_Printf("InitSucc\n");

}


//主函数
//可以在这里写Main中的While函数
void Main_While()
{

	//W25Qx_ReadID();

	//MPU6050_GetAttitudeAngle();
	//MPU6050_Printf();

	OLED0961_GUI_Characters(32,32,"HELLO");

	OLED0961_GUI_Line(1,1,32,32);
	OLED0961_IIC_PushFrame();
	OLED0961_SPI_PushFrame();
//	OLED0961_IIC_Refresh(0x0f);
//	OLED0961_SPI_Refresh(0x0f);


//	OLED0961_SPI_Printf("P=%.2f",MPU6050_Pitch);
//	OLED0961_IIC_Printf("R=%.2f",MPU6050_Roll);
//	OLED0961_SPI_Printf("Y=%.2f",MPU6050_Yaw);
	//OLED0961_SPI_Printf("");


}















#endif//SimpleMain_H
