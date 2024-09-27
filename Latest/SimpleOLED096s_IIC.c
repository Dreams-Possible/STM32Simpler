#include"SimpleOLED096s_IIC.h"
#ifdef SimpleOLED096s_IIC_H

#ifdef IICs_H


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

//设置显示焦点（向下为A轴0-7，向左为B轴0-127）(向右按行扫描刷新，一次扫描8行，128列)
void OLED0961_IIC_Focus(uint8_t A, uint8_t B)
{
	OLED0961_IIC_Command(0xb0|A);//设置A位置
	OLED0961_IIC_Command(0x10|((B&0xf0)>>4));//设置B位置高4位
	OLED0961_IIC_Command(0x00|(B&0x0f));//设置B位置低4位
}

//全局刷新
void OLED0961_IIC_Refresh()
{
	for(uint8_t a=0;a<8;++a)
	{
		OLED0961_IIC_Focus(a, 0);
		for(uint8_t b=0;b<128;++b)
		{
			//0x00为全黑，0xff为全白
			OLED0961_IIC_Data(0x00);
		}
	}
}



//字符串模式
#ifdef OLED0961_IIC_CharacterStringMode
//固定位置显示字符串
//位置：行数：1-8；列数：1-128，字符串
void OLED0961_IIC_CharacterString(uint8_t Axle_A,uint8_t Axle_B,char*CharacterString,...)
{
	--Axle_A;
	--Axle_B;
	//最大容纳32个字符，实际限制为16个字符
    uint8_t StringData[32]=
    		{
    				0,
    		};

    //使用可变参数列表
    va_list args;
    va_start(args,CharacterString);

    //将参数传递给sprintf函数
    vsprintf((char*)StringData,(char*)CharacterString,args);

    //结束可变参数列表
    va_end(args);

    //扫描连续两行，每行高8像素
    for(uint8_t a=0;a<2;++a)
	{
    	//显示焦点定位
		OLED0961_IIC_Focus(Axle_A+a,Axle_B);
		//分别发送字符串的上下两部分
		for(uint8_t b=0;b<strlen((char*)StringData);++b)
		{
			//发送一个字的宽度
			for(uint8_t c=0;c<8;++c)
			{
				OLED0961_IIC_Data(OLED096_Character_ASCII_1608[StringData[b]-' '][c+a*8]);
			}
		}
	}
}
#endif//OLED0961_IIC_CharacterStringMode




//Printf模式
#ifdef OLED0961_IIC_PrintfMode


void OLED0961_IIC_Printf(const char *CharacterString,...)
{
	static uint8_t Axle_A=0;
	static uint8_t Axle_B=0;

	uint8_t StringData[32];//最大容纳32个字符，实际限制为16个字符
	//使用可变参数列表
	va_list args;
	va_start(args,CharacterString);
	//将参数传递给sprintf函数
	vsprintf((char*)StringData,(char*)CharacterString,args);
	//结束可变参数列表
	va_end(args);

	//用空格填充一行
	uint8_t CharacterNumber=strlen((char*)StringData);
	for(uint8_t a=CharacterNumber;a<16;++a)
	{
		StringData[a]=' ';
	}
	StringData[16]='\0';

	//扫描连续两行，每行高8像素
	for(uint8_t a=0;a<2;++a)
	{
		//显示焦点定位
		OLED0961_IIC_Focus(Axle_A+a,Axle_B);
		//分别发送字符串的上下两部分
		for(uint8_t b=0;b<16;++b)
		{
			//发送一个字的宽度
			for(uint8_t c=0;c<8;++c)
			{
				OLED0961_IIC_Data(OLED096_Character_ASCII_1608[StringData[b]-' '][c+a*8]);
			}
		}
	}

	if(Axle_A>=8)
	{
		Axle_A=0;
	}else
	{
		Axle_A+=2;
	}

}


#endif//OLED0961_IIC_PrintfMode


#endif//IICs_H
#endif//SimpleOLED096s_IIC_H
