#include"Controller.h"
#ifdef Controller_H

//默认速度
int16_t DefaultSpeed=0;
//速度等级
int16_t SpeedLevel=SpeedLevel_High;




//遥控状态
//0停止，1前进，2后退
uint8_t Remote_State1=0;
//0停止，1左转，2右转
uint8_t Remote_State2=0;


//定义初始速度
float Speed1=0;
float Speed2=0;





uint8_t test1=0;




//主控制模块
void MainController()
{


	//遥控执行部分
	RemoteController();

	//视觉辅助
	AuxiliaryController();

	//电机驱动
	Motor_Driver(Speed1,Speed2);


}




//遥控接收部分JDY31
void RemoteReceiver()
{
	//遥控前进
	if(USART_JDY31_Data[0]=='A')
	{
		Remote_State1=1;
		//USART_JDY31_Printf("遥控前进\n");
	}
	//遥控停止
	if(USART_JDY31_Data[0]=='Z'||USART_JDY31_Data[1]=='Z')
	{
		Remote_State1=0;
		//USART_JDY31_Printf("遥控停止\n");
	}
	//遥控后退
	if(USART_JDY31_Data[0]=='B')
	{
		Remote_State1=2;
		//USART_JDY31_Printf("遥控后退\n");
	}
	//收到遥控左转
	if(USART_JDY31_Data[0]=='C')
	{
		Remote_State2=1;
		//USART_JDY31_Printf("遥控左转\n");
	}
	//收到遥控右转
	if(USART_JDY31_Data[0]=='D')
	{
		Remote_State2=2;
		//USART_JDY31_Printf("遥控右转\n");
	}

	//收到遥控停止转弯
	if(USART_JDY31_Data[0]=='Y'||USART_JDY31_Data[1]=='Y')
	{
		Remote_State2=0;
		//USART_JDY31_Printf("停止转弯\n");
	}

	//收到遥控制动
	if(USART_JDY31_Data[0]=='X')
	{
		Remote_State1=0;
		Remote_State2=0;
		USART_JDY31_Printf("制动\n");

//		test1=0;
	}

	//调整速度等级//低速
	if(USART_JDY31_Data[0]=='E')
	{
		SpeedLevel=SpeedLevel_Low;
		//USART_JDY31_Printf("遥控低速\n");
	}
	//调整速度等级//中速
	if(USART_JDY31_Data[0]=='F')
	{
		SpeedLevel=SpeedLevel_Medium;
		//USART_JDY31_Printf("遥控中速\n");
	}
	//调整速度等级//高速
	if(USART_JDY31_Data[0]=='G')
	{
		SpeedLevel=SpeedLevel_High;
		//USART_JDY31_Printf("遥控高速\n");
	}





	//测试
	if(USART_JDY31_Data[0]=='1')
	{
		test1=1;
	}
	//测试
	if(USART_JDY31_Data[0]=='2')
	{
		test1=2;
	}
	//测试
	if(USART_JDY31_Data[0]=='3')
	{

		test1=3;
	}
	if(USART_JDY31_Data[0]=='4')
	{

		while(1)
		{
			Motor_Driver(0,0);
		}


	}





}






//遥控执行
void RemoteController()
{
	//速度归零
	Speed1=0;
	Speed2=0;

	//停止
	if(Remote_State1==0)
	{
		Speed1=0;
		Speed2=0;
	}

	//前进
	if(Remote_State1==1)
	{
		Speed1+=SpeedLevel;
		Speed2+=SpeedLevel;
	}

	//后退
	if(Remote_State1==2)
	{
		Speed1-=SpeedLevel;
		Speed2-=SpeedLevel;
	}

	//左转
	if(Remote_State2==1)
	{
		//停止
		if(Remote_State1==0)
		{
			Speed1=-SpeedLevel*0.6;
			Speed2=SpeedLevel*0.6;
		}else
		{
			Speed1*=0.2;
			Speed2*=1.2;
		}
	}

	//右转
	if(Remote_State2==2)
	{
		//停止
		if(Remote_State1==0)
		{
			Speed2=-SpeedLevel*0.6;
			Speed1=SpeedLevel*0.6;
		}else
		{
			Speed2*=0.2;
			Speed1*=1.2;
		}
	}

}



//定义视觉辅助状态（0关闭1直行2路口）
int8_t Auxiliary_State1=0;

//视觉接收部分OpenMV
void AuxiliaryReceiver()
{


	//OpenMV直行
	if(USART_OpenMV_Data[0]=='a')
	{
		Auxiliary_State1=1;
		//USART_JDY31_Printf("直行\n");
		//接受数字
		OpenMVNumber=atof((const char *)(USART_OpenMV_Data+2));
//		USART_UART_Printf("Data=%f\n",OpenMVNumber);
		//USART_JDY31_Printf("Data=%f\n",OpenMVNumber);
	}

	//OpenMV路口
	if(USART_OpenMV_Data[0]=='b')
	{
		Auxiliary_State1=2;
		//USART_JDY31_Printf("路口\n");
	}

	//OpenMV失去道路
	if(USART_OpenMV_Data[0]=='c')
	{
		Auxiliary_State1=3;
		//USART_JDY31_Printf("停止\n");
	}






}



//视觉辅助
//用来帮助巡线，类似于自动辅助驾驶系统
void AuxiliaryController()
{
	//直行，辅助参与
	if(Auxiliary_State1==1)
	{
		//PID1比例系数
		//float PID1_Kp=0.1*SpeedLevel;
		float PID1_Kp=0.6;
		//PID
		float AdjustValue=OpenMVNumber*PID1_Kp;
		//限幅
		if(AdjustValue>SpeedLevel)
		{
			AdjustValue=SpeedLevel*0.5;
		}
		if(AdjustValue<-SpeedLevel)
		{
			AdjustValue=-SpeedLevel*0.5;
		}
//		USART_JDY31_Printf("Adj=%.2f\n",AdjustValue);
		if(Remote_State1==1)
		{
			//调整
			Speed1-=AdjustValue*0.5;
			Speed2+=AdjustValue*0.5;
		}
//		if(Remote_State1==2)
//		{
//			//调整
//			Speed1-=AdjustValue*0.5;
//			Speed2+=AdjustValue*0.5;
//		}

	}


}
//
//
////转向等待时间
//uint8_t TurnTimer=0;
//
////转向等待时间
//uint8_t TurnFlag=0;
//
//
//
//
//
//
//
//
//
//
////定义转弯历史记录
//uint8_t TurnHistory[8]=
//{
//		0,
//};
////定义转弯次数
//uint8_t TurnNumber=0;
//
//
//
//
//void StartSign()
//{
//	if(test1==3)
//	{
//		Remote_State1=1;
//	}
//}
//
//
////自动转向
//void AutoTurn(uint8_t Direction)
//{
//
//	//到达路口
//	if(Auxiliary_State1==2)
//	{
//		if(Direction==0)
//		{
//			Remote_State1=0;
//			USART_JDY31_Printf("路口等待\n");
//			return;
//		}
//
//	}
//
//	//转向
//	if(TurnFlag==0)
//	{
//		//记录转向
//		TurnHistory[TurnNumber]=Direction;
//		++TurnNumber;
//
//		TurnFlag=1;
//
//		Remote_State1=1;
//
//		if(Remote_State1==1)
//		{
//			//SpeedLevel=SpeedLevel_Low;
//			if(Direction==1)
//			{//左转
//				Remote_State2=1;
//				USART_JDY31_Printf("路口左转\n");
//			}
//			if(Direction==2)
//			{//右转
//				Remote_State2=2;
//				USART_JDY31_Printf("路口右转\n");
//			}
//		}
//	}
//
//	if(TurnFlag)
//	{
//		//转弯中
//		if(Auxiliary_State1!=1)
//		{
//			USART_JDY31_Printf("TT=%d\n",TurnTimer);
//			++TurnTimer;
//		}
//		//基本回正，结束转向
//		if(TurnTimer>42&&Auxiliary_State1==1)//&&OpenMVNumber>-30)
//		{
//			USART_JDY31_Printf("结束转向\n");
//			//SpeedLevel=SpeedLevel_Medium;
//			Remote_State2=0;
//			TurnTimer=0;
//			TurnFlag=0;
//		}
//	}
//}
//
//
//


#endif//Control_H
