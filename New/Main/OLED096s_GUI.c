#include"OLED096s_GUI.h"
#ifdef OLED096s_GUI_H

#if defined(OLED096s_IIC_H)||defined(OLED096s_SPI_H)



//缓冲帧数据区
//已包含数据标志位0x40
uint8_t OLED0961_GUI_Frame_Data[OLED0961_GUI_Width/8][OLED0961_GUI_Length+1]=
	{
		0,
	};


//缓冲帧初始化
void OLED0961_GUI_FrameReset()
{
	memset(OLED0961_GUI_Frame_Data,0,sizeof(OLED0961_GUI_Frame_Data));
//	//设置数据标志位0x40
//	for(uint8_t a=0;a<OLED0961_GUI_Width/8;++a)
//	{
//		OLED0961_GUI_Frame_Data[a][0]=0x40;
//	}
}


//绘制点（给出标准平面直角坐标系下的XY坐标）
void OLED0961_GUI_Point(uint8_t Axle_X,uint8_t Axle_Y)
{
	if(Axle_X>OLED0961_GUI_Length)
	{
		return;
	}
	if(Axle_Y>OLED0961_GUI_Width)
	{
		return;
	}

	uint8_t Axle_A=OLED0961_GUI_Width-Axle_Y;
	uint8_t Axle_B=Axle_X;

	OLED0961_GUI_Frame_Data[Axle_A/8][Axle_B]|=(0x01<<(Axle_A%8));
	//OLED0961_GUI_Frame_Data[2][32]=0xff;
}

//绘制线（给出起点坐标和终点坐标）
void OLED0961_GUI_Line(uint8_t From_X,uint8_t From_Y,uint8_t To_X,uint8_t To_Y)
{

	uint8_t Axle_X=From_X;
	uint8_t Axle_Y=From_Y;

	if((From_Y-To_Y)==0)//说明直线垂直于x轴
	{
		if(From_X<To_X)//说明直线走向斜向上
		{
			OLED0961_GUI_Point(Axle_X,Axle_Y);
			while(Axle_X<To_X)
			{
				Axle_X+=1;
				OLED0961_GUI_Point(Axle_X,Axle_Y);
			}
		}else//说明直线走向斜向下
		{
			OLED0961_GUI_Point(Axle_X,Axle_Y);
			while(Axle_X>To_X)
			{
				Axle_X-=1;
				OLED0961_GUI_Point(Axle_X,Axle_Y);
			}
		}
	}else
	{
		//计算斜率和截距
		float Slope=(float)(From_X-To_X)/(From_Y-To_Y);
		float Intercept=(float)((From_X+To_X)/2)-Slope*(From_Y+To_Y)/2;
		//USART_UART_Printf("S=%.2f\n",Slope);
		//USART_UART_Printf("I=%.2f\n",Intercept);

		if(fabs(Slope)<=1)//如果斜率的绝对值小于等于1，以x为基准
		{
			if(From_Y<To_Y)//说明直线走向斜向上
			{
				OLED0961_GUI_Point(Axle_X,Axle_Y);
				while(Axle_Y<To_Y)
				{
					Axle_Y+=1;
					Axle_X=(uint8_t)round(Axle_Y*Slope+Intercept);
					OLED0961_GUI_Point(Axle_X,Axle_Y);
					//USART_UART_Printf("A=%d,B=%d\n",Axle_Y,Axle_X);
				}
			}else//说明直线走向斜向下
			{
				OLED0961_GUI_Point(Axle_X,Axle_Y);
				while(Axle_Y>To_Y)
				{
					Axle_Y-=1;
					Axle_X=(uint8_t)round(Axle_Y*Slope+Intercept);
					OLED0961_GUI_Point(Axle_X,Axle_Y);
				}
			}
		}else//如果斜率的绝对值大于1，以y为基准
		{
			if(From_X<To_X)//说明直线走向斜向上
			{
				OLED0961_GUI_Point(Axle_X,Axle_Y);
				while(Axle_X<To_X)
				{
					Axle_X+=1;
					Axle_Y=(uint8_t)round((Axle_X-Intercept)/Slope);
					OLED0961_GUI_Point(Axle_X,Axle_Y);
				}

			}else//说明直线走向斜向下
			{
				OLED0961_GUI_Point(Axle_X,Axle_Y);
				while(Axle_X>To_X)
				{
					Axle_X-=1;
					Axle_Y=(uint8_t)round((Axle_X-Intercept)/Slope);
					OLED0961_GUI_Point(Axle_X,Axle_Y);
				}
			}
		}
	}
}

//绘制三角形（给出三个点的XY坐标）
void OLED0961_GUI_Triangle(uint8_t Point1_X,uint8_t Point1_Y,uint8_t Point2_X,uint8_t Point2_Y,uint8_t Point3_X,uint8_t Point3_Y)
{
	OLED0961_GUI_Line(Point1_X,Point1_Y,Point2_X,Point2_Y);
	OLED0961_GUI_Line(Point2_X,Point2_Y,Point3_X,Point3_Y);
	OLED0961_GUI_Line(Point3_X,Point3_Y,Point1_X,Point1_Y);
}

//绘制四边形（以以此给出四个点的XY坐标）
void OLED0961_GUI_Quadrilateral(uint8_t Point1_X,uint8_t Point1_Y,uint8_t Point2_X,uint8_t Point2_Y,uint8_t Point3_X,uint8_t Point3_Y,uint8_t Point4_X,uint8_t Point4_Y)
{
	OLED0961_GUI_Line(Point1_X,Point1_Y,Point2_X,Point2_Y);
	OLED0961_GUI_Line(Point2_X,Point2_Y,Point3_X,Point3_Y);
	OLED0961_GUI_Line(Point3_X,Point3_Y,Point4_X,Point4_Y);
	OLED0961_GUI_Line(Point4_X,Point4_Y,Point1_X,Point1_Y);
}

//绘制圆型（给出圆心XY坐标，半径，起始角度和结束角度）
void OLED0961_GUI_Round(uint8_t Axle_X,uint8_t Axle_Y,uint8_t Radius,uint16_t From_Angle,uint16_t To_Angle)
{

	if(Radius>128)
	{
		return;
	}
//	if(From_Angle>360)
//	{
//		From_Angle%=360;
//	}
//	if(To_Angle>360)
//	{
//		To_Angle%=360;
//	}
	for(uint16_t a=From_Angle;a<To_Angle;a++)
	{
		OLED0961_GUI_Point((uint8_t)round(Axle_X+cos(a*M_PI/180.0)*Radius),(uint8_t)round(Axle_Y+sin(a*M_PI/180.0)*Radius));
	}

}



//将一个Bit嵌入两个Bits之间
//AND_NOR为0代表或，为1代表全覆盖
void BitImplant(uint8_t FromBit,uint8_t*RawBit1,uint8_t*RawBit2,uint8_t*GoalBit,uint8_t AND_NOR)
{

    if(FromBit>8)
    {
        return;
    }

	if(AND_NOR==0)
	{
		*RawBit1|=(*GoalBit>>(8-FromBit));
		*RawBit2|=(*GoalBit<<FromBit);
	}else
	{
        *RawBit1&=~((uint8_t)0xFF>>(FromBit));
        *RawBit1|=(*GoalBit>>(8-FromBit));
        *RawBit2&=~((uint8_t)0xFF<<(8-FromBit));
        *RawBit2|=(*GoalBit<<FromBit);
	}


}


//显示字符（起点左上角XY坐标，字符串）
void OLED0961_GUI_Characters(uint8_t Axle_X,uint8_t Axle_Y,const char *CharacterString,...)
{

	if(Axle_X>OLED0961_GUI_Length)
	{
		return;
	}
	if(Axle_Y>OLED0961_GUI_Width)
	{
		return;
	}
	uint8_t Axle_A=OLED0961_GUI_Width-Axle_Y;
	uint8_t Axle_B=Axle_X;

	//最大暂定32个字符
	uint8_t StringData[32]=
		{
			0
		};
	//使用可变参数列表
	va_list args;
	va_start(args,CharacterString);
	//将参数传递给vsprintf函数
	vsprintf((char*)StringData,(char*)CharacterString,args);
	//结束可变参数列表
	va_end(args);

	//显字
	for(uint8_t a=0;a<strlen((char*)StringData);++a)//一共多少个字
	{

		for(uint8_t b=0;b<OLED0961_GUI_CharacterWidth;++b)//字宽
		{
			for(uint8_t c=0;c<OLED0961_GUI_CharacterHeight/8;++c)//考虑字高大于8
			{
				BitImplant(Axle_A%8,&OLED0961_GUI_Frame_Data[Axle_A/8+c+1][Axle_B+b+OLED0961_GUI_CharacterWidth*a],&OLED0961_GUI_Frame_Data[(Axle_A/8)+c][Axle_B+b+OLED0961_GUI_CharacterWidth*a],(uint8_t*)&OLED096_Character_ASCII_1608[StringData[a]-' '][b+c*8],0);
			}
			//BitImplant(Axle_A%8,&OLED0961_GUI_Frame_Data[Axle_A/8+1][Axle_B+b+8*a],&OLED0961_GUI_Frame_Data[(Axle_A/8)][Axle_B+b+8*a],(uint8_t*)&OLED096_Character_ASCII_1608[StringData[a]-' '][b],0);
			//BitImplant(Axle_A%8,&OLED0961_GUI_Frame_Data[Axle_A/8+2][Axle_B+b+8*a],&OLED0961_GUI_Frame_Data[(Axle_A/8)+1][Axle_B+b+8*a],(uint8_t*)&OLED096_Character_ASCII_1608[StringData[a]-' '][b+8],0);
		}
	}
}


#endif//defined(OLED096_IIC_H)||defined(OLED096_SPI_H)
#endif//OLED096_GUI_H
