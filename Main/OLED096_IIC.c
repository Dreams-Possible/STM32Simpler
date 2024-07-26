#include"OLED096_IIC.h"
#ifdef OLED096_IIC_H


//写命令
void OLED096_Command_IIC(uint8_t Command)
{
	uint8_t Command_Data[2];
	Command_Data[0]=0x00;
	Command_Data[1]=Command;
	IIC_SendData(OLED096_Address,2,Command_Data);
}

//写数据
void OLED096_Data_IIC(uint8_t Data)
{
	uint8_t Data_Data[2];
	Data_Data[0]=0x40;
	Data_Data[1]=Data;
	IIC_SendData(OLED096_Address,2,Data_Data);

}


//屏幕初始化
void OLED096_Initialization_IIC()
{
    OLED096_Command_IIC(0xae);//设置显示关闭

    OLED096_Command_IIC(0xd5);
    OLED096_Command_IIC(0x80);//设置显示分频率/振荡器频率

    OLED096_Command_IIC(0xa8);
    OLED096_Command_IIC(0x3f);//设置复用率

    OLED096_Command_IIC(0xd3);
    OLED096_Command_IIC(0x00);//设置显示偏移量

    OLED096_Command_IIC(0x40);//设置显示起止线

    OLED096_Command_IIC(0xa1);//设置段重映射

    OLED096_Command_IIC(0xc8);//设置com输出扫描方式

    OLED096_Command_IIC(0xda);
    OLED096_Command_IIC(0x12);//设置com引脚硬件配置

    OLED096_Command_IIC(0x81);
    OLED096_Command_IIC(0x66);//设置对比度

    OLED096_Command_IIC(0xd9);
    OLED096_Command_IIC(0xf1);//设置预充电周期

    OLED096_Command_IIC(0xdb);
    OLED096_Command_IIC(0x30);//设置vcomh取消选择等级

    OLED096_Command_IIC(0xa4);//设置全局显示开或关

    OLED096_Command_IIC(0xa6);//设置正常显示或反显

    OLED096_Command_IIC(0x8d);
    OLED096_Command_IIC(0x14);//设置电荷泵

    OLED096_Command_IIC(0xaf);//设置显示开

    //设置为水平地址模式
    //OLED096_SwitchPageMode_IIC(1);
}

//屏幕睡眠（关闭）
void OLED096_Sleep_IIC()
{
	OLED096_Command_IIC(0xae);//设置显示关

	OLED096_Command_IIC(0x8d);
	OLED096_Command_IIC(0x10);//设置电荷泵
}

//屏幕唤醒
void OLED096_Wake_IIC()
{
	OLED096_Command_IIC(0x8d);
	OLED096_Command_IIC(0x14);//设置电荷泵

	OLED096_Command_IIC(0xaf);//设置显示开
}

//设置显示焦点（向下为A轴0-7，向左为B轴0-127）(向右按行扫描刷新，一次扫描8行，128列)
void OLED096_Focus_IIC(uint8_t Axle_A, uint8_t Axle_B)
{
	OLED096_Command_IIC(0xb0|Axle_A);//设置A位置
	OLED096_Command_IIC(0x10|((Axle_B&0xf0)>>4));//设置B位置高4位
	OLED096_Command_IIC(0x00|(Axle_B&0x0f));//设置B位置低4位
}

//设置对比度
void OLED096_ContrastRatio_IIC(uint8_t ContrastRatio)
{
	OLED096_Command_IIC(0x81);
	OLED096_Command_IIC(ContrastRatio);//设置对比度
}

//设置正反显，0正1反
void OLED096_DisplayMode_IIC(uint8_t DisplayMode)
{
	if(DisplayMode==0)
	{
		OLED096_Command_IIC(0xa6);//设置正显
	}else
	{
		OLED096_Command_IIC(0xa7);//设置反显
	}

}

////设置地址模式（0页地址模式1水平地址模式2垂直地址模式）
//void OLED096_SwitchPageMode_IIC(uint8_t PageMode)
//{
//	if(PageMode==0)
//	{
//		OLED096_Command_IIC(0x20);
//		OLED096_Command_IIC(0x10);//页地址模式（默认）
//	}else
//	if(PageMode==1)
//	{
//		OLED096_Command_IIC(0x20);
//		OLED096_Command_IIC(0x00);//水平地址模式
//	}else
//	if(PageMode==2)
//	{
//		OLED096_Command_IIC(0x20);
//		OLED096_Command_IIC(0x01);//垂直地址模式
//	}
//}



//全局刷新（为全黑，0xff为全白）
void OLED096_Refresh_IIC(uint8_t Display)
{
	memset(OLED096_Frame_Data,Display,sizeof(OLED096_Frame_Data));

	//设置数据标志位0x40
	for(uint8_t a=0;a<OLED096_Width/8;++a)
	{
		OLED096_Frame_Data[a][0]=0x40;
	}

    for (uint8_t a=0;a<OLED096_Width/8;++a)
    {
    	OLED096_Focus_IIC(a,0);
        //直接调用更底层的IIC函数连续发送数据更高效
    	IIC_SendData(OLED096_Address,OLED096_Length+1,OLED096_Frame_Data[a]);
    }
}


//OLED096_IIC帧数
uint8_t OLED096_FPS_IIC=0;

//输出缓冲帧
void OLED096_PushFrame_IIC()
{
	//设置数据标志位0x40
	for(uint8_t a=0;a<OLED096_Width/8;++a)
	{
		OLED096_Frame_Data[a][0]=0x40;
	}

    for (uint8_t a=0;a<OLED096_Width/8;++a)
    {
        OLED096_Focus_IIC(a,0);
        //直接调用更底层的IIC函数连续发送数据更高效
    	IIC_SendData(OLED096_Address,OLED096_Length+1,OLED096_Frame_Data[a]);
    }
    ++OLED096_FPS_IIC;
}

//帧数记录
void OLED096_FPSRecord_IIC()
{
	USART_UART_Printf("IICFPS=%d\n",OLED096_FPS_IIC);
	OLED096_FPS_IIC=0;
}

//void OLED096_Round(uint8_t Axle_X,uint8_t Axle_Y,uint8_t Radius,uint8_t Angles,...)
//{
//	uint8_t From_Angle=0;
//	uint8_t To_Angle=360;
//
//	va_list Angle_List;
//	va_start(Angle_List,Angles);
//
//	// 读取可变参数，如果存在的话
//	if(Angles==2)
//	{
//		From_Angle=va_arg(Angle_List,int);
//		To_Angle = va_arg(Angle_List,int);
//	}
//
//	va_end(Angle_List);
//
//	if(Radius>64)
//	{
//		return;
//	}
//	for(uint16_t a=From_Angle;a<To_Angle;a+=4)
//	{
//		OLED096_Point((uint8_t)round(Axle_X+cos(a*M_PI/180.0)*Radius),(uint8_t)round(Axle_Y+sin(a*M_PI/180.0)*Radius));
//		//USART_UART_Printf("x=%d\n",(uint8_t)round(Axle_X+cos(a*M_PI/180.0)*Radius));
//		//USART_UART_Printf("y=%d\n",(uint8_t)round(Axle_Y+sin(a*M_PI/180.0)*Radius));
//	}
//
//}





/*void Polygon(uint8_t CoordinatesXY,...)
{

	va_list XYList;
	va_start(XYList,CoordinatesXY);

	uint8_t From_Y=OLED096_Width-va_arg(XYList,uint8_t);
	uint8_t From_X=va_arg(XYList,uint8_t);

	for(uint8_t a=0;a<(CoordinatesXY-2)/2;a+=2)
	{
		uint8_t To_Y=OLED096_Width-va_arg(XYList,uint8_t);
		uint8_t To_X=va_arg(XYList,uint8_t);
		OLED096_Line(From_Y,From_X,To_Y,To_X);
		From_Y=To_Y;
		From_X=To_X;
	}

	va_end(XYList);

}*/








#endif//OLED096_IIC_H







