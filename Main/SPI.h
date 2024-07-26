#if 0
#ifndef SPI_H
#define SPI_H
#include"SimpleMain.h"


////////////////////////////////////////////////////////////////
//选择使用软件SPI还是硬件SPI
//#define SPI_Software
#define SPI_Hardware
////////////////////////////////////////////////////////////////


//公共区域
////////////////////////////////////////////////////////////////
#if defined(SPI_Software)||defined(SPI_Hardware)
//重定义NSS
//设备1
#define SPI_NSS_1(x) HAL_GPIO_WritePin(SPI_NSS_1_GPIO_Port,SPI_NSS_1_Pin,(GPIO_PinState)(x))
//空字节（用来辅助接收字节）
#define SPI_NoneByte 0

//SPI开始
void SPI_Start();
//SPI结束
void SPI_End();
//发送数据
//数据长度，数据地址
void SPI_SendData(uint8_t DataLength,uint8_t *Data);
//SPI接收字节（单独使用无效）
uint8_t SPI_ExchangeByte(uint8_t Byte);
#endif//defined(SPI_Software)||defined(SPI_Hardware)
////////////////////////////////////////////////////////////////




////////////////////////////////////////////////////////////////
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
//选中状态（0时选中，1时选中）
#define CSMD 0
#endif//SPI_Software
////////////////////////////////////////////////////////////////





////////////////////////////////////////////////////////////////
#ifdef SPI_Hardware
//解释所使用的SPI端口
extern SPI_HandleTypeDef hspi2;
//重定义串口使用的SPI端口号
#define SPI_1 hspi2
#endif//SPI_Hardware
////////////////////////////////////////////////////////////////


#endif//SPI_Software_H
#endif//0

