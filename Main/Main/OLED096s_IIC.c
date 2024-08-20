#include"OLED096s_IIC.h"
#ifdef OLED096s_IIC_H


//写命令
void OLED0961_IIC_Command(uint8_t Command)
{
	uint8_t Command_Data[2];
	Command_Data[0]=0x00;
	Command_Data[1]=Command;
	OLED0961_IIC_SendData(OLED0961_Address,2,Command_Data);
}

//写数据
void OLED0961_IIC_Data(uint8_t Data)
{
	uint8_t Data_Data[2];
	Data_Data[0]=0x40;
	Data_Data[1]=Data;
	OLED0961_IIC_SendData(OLED0961_Address,2,Data_Data);
}



//屏幕初始化
void OLED0961_IIC_Initialization()
{
    OLED0961_IIC_Command(0xae);//设置显示关闭

    OLED0961_IIC_Command(0xd5);
    OLED0961_IIC_Command(0x80);//设置显示分频率/振荡器频率

    OLED0961_IIC_Command(0xa8);
    OLED0961_IIC_Command(0x3f);//设置复用率

    OLED0961_IIC_Command(0xd3);
    OLED0961_IIC_Command(0x00);//设置显示偏移量

    OLED0961_IIC_Command(0x40);//设置显示起止线

    OLED0961_IIC_Command(0xa1);//设置段重映射

    OLED0961_IIC_Command(0xc8);//设置com输出扫描方式

    OLED0961_IIC_Command(0xda);
    OLED0961_IIC_Command(0x12);//设置com引脚硬件配置

    OLED0961_IIC_Command(0x81);
    OLED0961_IIC_Command(0x66);//设置对比度

    OLED0961_IIC_Command(0xd9);
    OLED0961_IIC_Command(0xf1);//设置预充电周期

    OLED0961_IIC_Command(0xdb);
    OLED0961_IIC_Command(0x30);//设置vcomh取消选择等级

    OLED0961_IIC_Command(0xa4);//设置全局显示开或关

    OLED0961_IIC_Command(0xa6);//设置正常显示或反显

    OLED0961_IIC_Command(0x8d);
    OLED0961_IIC_Command(0x14);//设置电荷泵

    OLED0961_IIC_Command(0xaf);//设置显示开
}


//屏幕睡眠（关闭）
void OLED0961_IIC_Sleep()
{
	OLED0961_IIC_Command(0xae);//设置显示关

	OLED0961_IIC_Command(0x8d);
	OLED0961_IIC_Command(0x10);//设置电荷泵
}

//屏幕唤醒
void OLED0961_IIC_Wake()
{
	OLED0961_IIC_Command(0x8d);
	OLED0961_IIC_Command(0x14);//设置电荷泵

	OLED0961_IIC_Command(0xaf);//设置显示开
}

//设置显示焦点（向下为A轴0-7，向左为B轴0-127）(向右按行扫描刷新，一次扫描8行，128列)
void OLED096_Focus_IIC(uint8_t Axle_A, uint8_t Axle_B)
{
	OLED0961_IIC_Command(0xb0|Axle_A);//设置A位置
	OLED0961_IIC_Command(0x10|((Axle_B&0xf0)>>4));//设置B位置高4位
	OLED0961_IIC_Command(0x00|(Axle_B&0x0f));//设置B位置低4位
}

//设置对比度
void OLED0961_IIC_ContrastRatio(uint8_t ContrastRatio)
{
	OLED0961_IIC_Command(0x81);
	OLED0961_IIC_Command(ContrastRatio);//设置对比度
}

//设置正反显，0正1反
void OLED0961_IIC_DisplayMode(uint8_t DisplayMode)
{
	if(DisplayMode==0)
	{
		OLED0961_IIC_Command(0xa6);//设置正显
	}else
	{
		OLED0961_IIC_Command(0xa7);//设置反显
	}

}

////设置地址模式（0页地址模式1水平地址模式2垂直地址模式）
//void OLED096_SwitchPageMode_IIC(uint8_t PageMode)
//{
//	if(PageMode==0)
//	{
//		OLED0961_IIC_Command(0x20);
//		OLED0961_IIC_Command(0x10);//页地址模式（默认）
//	}else
//	if(PageMode==1)
//	{
//		OLED0961_IIC_Command(0x20);
//		OLED0961_IIC_Command(0x00);//水平地址模式
//	}else
//	if(PageMode==2)
//	{
//		OLED0961_IIC_Command(0x20);
//		OLED0961_IIC_Command(0x01);//垂直地址模式
//	}
//}



//全局刷新（为全黑，0xff为全白）
void OLED0961_IIC_Refresh(uint8_t Display)
{
	memset(OLED0961_IIC_Frame_Data,Display,sizeof(OLED0961_IIC_Frame_Data));

	//设置数据标志位0x40
	for(uint8_t a=0;a<OLED0961_IIC_Width/8;++a)
	{
		OLED0961_IIC_Frame_Data[a][0]=0x40;
	}

    for (uint8_t a=0;a<OLED0961_IIC_Width/8;++a)
    {
    	OLED096_Focus_IIC(a,0);
        //直接调用更底层的IIC函数连续发送数据更高效
    	OLED0961_IIC_SendData(OLED0961_Address,OLED0961_IIC_Length+1,OLED0961_IIC_Frame_Data[a]);
    }
}



//输出缓冲帧
void OLED0961_IIC_PushFrame()
{
	//设置数据标志位0x40
	for(uint8_t a=0;a<OLED0961_IIC_Width/8;++a)
	{
		OLED0961_IIC_Frame_Data[a][0]=0x40;
	}

    for (uint8_t a=0;a<OLED0961_IIC_Width/8;++a)
    {
        OLED096_Focus_IIC(a,0);
        //直接调用更底层的IIC函数连续发送数据更高效
        OLED0961_IIC_SendData(OLED0961_Address,OLED0961_IIC_Length+1,OLED0961_IIC_Frame_Data[a]);
    }
}




#endif//OLED096_IIC_H







