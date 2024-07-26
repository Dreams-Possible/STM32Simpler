#include"OLED096_GUI.h"
#ifdef OLED096_GUI_H

#if defined(OLED096_IIC_H)||defined(OLED096_SPI_H)



//字典（字体大小1608）
//取模方式：阴码，列行式，逆向（低位在前）
const uint8_t OLED096_Character_ASCII_1608[95][16]=
{
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*" ",0*/

	{0x00,0x00,0x00,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x33,0x00,0x00,0x00,0x00},/*"!",1*/

	{0x00,0x10,0x0C,0x02,0x10,0x0C,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*""",2*/

	{0x00,0x40,0xC0,0x78,0x40,0xC0,0x78,0x00,0x00,0x04,0x3F,0x04,0x04,0x3F,0x04,0x00},/*"#",3*/

	{0x00,0x70,0x88,0x88,0xFC,0x08,0x30,0x00,0x00,0x18,0x20,0x20,0xFF,0x21,0x1E,0x00},/*"$",4*/

	{0xF0,0x08,0xF0,0x80,0x60,0x18,0x00,0x00,0x00,0x31,0x0C,0x03,0x1E,0x21,0x1E,0x00},/*"%",5*/

	{0x00,0xF0,0x08,0x88,0x70,0x00,0x00,0x00,0x1E,0x21,0x23,0x2C,0x19,0x27,0x21,0x10},/*"&",6*/

	{0x00,0x12,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"'",7*/

	{0x00,0x00,0x00,0xE0,0x18,0x04,0x02,0x00,0x00,0x00,0x00,0x07,0x18,0x20,0x40,0x00},/*"(",8*/

	{0x00,0x02,0x04,0x18,0xE0,0x00,0x00,0x00,0x00,0x40,0x20,0x18,0x07,0x00,0x00,0x00},/*")",9*/

	{0x40,0x40,0x80,0xF0,0x80,0x40,0x40,0x00,0x02,0x02,0x01,0x0F,0x01,0x02,0x02,0x00},/*"*",10*/

	{0x00,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x0F,0x01,0x01,0x01},/*"+",11*/

	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x90,0x70,0x00,0x00,0x00,0x00,0x00},/*",",12*/

	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x00},/*"-",13*/

	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x00,0x00,0x00},/*".",14*/

	{0x00,0x00,0x00,0x00,0xC0,0x38,0x04,0x00,0x00,0x60,0x18,0x07,0x00,0x00,0x00,0x00},/*"/",15*/

	{0x00,0xE0,0x10,0x08,0x08,0x10,0xE0,0x00,0x00,0x0F,0x10,0x20,0x20,0x10,0x0F,0x00},/*"0",16*/

	{0x00,0x00,0x10,0x10,0xF8,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00},/*"1",17*/

	{0x00,0x70,0x08,0x08,0x08,0x08,0xF0,0x00,0x00,0x30,0x28,0x24,0x22,0x21,0x30,0x00},/*"2",18*/

	{0x00,0x30,0x08,0x08,0x08,0x88,0x70,0x00,0x00,0x18,0x20,0x21,0x21,0x22,0x1C,0x00},/*"3",19*/

	{0x00,0x00,0x80,0x40,0x30,0xF8,0x00,0x00,0x00,0x06,0x05,0x24,0x24,0x3F,0x24,0x24},/*"4",20*/

	{0x00,0xF8,0x88,0x88,0x88,0x08,0x08,0x00,0x00,0x19,0x20,0x20,0x20,0x11,0x0E,0x00},/*"5",21*/

	{0x00,0xE0,0x10,0x88,0x88,0x90,0x00,0x00,0x00,0x0F,0x11,0x20,0x20,0x20,0x1F,0x00},/*"6",22*/

	{0x00,0x18,0x08,0x08,0x88,0x68,0x18,0x00,0x00,0x00,0x00,0x3E,0x01,0x00,0x00,0x00},/*"7",23*/

	{0x00,0x70,0x88,0x08,0x08,0x88,0x70,0x00,0x00,0x1C,0x22,0x21,0x21,0x22,0x1C,0x00},/*"8",24*/

	{0x00,0xF0,0x08,0x08,0x08,0x10,0xE0,0x00,0x00,0x01,0x12,0x22,0x22,0x11,0x0F,0x00},/*"9",25*/

	{0x00,0x00,0x00,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x00},/*":",26*/

	{0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0x00},/*";",27*/

	{0x00,0x00,0x80,0x40,0x20,0x10,0x08,0x00,0x00,0x01,0x02,0x04,0x08,0x10,0x20,0x00},/*"<",28*/

	{0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x02,0x02,0x02,0x02,0x02,0x02,0x00},/*"=",29*/

	{0x00,0x08,0x10,0x20,0x40,0x80,0x00,0x00,0x00,0x20,0x10,0x08,0x04,0x02,0x01,0x00},/*">",30*/

	{0x00,0x70,0x48,0x08,0x08,0x88,0x70,0x00,0x00,0x00,0x00,0x30,0x37,0x00,0x00,0x00},/*"?",31*/

	{0xC0,0x30,0xC8,0x28,0xE8,0x10,0xE0,0x00,0x07,0x18,0x27,0x28,0x2F,0x28,0x17,0x00},/*"@",32*/

	{0x00,0x00,0xC0,0x38,0xE0,0x00,0x00,0x00,0x20,0x3C,0x23,0x02,0x02,0x27,0x38,0x20},/*"A",33*/

	{0x08,0xF8,0x88,0x88,0x88,0x70,0x00,0x00,0x20,0x3F,0x20,0x20,0x20,0x11,0x0E,0x00},/*"B",34*/

	{0xC0,0x30,0x08,0x08,0x08,0x08,0x38,0x00,0x07,0x18,0x20,0x20,0x20,0x10,0x08,0x00},/*"C",35*/

	{0x08,0xF8,0x08,0x08,0x08,0x10,0xE0,0x00,0x20,0x3F,0x20,0x20,0x20,0x10,0x0F,0x00},/*"D",36*/

	{0x08,0xF8,0x88,0x88,0xE8,0x08,0x10,0x00,0x20,0x3F,0x20,0x20,0x23,0x20,0x18,0x00},/*"E",37*/

	{0x08,0xF8,0x88,0x88,0xE8,0x08,0x10,0x00,0x20,0x3F,0x20,0x00,0x03,0x00,0x00,0x00},/*"F",38*/

	{0xC0,0x30,0x08,0x08,0x08,0x38,0x00,0x00,0x07,0x18,0x20,0x20,0x22,0x1E,0x02,0x00},/*"G",39*/

	{0x08,0xF8,0x08,0x00,0x00,0x08,0xF8,0x08,0x20,0x3F,0x21,0x01,0x01,0x21,0x3F,0x20},/*"H",40*/

	{0x00,0x08,0x08,0xF8,0x08,0x08,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00},/*"I",41*/

	{0x00,0x00,0x08,0x08,0xF8,0x08,0x08,0x00,0xC0,0x80,0x80,0x80,0x7F,0x00,0x00,0x00},/*"J",42*/

	{0x08,0xF8,0x88,0xC0,0x28,0x18,0x08,0x00,0x20,0x3F,0x20,0x01,0x26,0x38,0x20,0x00},/*"K",43*/

	{0x08,0xF8,0x08,0x00,0x00,0x00,0x00,0x00,0x20,0x3F,0x20,0x20,0x20,0x20,0x30,0x00},/*"L",44*/

	{0x08,0xF8,0xF8,0x00,0xF8,0xF8,0x08,0x00,0x20,0x3F,0x01,0x3E,0x01,0x3F,0x20,0x00},/*"M",45*/

	{0x08,0xF8,0x30,0xC0,0x00,0x08,0xF8,0x08,0x20,0x3F,0x20,0x00,0x07,0x18,0x3F,0x00},/*"N",46*/

	{0xE0,0x10,0x08,0x08,0x08,0x10,0xE0,0x00,0x0F,0x10,0x20,0x20,0x20,0x10,0x0F,0x00},/*"O",47*/

	{0x08,0xF8,0x08,0x08,0x08,0x08,0xF0,0x00,0x20,0x3F,0x21,0x01,0x01,0x01,0x00,0x00},/*"P",48*/

	{0xE0,0x10,0x08,0x08,0x08,0x10,0xE0,0x00,0x0F,0x10,0x28,0x28,0x30,0x50,0x4F,0x00},/*"Q",49*/

	{0x08,0xF8,0x88,0x88,0x88,0x88,0x70,0x00,0x20,0x3F,0x20,0x00,0x03,0x0C,0x30,0x20},/*"R",50*/

	{0x00,0x70,0x88,0x08,0x08,0x08,0x38,0x00,0x00,0x38,0x20,0x21,0x21,0x22,0x1C,0x00},/*"S",51*/

	{0x18,0x08,0x08,0xF8,0x08,0x08,0x18,0x00,0x00,0x00,0x20,0x3F,0x20,0x00,0x00,0x00},/*"T",52*/

	{0x08,0xF8,0x08,0x00,0x00,0x08,0xF8,0x08,0x00,0x1F,0x20,0x20,0x20,0x20,0x1F,0x00},/*"U",53*/

	{0x08,0x78,0x88,0x00,0x00,0xC8,0x38,0x08,0x00,0x00,0x07,0x38,0x0E,0x01,0x00,0x00},/*"V",54*/

	{0x08,0xF8,0x00,0xF8,0x00,0xF8,0x08,0x00,0x00,0x03,0x3E,0x01,0x3E,0x03,0x00,0x00},/*"W",55*/

	{0x08,0x18,0x68,0x80,0x80,0x68,0x18,0x08,0x20,0x30,0x2C,0x03,0x03,0x2C,0x30,0x20},/*"X",56*/

	{0x08,0x38,0xC8,0x00,0xC8,0x38,0x08,0x00,0x00,0x00,0x20,0x3F,0x20,0x00,0x00,0x00},/*"Y",57*/

	{0x10,0x08,0x08,0x08,0xC8,0x38,0x08,0x00,0x20,0x38,0x26,0x21,0x20,0x20,0x18,0x00},/*"Z",58*/

	{0x00,0x00,0x00,0xFE,0x02,0x02,0x02,0x00,0x00,0x00,0x00,0x7F,0x40,0x40,0x40,0x00},/*"[",59*/

	{0x00,0x04,0x38,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x06,0x38,0xC0,0x00},/*"\",60*/

	{0x00,0x02,0x02,0x02,0xFE,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x7F,0x00,0x00,0x00},/*"]",61*/

	{0x00,0x00,0x04,0x02,0x02,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"^",62*/

	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},/*"_",63*/

	{0x00,0x02,0x02,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"`",64*/

	{0x00,0x00,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x19,0x24,0x24,0x12,0x3F,0x20,0x00},/*"a",65*/

	{0x10,0xF0,0x00,0x80,0x80,0x00,0x00,0x00,0x00,0x3F,0x11,0x20,0x20,0x11,0x0E,0x00},/*"b",66*/

	{0x00,0x00,0x00,0x80,0x80,0x80,0x00,0x00,0x00,0x0E,0x11,0x20,0x20,0x20,0x11,0x00},/*"c",67*/

	{0x00,0x00,0x80,0x80,0x80,0x90,0xF0,0x00,0x00,0x1F,0x20,0x20,0x20,0x10,0x3F,0x20},/*"d",68*/

	{0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x1F,0x24,0x24,0x24,0x24,0x17,0x00},/*"e",69*/

	{0x00,0x80,0x80,0xE0,0x90,0x90,0x20,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00},/*"f",70*/

	{0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x6B,0x94,0x94,0x94,0x93,0x60,0x00},/*"g",71*/

	{0x10,0xF0,0x00,0x80,0x80,0x80,0x00,0x00,0x20,0x3F,0x21,0x00,0x00,0x20,0x3F,0x20},/*"h",72*/

	{0x00,0x80,0x98,0x98,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00},/*"i",73*/

	{0x00,0x00,0x00,0x80,0x98,0x98,0x00,0x00,0x00,0xC0,0x80,0x80,0x80,0x7F,0x00,0x00},/*"j",74*/

	{0x10,0xF0,0x00,0x00,0x80,0x80,0x80,0x00,0x20,0x3F,0x24,0x06,0x29,0x30,0x20,0x00},/*"k",75*/

	{0x00,0x10,0x10,0xF8,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00},/*"l",76*/

	{0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x20,0x3F,0x20,0x00,0x3F,0x20,0x00,0x3F},/*"m",77*/

	{0x80,0x80,0x00,0x80,0x80,0x80,0x00,0x00,0x20,0x3F,0x21,0x00,0x00,0x20,0x3F,0x20},/*"n",78*/

	{0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x1F,0x20,0x20,0x20,0x20,0x1F,0x00},/*"o",79*/

	{0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0x80,0xFF,0x91,0x20,0x20,0x11,0x0E,0x00},/*"p",80*/

	{0x00,0x00,0x00,0x80,0x80,0x00,0x80,0x00,0x00,0x0E,0x11,0x20,0x20,0x91,0xFF,0x80},/*"q",81*/

	{0x80,0x80,0x80,0x00,0x80,0x80,0x80,0x00,0x20,0x20,0x3F,0x21,0x20,0x00,0x01,0x00},/*"r",82*/

	{0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x33,0x24,0x24,0x24,0x24,0x19,0x00},/*"s",83*/

	{0x00,0x80,0x80,0xE0,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x1F,0x20,0x20,0x10,0x00},/*"t",84*/

	{0x80,0x80,0x00,0x00,0x00,0x80,0x80,0x00,0x00,0x1F,0x20,0x20,0x20,0x10,0x3F,0x20},/*"u",85*/

	{0x80,0x80,0x80,0x00,0x80,0x80,0x80,0x00,0x00,0x03,0x0C,0x30,0x0C,0x03,0x00,0x00},/*"v",86*/

	{0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x01,0x0E,0x30,0x0C,0x07,0x38,0x06,0x01},/*"w",87*/

	{0x00,0x80,0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x20,0x31,0x0E,0x2E,0x31,0x20,0x00},/*"x",88*/

	{0x80,0x80,0x80,0x00,0x00,0x80,0x80,0x80,0x00,0x81,0x86,0x78,0x18,0x06,0x01,0x00},/*"y",89*/

	{0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x21,0x30,0x2C,0x22,0x21,0x30,0x00},/*"z",90*/

	{0x00,0x00,0x00,0x00,0x00,0xFC,0x02,0x02,0x00,0x00,0x00,0x00,0x01,0x3E,0x40,0x40},/*"{",91*/

	{0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00},/*"|",92*/

	{0x02,0x02,0xFC,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x3E,0x01,0x00,0x00,0x00,0x00},/*"}",93*/

	{0x00,0x02,0x01,0x02,0x02,0x04,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"~",94*/

};


//缓冲帧数据区
//已包含数据标志位0x40
uint8_t OLED096_Frame_Data[OLED096_Width/8][OLED096_Length+1]=
	{
		0,
	};


//缓冲帧初始化
void OLED096_FrameReset()
{
	memset(OLED096_Frame_Data,0,sizeof(OLED096_Frame_Data));
//	//设置数据标志位0x40
//	for(uint8_t a=0;a<OLED096_Width/8;++a)
//	{
//		OLED096_Frame_Data[a][0]=0x40;
//	}
}


//绘制点（给出标准平面直角坐标系下的XY坐标）
void OLED096_Point(uint8_t Axle_X,uint8_t Axle_Y)
{
	if(Axle_X>OLED096_Length)
	{
		return;
	}
	if(Axle_Y>OLED096_Width)
	{
		return;
	}

	uint8_t Axle_A=OLED096_Width-Axle_Y;
	uint8_t Axle_B=Axle_X;

	OLED096_Frame_Data[Axle_A/8][Axle_B]|=(0x01<<(Axle_A%8));
	//OLED096_Frame_Data[2][32]=0xff;
}

//绘制线（给出起点坐标和终点坐标）
void OLED096_Line(uint8_t From_X,uint8_t From_Y,uint8_t To_X,uint8_t To_Y)
{

	uint8_t Axle_X=From_X;
	uint8_t Axle_Y=From_Y;

	if((From_Y-To_Y)==0)//说明直线垂直于x轴
	{
		if(From_X<To_X)//说明直线走向斜向上
		{
			OLED096_Point(Axle_X,Axle_Y);
			while(Axle_X<To_X)
			{
				Axle_X+=1;
				OLED096_Point(Axle_X,Axle_Y);
			}
		}else//说明直线走向斜向下
		{
			OLED096_Point(Axle_X,Axle_Y);
			while(Axle_X>To_X)
			{
				Axle_X-=1;
				OLED096_Point(Axle_X,Axle_Y);
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
				OLED096_Point(Axle_X,Axle_Y);
				while(Axle_Y<To_Y)
				{
					Axle_Y+=1;
					Axle_X=(uint8_t)round(Axle_Y*Slope+Intercept);
					OLED096_Point(Axle_X,Axle_Y);
					//USART_UART_Printf("A=%d,B=%d\n",Axle_Y,Axle_X);
				}
			}else//说明直线走向斜向下
			{
				OLED096_Point(Axle_X,Axle_Y);
				while(Axle_Y>To_Y)
				{
					Axle_Y-=1;
					Axle_X=(uint8_t)round(Axle_Y*Slope+Intercept);
					OLED096_Point(Axle_X,Axle_Y);
				}
			}
		}else//如果斜率的绝对值大于1，以y为基准
		{
			if(From_X<To_X)//说明直线走向斜向上
			{
				OLED096_Point(Axle_X,Axle_Y);
				while(Axle_X<To_X)
				{
					Axle_X+=1;
					Axle_Y=(uint8_t)round((Axle_X-Intercept)/Slope);
					OLED096_Point(Axle_X,Axle_Y);
				}

			}else//说明直线走向斜向下
			{
				OLED096_Point(Axle_X,Axle_Y);
				while(Axle_X>To_X)
				{
					Axle_X-=1;
					Axle_Y=(uint8_t)round((Axle_X-Intercept)/Slope);
					OLED096_Point(Axle_X,Axle_Y);
				}
			}
		}
	}
}

//绘制三角形（给出三个点的XY坐标）
void OLED096_Triangle(uint8_t Point1_X,uint8_t Point1_Y,uint8_t Point2_X,uint8_t Point2_Y,uint8_t Point3_X,uint8_t Point3_Y)
{
	OLED096_Line(Point1_X,Point1_Y,Point2_X,Point2_Y);
	OLED096_Line(Point2_X,Point2_Y,Point3_X,Point3_Y);
	OLED096_Line(Point3_X,Point3_Y,Point1_X,Point1_Y);
}

//绘制四边形（以以此给出四个点的XY坐标）
void OLED096_Quadrilateral(uint8_t Point1_X,uint8_t Point1_Y,uint8_t Point2_X,uint8_t Point2_Y,uint8_t Point3_X,uint8_t Point3_Y,uint8_t Point4_X,uint8_t Point4_Y)
{
	OLED096_Line(Point1_X,Point1_Y,Point2_X,Point2_Y);
	OLED096_Line(Point2_X,Point2_Y,Point3_X,Point3_Y);
	OLED096_Line(Point3_X,Point3_Y,Point4_X,Point4_Y);
	OLED096_Line(Point4_X,Point4_Y,Point1_X,Point1_Y);
}

//绘制圆型（给出圆心XY坐标，半径，起始角度和结束角度）
void OLED096_Round(uint8_t Axle_X,uint8_t Axle_Y,uint8_t Radius,uint16_t From_Angle,uint16_t To_Angle)
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
	for(uint16_t a=From_Angle;a<To_Angle;a+=4)
	{
		OLED096_Point((uint8_t)round(Axle_X+cos(a*M_PI/180.0)*Radius),(uint8_t)round(Axle_Y+sin(a*M_PI/180.0)*Radius));
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
void OLED096_Characters(uint8_t Axle_X,uint8_t Axle_Y,const char *CharacterString,...)
{

	if(Axle_X>OLED096_Length)
	{
		return;
	}
	if(Axle_Y>OLED096_Width)
	{
		return;
	}
	uint8_t Axle_A=OLED096_Width-Axle_Y;
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

		for(uint8_t b=0;b<CharacterWidth;++b)//字宽
		{
			for(uint8_t c=0;c<CharacterHeight/8;++c)//考虑字高大于8
			{
				BitImplant(Axle_A%8,&OLED096_Frame_Data[Axle_A/8+c+1][Axle_B+b+CharacterWidth*a],&OLED096_Frame_Data[(Axle_A/8)+c][Axle_B+b+CharacterWidth*a],(uint8_t*)&OLED096_Character_ASCII_1608[StringData[a]-' '][b+c*8],0);
			}
			//BitImplant(Axle_A%8,&OLED096_Frame_Data[Axle_A/8+1][Axle_B+b+8*a],&OLED096_Frame_Data[(Axle_A/8)][Axle_B+b+8*a],(uint8_t*)&OLED096_Character_ASCII_1608[StringData[a]-' '][b],0);
			//BitImplant(Axle_A%8,&OLED096_Frame_Data[Axle_A/8+2][Axle_B+b+8*a],&OLED096_Frame_Data[(Axle_A/8)+1][Axle_B+b+8*a],(uint8_t*)&OLED096_Character_ASCII_1608[StringData[a]-' '][b+8],0);
		}
	}
}


#endif//defined(OLED096_IIC_H)||defined(OLED096_SPI_H)
#endif//OLED096_GUI_H
