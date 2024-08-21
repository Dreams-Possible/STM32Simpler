#if 1
#ifndef OLED096s_GUI_H
#define OLED096s_GUI_H
#include"SimpleMain.h"



//字典（字体大小1608）
//取模方式：阴码，列行式，逆向（低位在前）
#define OLED0961_GUI_CharacterHeight 16
#define OLED0961_GUI_CharacterWidth 8

//定义OLED096长和宽的有效像素
#define OLED0961_GUI_Width 64
#define OLED0961_GUI_Length 128

//缓冲帧数据区
//已包含数据标志位0x40
extern uint8_t OLED0961_GUI_Frame_Data[OLED0961_GUI_Width/8][OLED0961_GUI_Length+1];


//缓冲帧初始化
void OLED0961_GUI_FrameReset();

////帧数记录
//void OLED0961_GUI_FPSRecord();

//绘制点（给出标准平面直角坐标系下的XY坐标）
void OLED0961_GUI_Point(uint8_t Axle_X,uint8_t Axle_Y);
//绘制线（给出起点坐标和终点坐标）
void OLED0961_GUI_Line(uint8_t From_X,uint8_t From_Y,uint8_t To_X,uint8_t To_Y);
//绘制三角形（给出三个点的XY坐标）
void OLED0961_GUI_Triangle(uint8_t Point1_X,uint8_t Point1_Y,uint8_t Point2_X,uint8_t Point2_Y,uint8_t Point3_X,uint8_t Point3_Y);
//绘制四边形（以以此给出四个点的XY坐标）
void OLED0961_GUI_Quadrilateral(uint8_t Point1_X,uint8_t Point1_Y,uint8_t Point2_X,uint8_t Point2_Y,uint8_t Point3_X,uint8_t Point3_Y,uint8_t Point4_X,uint8_t Point4_Y);
//绘制圆型（给出圆心XY坐标，半径，起始角度和结束角度）
void OLED0961_GUI_Round(uint8_t Axle_X,uint8_t Axle_Y,uint8_t Radius,uint16_t From_Angle,uint16_t To_Angle);
//显示字符（起点左上角XY坐标，字符串）
void OLED0961_GUI_Characters(uint8_t Axle_X,uint8_t Axle_Y,const char *CharacterString,...);


#endif//OLED096_GUI_H
#endif//0


