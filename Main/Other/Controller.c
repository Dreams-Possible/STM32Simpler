#include"Controller.h"
#ifdef Controller_H

//该驱动代码已经过时
//目前已不再进行维护

//遥控状态
//0停止，1前进，2后退
uint8_t Remote_State1=0;
//0停止，1左转，2右转
uint8_t Remote_State2=0;

//速度等级
float SpeedLevel=SpeedLevel_Low;


//直立环参数
float PID_Vertical=0;
//速度环参数
float PID_Velocityt=0;
//转向环参数
float PID_Turn=0;

//期望角度
float Angle_Target=0;
//期望速度
float Speed_Target=0;
//期望转向角度
float Turn_Target=0;


//直立环系数
float Vertical_KP=-1.28;//-1.28;//-1.4;//-1.62;//-1.68;//-2.24;//-2.28;	//-2.4;//-2.28;//-2.28;//-1.56;//-1.918;//-1.92;//-1.86;//-1.82;//-1.78;//-1.78;//-1.78;//-1.78;//-1.82;//-2.84;
float Vertical_KD=0.0148;//0.0152;//0.014;//0.0136;//0.0158;//0.0212;//0.0218;	//0.024;//0.0218;//0.0212;//0.0152;//0.0178;//0.016;//0.016;//0.014;//0.012;//0.018;//0.022;//0.028;//0.038;//0.046;

//速度环系数
float Velocity_KP=-1.68;//-1.62;//-1.8;	//-0.2;//-0.0484;//-0.484;//-0.38;//-0.52;//-0.78;//-0.88;//-1.08;//-1;
//float Velocity_KI=0;//0;//0.00612;//0;	//0;//-0.000242;//-0.00242;//-0.0048;//-0.005;

//转向环系数
float Turn_KP=0.2;



//PID初始化
void PID_Initization()
{
	Turn_Target=MPU6050_Yaw;
}

//直立环PD控制器
//输入：期望角度、真实角度、角速度
void Control_Vertical(float Angle_Target,float Angle_Real,int16_t G_X)
{

	//计算直立环
	float P=Vertical_KP*(Angle_Real-Angle_Target);
	float D=Vertical_KD*G_X;
	PID_Vertical=P+D;

//	USART_UART_Printf("AR=%.2f\n",Angle_Real);
//	USART_UART_Printf("AT=%.2f\n",Angle_Target);
//	USART_UART_Printf("AE=%.2f\n",Angle_Real-Angle_Target);
//	USART_UART_Printf("P1=%.2f\n",P);
//	USART_UART_Printf("D1=%.2f\n",D);
//
//	USART_UART_Printf("CV1=%.2f\n",PID_Vertical);

}

//速度环PI控制器
//输入：期望速度、左编码器、右编码器
void Control_Velocity(float Speed_Target,float Encoder_Left,float Encoder_Right)
{


	//停止
	if(Remote_State1==0)
	{
		Speed_Target=0;
	}

	//前进
	if(Remote_State1==1)
	{
		Speed_Target=SpeedLevel;
	}

	//后退
	if(Remote_State1==2)
	{
		Speed_Target=-SpeedLevel;
	}

//	//定义积分
//	static float II=0;
	//定义误差
	float E=(Encoder_Left+Encoder_Right)-Speed_Target;
//
//	//积分
//	II+=E;
//	if(II>1000)
//	{
//		II=1000;
//	}
//	if(II<-1000)
//	{
//		II=-1000;
//	}
//	//检测控制状态
//	if(Remote_State1==0)
//	{
//		II=0;
//	}

	//计算直立环
	float P=Velocity_KP*E;
//	float I=Velocity_KI*II;

	PID_Velocityt=P;//+I;

//	USART_UART_Printf("P2=%.2f\n",P);
//	USART_UART_Printf("I2=%.2f\n",I);
//	USART_UART_Printf("CV2=%.2f\n",PID_Velocityt);
}

//转向环控制器
void Control_Turn(float Angle_Real)
{
	//计算转向环

	//滤波
	static float P_New=0;
	static float P=0;

	//前进//后退
	if(Remote_State1!=0)
	{
		P_New=Turn_KP*(Angle_Real-Turn_Target);
	}

	//不转弯
	if(Remote_State2==0)
	{
		P_New=0;
	}

	//左转
	if(Remote_State2==1)
	{
		P_New=-20;
		Turn_Target=Angle_Real;
	}

	//右转
	if(Remote_State2==2)
	{
		P_New=20;
		Turn_Target=Angle_Real;
	}


	P=0.3*P+0.7*P_New;

	PID_Turn=P;

}

//主控制函数
void PID_Control()
{
	//倒下检测
	if(MPU6050_Roll<90&&MPU6050_Roll>-90)
	{
		//PID控制核心
		Control_Velocity(Speed_Target,Encoder1_Speed,Encoder2_Speed);
		Control_Vertical(Angle_Target+PID_Velocityt,MPU6050_Roll,MPU6050_G_X);
		Control_Turn(MPU6050_Yaw);

		//电机驱动
		Motor_Driver(PID_Vertical-PID_Turn,PID_Vertical+PID_Turn);

	}else
	{
		//倒下停止
		Motor_Driver(0,0);
		//OLED096_Printf_IIC("Stop");
		HAL_Delay(4000);
		//OLED096_Printf_IIC("Run");
	}

}





//遥控接收部分
void RemoteReceiver()
{
	//遥控前进
	if(USART_UART_Data[0]=='A')
	{
		Remote_State1=1;
//		USART_UART_Printf("遥控前进\n");
	}
	//遥控停止
	if(USART_UART_Data[0]=='Z'||USART_UART_Data[1]=='Z')
	{
		Remote_State1=0;
//		USART_UART_Printf("遥控停止\n");
	}
	//遥控后退
	if(USART_UART_Data[0]=='B')
	{
		Remote_State1=2;
//		USART_UART_Printf("遥控后退\n");
	}
	//收到遥控左转
	if(USART_UART_Data[0]=='C')
	{
		Remote_State2=1;
//		USART_UART_Printf("遥控左转\n");
	}
	//收到遥控右转
	if(USART_UART_Data[0]=='D')
	{
		Remote_State2=2;
//		USART_UART_Printf("遥控右转\n");
	}

	//收到遥控停止转弯
	if(USART_UART_Data[0]=='Y'||USART_UART_Data[1]=='Y')
	{
		Remote_State2=0;
//		USART_UART_Printf("停止转弯\n");
	}

	//收到遥控制动
	if(USART_UART_Data[0]=='X')
	{
		Remote_State1=0;
		Remote_State2=0;
//		USART_UART_Printf("制动\n");
	}

	//调整速度等级//低速
	if(USART_UART_Data[0]=='E')
	{
		SpeedLevel=SpeedLevel_Low;
//		USART_UART_Printf("遥控低速\n");
	}
	//调整速度等级//中速
	if(USART_UART_Data[0]=='F')
	{
		SpeedLevel=SpeedLevel_Medium;
//		USART_UART_Printf("遥控中速\n");
	}
	//调整速度等级//高速
	if(USART_UART_Data[0]=='G')
	{
		SpeedLevel=SpeedLevel_High;
//		USART_UART_Printf("遥控高速\n");
	}
}





#endif//Control_H
