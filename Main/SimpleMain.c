#include"SimpleMain.h"
#ifdef SimpleMain_H


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
	USART_JDY31_Initialization();
	USART_OpenMV_Initialization();

	//编码器初始化（定时器接收方波）
	Encoder_Initialization();

	//电机初始化（定时器开启输出PWM）
	Motor_Initialization();

	//MPU6050初始化
	MPU6050_Initialization();

	//全部初始化完成
	USART_UART_Printf("InitSucc\n");

}


//可以在这里写Main中的While函数
//效果等同于在main.c中写
void MainSimple()
{

	//Motor_Driver(50,50);

	while(1)
	{
		//USART_JDY31_Printf("123456\n");

		//编码器数值显示
//		Encoder_Printf();
		//遥控执行部分
		//RemoteController();

		//MainController();

		//USART_JDY31_Printf("Y=%.2f\n",MPU6050_Yaw);

		//星瞳AI接收测试
		while(0)
		{
			USART_JDY31_Printf("ExmStar\n");
			int Num;
			while (1)
			{
				Num=read_singtownaicam_objs();
				USART_UART_Printf("Num:%d\n",Num);
				for(uint8_t a=0;a<Num;a++)
				{
					USART_UART_Printf("\t%d\t%d\t[%d,\t%d,\t%d\t%d]\n", objs[a].score, objs[a].idx,objs[a].x1, objs[a].y1, objs[a].x2, objs[a].y2);
				}
			}
		}

		while(1)
		{
			//全流程
			TakeSystem();
		}

	}

}












#endif//SimpleMain_H
