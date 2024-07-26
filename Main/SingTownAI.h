#if 1
#ifndef SingTownAI_H
#define SingTownAI_H
#include"SimpleMain.h"



//设置默认即可

//解释所使用的串口
extern UART_HandleTypeDef huart4;

//重定义串口使用的串口号
#define USART_SingTownAI huart4


//以下内容修改自星瞳官方文档
////////////////////////////////////////////////////////////////
#define OBJECT_MAX 8    // Max Found 8 Objects
#define OBJECT_SIZE 10  // Every Object is 10 bytes

struct DetectObj {
	int score;  // max 255
	int idx;
	int x1;  // box left coordinate, max 640
	int y1;  // box top coordinate, max 480
	int x2;  // box right coordinate, max 640
	int y2;  // box bottom coordinate, max 480
};

extern struct DetectObj objs[OBJECT_MAX];

int read_singtownaicam_objs();

////////////////////////////////////////////////////////////////

#endif//SingTownAI_H
#endif//0
