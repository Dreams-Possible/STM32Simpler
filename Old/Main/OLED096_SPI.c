#include"OLED096_SPI.h"
#ifdef OLED096_SPI_H



//OLED096写命令
void OLED096_Command_SPI(uint8_t Command)
{
	SPI_OLED096_DC(OLED096_Command);//OLED096写命令标志
	SPI_SendData(1,&Command);//发送数据
}

//OLED096写数据
void OLED096_Data_SPI(uint8_t Data)
{
	SPI_OLED096_DC(OLED096_Data);//OLED096写数据标志
	SPI_SendData(1,&Data);//发送数据
}

//屏幕初始化
void OLED096_Initialization_SPI()
{
    SPI_OLED096_RES(0);
    SPI_OLED096_RES(1);//重置屏幕状态

    OLED096_Command_SPI(0xae);//设置显示关闭

    OLED096_Command_SPI(0xd5);
    OLED096_Command_SPI(0x80);//设置显示分频率/振荡器频率

    OLED096_Command_SPI(0xa8);
    OLED096_Command_SPI(0x3f);//设置复用率

    OLED096_Command_SPI(0xd3);
    OLED096_Command_SPI(0x00);//设置显示偏移量

    OLED096_Command_SPI(0x40);//设置显示起止线

    OLED096_Command_SPI(0xa1);//设置段重映射

    OLED096_Command_SPI(0xc8);//设置com输出扫描方式

    OLED096_Command_SPI(0xda);
    OLED096_Command_SPI(0x12);//设置com引脚硬件配置

    OLED096_Command_SPI(0x81);
    OLED096_Command_SPI(0x66);//设置对比度

    OLED096_Command_SPI(0xd9);
    OLED096_Command_SPI(0xf1);//设置预充电周期

    OLED096_Command_SPI(0xdb);
    OLED096_Command_SPI(0x30);//设置vcomh取消选择等级

    OLED096_Command_SPI(0xa4);//设置全局显示开或关

    OLED096_Command_SPI(0xa6);//设置正常显示或反显

    OLED096_Command_SPI(0x8d);
    OLED096_Command_SPI(0x14);//设置电荷泵

    OLED096_Command_SPI(0xaf);//设置显示开

    //设置为水平地址模式
    //OLED096_SwitchPageMode_SPI(1);
}

//屏幕睡眠（关闭）
void OLED096_Sleep_SPI()
{
	OLED096_Command_SPI(0xae);//设置显示关

	OLED096_Command_SPI(0x8d);
	OLED096_Command_SPI(0x10);//设置电荷泵
}

//屏幕唤醒
void OLED096_Wake_SPI()
{
	OLED096_Command_SPI(0x8d);
	OLED096_Command_SPI(0x14);//设置电荷泵

	OLED096_Command_SPI(0xaf);//设置显示开
}

//设置显示焦点（向下为A轴0-7，向左为B轴0-127）(向右按行扫描刷新，一次扫描8行，128列)
void OLED096_Focus_SPI(uint8_t Axle_A, uint8_t Axle_B)
{
	OLED096_Command_SPI(0xb0|Axle_A);//设置A位置
	OLED096_Command_SPI(0x10|((Axle_B&0xf0)>>4));//设置B位置高4位
	OLED096_Command_SPI(0x00|(Axle_B&0x0f));//设置B位置低4位
}

//设置对比度
void OLED096_ContrastRatio_SPI(uint8_t ContrastRatio)
{
	OLED096_Command_SPI(0x81);
	OLED096_Command_SPI(ContrastRatio);//设置对比度
}

//设置正反显，0正1反
void OLED096_DisplayMode_SPI(uint8_t DisplayMode)
{
	if(DisplayMode==0)
	{
		OLED096_Command_SPI(0xa6);//设置正显
	}else
	{
		OLED096_Command_SPI(0xa7);//设置反显
	}

}

//全局刷新（0x00为全黑，0xff为全白）
void OLED096_Refresh_SPI(uint8_t Display)
{
	memset(OLED096_Frame_Data,Display,sizeof(OLED096_Frame_Data));

    for (uint8_t a=0;a<OLED096_Width/8;++a)
    {
    	OLED096_Focus_SPI(a,0);
		SPI_OLED096_DC(1);//发送写数据
		SPI_SendData(128,OLED096_Frame_Data[a]+1);
    }

}

//OLED096_SPI帧数
uint8_t OLED096_FPS_SPI=0;

//输出缓冲帧
void OLED096_PushFrame_SPI()
{

    for (uint8_t a=0;a<OLED096_Width/8;++a)
    {
    	OLED096_Focus_SPI(a,0);
		SPI_OLED096_DC(1);//发送写数据
		SPI_SendData(128,OLED096_Frame_Data[a]+1);
    }

    ++OLED096_FPS_SPI;
}

//帧数记录
void OLED096_FPSRecord_SPI()
{
	USART_UART_Printf("SPIFPS=%d\n",OLED096_FPS_SPI);
	OLED096_FPS_SPI=0;
}




#endif//OLED096_SPI_H
