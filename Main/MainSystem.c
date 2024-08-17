#include"MainSystem.h"
#ifdef MainSystem_H





//定义转弯历史记录
uint8_t TurnHistory[8]=
{
		0,
};
//定义转弯次数
uint8_t TurnNumber=0;

//目标数字
uint8_t TGNumber=0;

//停止超时
uint16_t StopTimer=0;

//转弯超时
uint16_t TurnTimer=400;

//掉头超时
uint16_t BackTimer=1000;




//阶段记录
uint8_t Step=0;




//数字检测
uint8_t step1()
{
	if(test==0)
	{
		USART_UART_Printf("等待数字\n");
		USART_JDY31_Printf("等待数字\n");
		return 1;
	}else
	{
		TGNumber=test;
		test=0;
		USART_UART_Printf("获得数字\n");
		USART_JDY31_Printf("获得数字\n");
		return 0;
	}

}


//放药检测
uint8_t step2()
{
	if(1==0)
	{
		return 1;
	}else
	{
		HAL_Delay(1000);
		USART_UART_Printf("放药检测完成\n");
		USART_JDY31_Printf("放药检测完成\n");
		return 0;
	}

}




//停止检测
uint8_t step3()
{
	if(Auxiliary_State1==0)
	{
		USART_UART_Printf("疑似停止\n");
		USART_JDY31_Printf("疑似停止\n");
		++StopTimer;
		if(StopTimer>100&&Step>3)
		{
			USART_UART_Printf("停止\n");
			USART_JDY31_Printf("停止\n");
			return 0;
		}else
		{
			return 1;
		}

	}else
	{
		StopTimer=0;
		USART_UART_Printf("不停止\n");
		USART_JDY31_Printf("不停止\n");
		return 1;
	}
}

//掉头
uint8_t step4()
{

	USART_UART_Printf("掉头中\n");
	USART_JDY31_Printf("掉头中\n");
	//转向
	Remote_State2=1;

	//遥控执行部分
	RemoteController();

	//电机驱动
	Motor_Driver(Speed1,Speed2);

	HAL_Delay(BackTimer);

	USART_UART_Printf("掉头完成\n");
	USART_JDY31_Printf("掉头完成\n");
	return 0;
}


//取药检测
uint8_t step5()
{
	if(1==0)
	{
		return 1;
	}else
	{
		HAL_Delay(1000);
		USART_UART_Printf("取药检测完成\n");
		USART_JDY31_Printf("取药检测完成\n");
		return 0;
	}
}



void All()
{
	//数字检测
	while(step1());
	++Step;

	//放药检测
	while(step2());
	++Step;


	//未达路口时直行，未到达终点时循环
	while(step3())
	{
		USART_UART_Printf("送药中\n");
		USART_JDY31_Printf("送药中\n");
		//直行
		if(Auxiliary_State1==1)
		{
			//前进
			Remote_State1=1;
			Remote_State2=0;

			//主控制模块
			MainController();

			USART_UART_Printf("直走\n");
			USART_JDY31_Printf("直走\n");
		}

		//到达路口
		if(Auxiliary_State1==2)
		{
			USART_UART_Printf("路口\n");
			USART_JDY31_Printf("路口\n");

			//停止
			//电机驱动
			Remote_State1=0;
			Motor_Driver(0,0);

			uint8_t TurnWay=0;
			//数字检测
			while(step1())
			{
				TurnWay=TGNumber;
			}

			//记录转向信息
			TurnHistory[TurnNumber]=TurnWay;
			++TurnNumber;

			//1左2右
			USART_UART_Printf("转向中\n");
			USART_JDY31_Printf("转向中\n");
			//前进
			Remote_State1=1;
			Remote_State2=TurnWay;

			//遥控执行部分
			RemoteController();
			//电机驱动
			Motor_Driver(Speed1,Speed2);

			HAL_Delay(TurnTimer);

			Remote_State1=0;
			Remote_State2=0;

			++Step;

		}


	}


	if(Step<3)
	{
		USART_UART_Printf("异常返回\n");
		return;
	}

	//等待取药
	while(step5());

	//掉头
	while(step4());

	//未达路口时直行，未到达起点时循环
	while(step3())
	{
		USART_UART_Printf("返回中\n");
		USART_JDY31_Printf("返回中\n");
		//直行
		if(Auxiliary_State1==1)
		{
			USART_UART_Printf("直走\n");
			USART_JDY31_Printf("直走\n");
			//前进
			Remote_State1=1;

			//主控制模块
			MainController();
		}

		//到达路口
		if(Auxiliary_State1==2)
		{
			USART_UART_Printf("路口\n");
			USART_JDY31_Printf("路口\n");

			//停止
			//电机驱动
			Remote_State1=0;
			Motor_Driver(0,0);


			uint8_t TurnWay=0;

			if(TurnHistory[TurnNumber]==1)
			{
				TurnWay=2;
			}

			if(TurnHistory[TurnNumber]==2)
			{
				TurnWay=1;
			}

			--TurnNumber;

			//1左2右
			USART_UART_Printf("转弯\n");
			USART_JDY31_Printf("转弯\n");
			//前进
			Remote_State1=1;
			Remote_State2=TurnWay;

			//遥控执行部分
			RemoteController();

			//电机驱动
			Motor_Driver(Speed1,Speed2);

			HAL_Delay(TurnTimer);

			Remote_State1=0;
			Remote_State2=0;

		}
	}
}


//void 开头数字检测
//定义全局变量存目标数字
//
//void 放药检测
//放药后置标志位
//按照指令亮灯
//发送直行信号
//
//
//void 接收数组检测
//访问星瞳视觉模块获得左右转信号
//
//
//u8 定义数组记录转弯情况0左转1右转
//
//
//void 路线调度
//
//如果是12，开局直接发送左右转，记录转弯情况
//
//如果不是12，遇到路口检测数字，接收返回的左右转信号转弯，依次记录转弯情况
//
//如果没路了，发送停止信号，
//
//
//void 全过程
//
//开头数字检测函数
//
//放药检测函数
//
//路线调度函数
//
//取药检测函数，原路返回函数
//
//void 取药检测
//取药后置标志位
//按照指令亮灯
//发送直行信号
//
//
//void 原路返回
//
//原地转180度
//按照数组顺序，遇到路口依次提取转弯信息，回到起点
//
//
//void 转弯（0左转1右转）
//
//添置左右转标志
//检测openmv
//当出现符合条件的道路后取消转弯标志
//改为直行标志


#endif//MainSystem_H
