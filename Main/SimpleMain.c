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
	#ifdef UARTs_H
	//开始初始化
	Error_Printf("InitStt\n");
	#endif//UARTs_H

	#ifdef Timers_H
	Timer_Initialization();
	#endif//Timers_H

	#ifdef UARTs_H
	UART1_Initialization();
	#endif//UARTs_H

	#ifdef UARTs_H
	//全部初始化完成
	Error_Printf("InitSucc\n");
	#endif//UARTs_H

}


//主函数
//可以在这里写Main中的While函数
void Main_While()
{




}















#endif//SimpleMain_H
