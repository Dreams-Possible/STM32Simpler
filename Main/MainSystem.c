#include"MainSystem.h"
#ifdef MainSystem_H







//目标数字
uint8_t TargetNumber=0;

//目标转向
uint8_t TargetTurn=0;


////直行状态
////用于处理路口直行又遇路口的情况
//uint8_t GoFlag=0;




//数字检测
uint8_t NumberScan(uint8_t State)
{
	Remote_State1=0;
	Remote_State2=0;
	Motor_Driver(0,0);

	//储存目标数字
	if(State==0)
	{
		if(test1==0)
		{
			//USART_JDY31_Printf("等待数字\n");
			return 1;
		}else
		{
			TargetNumber=test1;
			test1=0;
			//USART_JDY31_Printf("获得数字\n");
			return 0;
		}
	}else
	{
		if(test1==0)
		{
			//USART_JDY31_Printf("等待数字\n");
			return 1;
		}else
		{
			TargetTurn=test1;
			if(test1==3)
			{
				TargetTurn=0;
			}
			test1=0;

			//USART_JDY31_Printf("获得数字\n");

			return 0;
		}
	}


}



//
////数字检测
////0储存目标数字1识别目标数字
//uint8_t NumberScan(uint8_t State)
//{
//
//	Remote_State1=0;
//	Remote_State2=0;
//	Motor_Driver(0,0);
//	//储存目标数字
//	if(State==0)
//	{
//		//读取星瞳AI
//		while(1)
//		{
//			if(read_singtownaicam_objs()==1)
//			{
//				TargetNumber=objs[0].idx;
//				USART_JDY31_Printf("数字=%d\n",TargetNumber);
//				return 0;
//			}
//		}
//
//	}else//识别目标数字
//	{
//		//固定病房
//		if(TargetNumber==1)
//		{
//			TargetTurn=1;
//			USART_JDY31_Printf("左转\n");
//			return 0;
//		}
//		if(TargetNumber==2)
//		{
//			TargetTurn=2;
//			USART_JDY31_Printf("右转\n");
//			return 0;
//		}
//
//
//		//读取星瞳AI
//		read_singtownaicam_objs();
//		for(uint8_t a=0;a<8;a++)
//		{
//			if(objs[a].idx==TargetNumber)
//			{
//				if(objs[a].x1+objs[a].x2<320)
//				{
//					TargetTurn=1;
//					USART_JDY31_Printf("左转\n");
//					return 0;
//				}else
//				{
//					TargetTurn=2;
//					USART_JDY31_Printf("右转\n");
//					return 0;
//				}
//			}
//		}
//
//
//		USART_JDY31_Printf("没有目标数字\n");
//		return 1;
//	}
//
//
//
//}








//物品状态检测
//0放药检测1取药检测
uint8_t PickTest(uint8_t State)
{
	//放药检测
	if(State==0)
	{
		if(SimpleIO_Key1_State)
		{
			//USART_JDY31_Printf("放药检测完成\n");
			SimpleIO_Key1_State=0;
			return 0;
		}else
		{
			//USART_JDY31_Printf("请放药\n");
			return 1;

		}
	}else//取药检测
	{
		if(SimpleIO_Key2_State)
		{
			//USART_JDY31_Printf("取药检测完成\n");
			SimpleIO_Key2_State=0;
			return 0;

		}else
		{
			//USART_JDY31_Printf("请取药\n");
			return 1;

		}
	}



}




//停止检测
uint8_t StopTest()
{
	if(Auxiliary_State1==3)
	{
//		USART_JDY31_Printf("停止\n");
		Remote_State1=0;
		Remote_State2=0;
		Motor_Driver(0,0);
		return 1;

	}else
	{
//		USART_JDY31_Printf("不停止\n");
		return 0;
	}
}


//直行
void Go()
{
	//前进
	Remote_State1=1;
	Remote_State2=0;

	//主控制模块
	MainController();

//	USART_JDY31_Printf("直行\n");

}


//转弯
void Turn(uint8_t Direction)
{
	USART_JDY31_Printf("Dir=%d\n",Direction);

	//如果直走
	if(Direction==0)
	{
		Go();
		return;
	}


//	float CurrentAngle=MPU6050_Yaw;
//
//	float AngleChange=0;
//
//	while(AngleChange<80)
//	{
//		AngleChange=fabs(MPU6050_Yaw-CurrentAngle);
//
//		if(AngleChange>180)
//		{
//			AngleChange=fabs(MPU6050_Yaw+CurrentAngle);
//		}


	//处理mpu6050临界角度问题
	float CurrentAngle=MPU6050_Yaw;

	float AngleChange=0;

	float Angle1=0;

	float Angle2=0;

	if(CurrentAngle>0)
	{
		Angle1=180-CurrentAngle;
	}else
	{
		Angle1=180+CurrentAngle;
	}

	while(AngleChange<80)
	{
		AngleChange=fabs(MPU6050_Yaw-CurrentAngle);

		if(AngleChange>180)
		{
			if(MPU6050_Yaw>0)
			{
				Angle2=180-MPU6050_Yaw;
			}else
			{
				Angle2=180+MPU6050_Yaw;
			}
			AngleChange=Angle1+Angle2;
		}


		//USART_JDY31_Printf("转向中\n");
		//转向
		Remote_State1=1;
		Remote_State2=Direction;

//		USART_JDY31_Printf("abs=%f\n",AngleChange);
//		USART_JDY31_Printf("TurnNumber=%d\n",TurnNumber);
//		USART_JDY31_Printf("Dir=%d\n",Direction);
//
//		USART_JDY31_Printf("curr=%f\n",CurrentAngle);
//		USART_JDY31_Printf("yaw=%f\n",MPU6050_Yaw);

		//遥控执行部分
		RemoteController();

		//电机驱动
		Motor_Driver(Speed1,Speed2);

//		if(fabs(MPU6050_Yaw-CurrentAngle)>90)
//		{
//			break;
//		}

//		if(Auxiliary_State1==1&&fabs(OpenMVNumber)<20&&fabs(MPU6050_Yaw-CurrentAngle)>60)
//		{
//			break;
//		}

	}
	Remote_State1=0;
	Remote_State2=0;

//	USART_JDY31_Printf("转向完成\n");

	Motor_Driver(0,0);

}

//掉头
void Return(uint8_t Direction)
{

	//处理mpu6050临界角度问题
	float CurrentAngle=MPU6050_Yaw;

	float AngleChange=0;

	float Angle1=0;

	float Angle2=0;

	if(CurrentAngle>0)
	{
		Angle1=180-CurrentAngle;
	}else
	{
		Angle1=180+CurrentAngle;
	}

	while(AngleChange<170)
	{
		AngleChange=fabs(MPU6050_Yaw-CurrentAngle);

		if(AngleChange>180)
		{
			if(MPU6050_Yaw>0)
			{
				Angle2=180-MPU6050_Yaw;
			}else
			{
				Angle2=180+MPU6050_Yaw;
			}
			AngleChange=Angle1+Angle2;
		}

//		USART_JDY31_Printf("abs=%f\n",AngleChange);
//
//		USART_JDY31_Printf("curr=%f\n",CurrentAngle);
//
//		USART_JDY31_Printf("yaw=%f\n",MPU6050_Yaw);
		//USART_JDY31_Printf("掉头中\n");
		//转向
		Remote_State2=Direction;

		//遥控执行部分
		RemoteController();

		//电机驱动
		Motor_Driver(Speed1,Speed2);

		//检测道路是否回正
		if(Auxiliary_State1==1&&fabs(OpenMVNumber)<10&&fabs(MPU6050_Yaw-CurrentAngle)>160)
		{
//			USART_JDY31_Printf("提前\n");
			break;
		}
//		uint8_t State=0;
//		if(fabs(MPU6050_Yaw-CurrentAngle)>170)
//		{
//			++State;
//			if(State>5)
//			{
//				break;
//			}
//
//		}

	}
	Remote_State1=0;
	Remote_State2=0;

//	USART_JDY31_Printf("%f",fabs((MPU6050_Yaw+180)-(CurrentAngle+180)));
//	USART_JDY31_Printf("掉头完成\n");
	Motor_Driver(0,0);

}



//全流程
void TakeSystem()
{


	//定义转弯历史记录
	uint8_t TurnHistory[8]=
	{
			0,
	};
	//定义转弯次数
	uint8_t TurnNumber=0;


	//数字检测
	while(NumberScan(0));

	//放药检测
	while(PickTest(0));


	//未达路口时直行，未到达终点时循环
	while(1)
	{

//		USART_JDY31_Printf("启程中\n");
		//直行
		if(Auxiliary_State1==1)
		{
			Go();
		}

		//到达路口
		if(Auxiliary_State1==2)
		{

			USART_JDY31_Printf("路口\n");

//			//停止
//			//电机驱动
//			Remote_State1=0;
//			Motor_Driver(0,0);
//			HAL_Delay(5000);

			//数字检测
			while(NumberScan(1))

			//记录转向信息
			TurnHistory[TurnNumber]=TargetTurn;
			TurnHistory[TurnNumber]=TargetTurn;
			++TurnNumber;

//			USART_JDY31_Printf("TargetTurn=%d\n",TargetTurn);
//			USART_JDY31_Printf("T[0]=%d\n",TurnHistory[0]);
//
			for(uint8_t a=0;a<8;++a)
			{
				USART_JDY31_Printf("List[%d]=%d\n",a,TurnHistory[a]);
			}

			//转向
			Turn(TargetTurn);

		}

		if(StopTest())
		{
			break;
		}

	}

	//等待取药
	while(PickTest(1));

	//掉头
	Return(1);


	//未达路口时直行，未到达起点时循环
	while(1)
	{

//		USART_JDY31_Printf("返回中\n");
		//直行
		if(Auxiliary_State1==1)
		{
			Go();
		}

		//到达路口
		if(Auxiliary_State1==2)
		{

//			USART_JDY31_Printf("路口\n");

//			//停止
//			//电机驱动
//			Remote_State1=0;
//			Motor_Driver(0,0);

			if(TurnNumber!=0)
			{
				--TurnNumber;
			}


			if(TurnHistory[TurnNumber]==0)
			{
				TargetTurn=0;
			}

			if(TurnHistory[TurnNumber]==1)
			{
				TargetTurn=2;
			}

			if(TurnHistory[TurnNumber]==2)
			{
				TargetTurn=1;
			}



//
//			for(uint8_t a=0;a<8;++a)
//			{
//				USART_JDY31_Printf("list[%d]=%d\n",a,TurnHistory[a]);
//			}

			//转向
			Turn(TargetTurn);



		}


		if(StopTest())
		{
			break;
		}
	}
	USART_JDY31_Printf("已回到起点\n");
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


//
//
////数字检测
////0储存目标数字1识别目标数字
//uint8_t NumberScan(uint8_t State)
//{
//
//	//储存目标数字
//	if(State==0)
//	{
//		//读取星瞳AI
//		while(1)
//		{
//			if(read_singtownaicam_objs()==1)
//			{
//				TargetNumber=objs[0].idx;
//				USART_JDY31_Printf("数字=%d\n",TargetNumber);
//				return 0;
//			}
//		}
//
//	}else//识别目标数字
//	{
//		//固定病房
//		if(TargetNumber==1)
//		{
//			USART_JDY31_Printf("左转\n");
//			return 1;
//		}
//		if(TargetNumber==2)
//		{
//			USART_JDY31_Printf("右转\n");
//			return 2;
//		}
//
//
//		//读取星瞳AI
//		read_singtownaicam_objs();
//		for(uint8_t a=0;a<8;a++)
//		{
//			if(objs[a].idx==TargetNumber)
//			{
//				if(objs[a].x1+objs[a].x2<320)
//				{
//					USART_JDY31_Printf("左转\n");
//					return 1;
//				}else
//				{
//					USART_JDY31_Printf("右转\n");
//					return 2;
//				}
//			}
//		}
//
//		USART_JDY31_Printf("没有目标数字\n");
//
//	}
//
//
//
//}
#endif//MainSystem_H
