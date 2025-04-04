#if 1
#ifndef SPI_H
#define SPI_H
#include"SimpleMain.h"

//开始选择使用软件SPI还是硬件SPI
////////////////////////////////////////////////////////////////
//

//#define SPI_Software
#define SPI_Hardware

//
////////////////////////////////////////////////////////////////
//结束选择使用软件SPI还是硬件SPI



//配置如下
////////////////////////////////////////////////////////////////
//

//如果使用软件SPI
//将任意几引脚名称设置为SPI_NSS_x，SPI_MOSI，SPI_MISO
//引脚具体配置为，默认配置即可

//如果使用硬件SPI
//使用默认配置设置硬件SPI即可

//SPI对应硬件的具体函数应该在其对应部分实现，这里只提供了基本的函数

//
////////////////////////////////////////////////////////////////
//结束配置


//开始定义软硬件SPI公共函数
////////////////////////////////////////////////////////////////
//

#if defined(SPI_Software)||defined(SPI_Hardware)

//根据未选中状态设置片选引脚初始电平和上下拉状态

//设备1选中状态（0时选中，1时选中）
#define CSMD_1 0
//设备2选中状态（0时选中，1时选中）
#define CSMD_2 0

//重定义NSS
//设备1
#define SPI_CS_1(x) HAL_GPIO_WritePin(SPI_CS_1_GPIO_Port,SPI_CS_1_Pin,(GPIO_PinState)(x))
//设备2
#define SPI_CS_2(x) HAL_GPIO_WritePin(SPI_CS_2_GPIO_Port,SPI_CS_2_Pin,(GPIO_PinState)(x))
//空字节（用来辅助接收字节）
#define SPI_NoneByte 0


//设备1SPI开始
void SPI_Start_1();

//设备2SPI开始
void SPI_Start_2();

//设备1SPI结束
void SPI_End_1();

//设备2SPI结束
void SPI_End_2();


//发送数据
//数据长度，数据地址
void SPI_SendData(uint8_t DataLength,uint8_t *Data);
//SPI接收字节（单独使用无效）
uint8_t SPI_ExchangeByte(uint8_t Byte);
#endif//defined(SPI_Software)||defined(SPI_Hardware)

//
////////////////////////////////////////////////////////////////
//结束定义软硬件SPI公共函数


//开始定义软件SPI部分
////////////////////////////////////////////////////////////////
//

#ifdef SPI_Software
//SPI通信引脚名称默认为
//SPI_NSS_x引脚
//SPI_MOSI引脚，默认配置
//SPI_MISO引脚，默认配置

//重定义MOSI
#define SPI_MOSI(x) HAL_GPIO_WritePin(SPI_MOSI_GPIO_Port,SPI_MOSI_Pin,(GPIO_PinState)(x))
//重定义MISO
#define SPI_MISO HAL_GPIO_ReadPin(SPI_MISO_GPIO_Port,SPI_MISO_Pin)
//重定义SCK
#define SPI_SCK(x) HAL_GPIO_WritePin(SPI_SCK_GPIO_Port,SPI_SCK_Pin,(GPIO_PinState)(x))

//时钟极性（0时不活跃，1时不活跃）
#define CPOL 0
//时钟相位（在时钟信号SCK的奇数个，1第二个跳变沿采样）
#define CPHA 0

#endif//SPI_Software

//
////////////////////////////////////////////////////////////////
//结束定义软件SPI部分



//开始定义硬件SPI部分
////////////////////////////////////////////////////////////////
//
#ifdef SPI_Hardware
//解释所使用的SPI端口
extern SPI_HandleTypeDef hspi1;
extern SPI_HandleTypeDef hspi2;
//重定义串口使用的SPI端口号
#define SPI_1 hspi1
#define SPI_2 hspi2
#endif//SPI_Hardware
//
////////////////////////////////////////////////////////////////
//结束定义硬件SPI部分


#endif//SPI_Software_H
#endif//0

