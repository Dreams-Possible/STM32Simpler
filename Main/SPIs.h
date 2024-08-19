#if 1
#ifndef SPIs_H
#define SPIs_H
#include"SimpleMain.h"


//配置如下
////////////////////////////////////////////////////////////////
//

//如果使用软件SPIs
//将任意几引脚名称设置为SPIx_CS，SPI_MOSI，SPI_MISO
//引脚具体配置为，默认配置即可



//如果使用硬件SPIs
//使用默认配置设置硬件SPIs即可

//SPIs对应硬件的具体函数应该在其对应部分实现，这里只提供了基本的函数

//
////////////////////////////////////////////////////////////////
//结束配置



//开始选择使用软件SPIs还是硬件SPIs
////////////////////////////////////////////////////////////////
//

//#define SPIs_Software
#define SPIs_Hardware

//
////////////////////////////////////////////////////////////////
//结束选择使用软件SPIs还是硬件SPIs




//开始定义软硬件SPIs公共函数
////////////////////////////////////////////////////////////////
//

#if defined(SPIs_Software)||defined(SPIs_Hardware)

//根据未选中状态设置片选引脚初始电平和上下拉状态

//设备1选中状态（0时选中，1时选中）
#define SPI1_CSMD 0
//设备2选中状态（0时选中，1时选中）
#define SPI2_CSMD 0

//重定义NSS
//设备1
#define SPI1_CS(x) HAL_GPIO_WritePin(SPI1_CS_GPIO_Port,SPI1_CS_Pin,(GPIO_PinState)(x))
//设备2
#define SPI2_CS(x) HAL_GPIO_WritePin(SPI2_CS_GPIO_Port,SPI2_CS_Pin,(GPIO_PinState)(x))
//空字节（用来辅助接收字节）
#define SPI_NoneByte 0


//设备1SPI开始
void SPI1_Start();

//设备2SPI开始
void SPI2_Start();

//设备1SPI结束
void SPI1_End();

//设备2SPI结束
void SPI2_End();


//发送数据
//数据长度，数据地址
void SPI_SendData(uint8_t DataLength,uint8_t *Data);
//SPI接收字节（单独使用无效）
uint8_t SPI_ExchangeByte(uint8_t Byte);
#endif//defined(SPIs_Software)||defined(SPIs_Hardware)

//
////////////////////////////////////////////////////////////////
//结束定义软硬件SPIs公共函数


//开始定义软件SPIs部分
////////////////////////////////////////////////////////////////
//

#ifdef SPIs_Software
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

//设备1的时钟极性（0时不活跃，1时不活跃）
#define SPI1_CPOL 0
//设备1的时钟相位（在时钟信号SCK的奇数个，1第二个跳变沿采样）
#define SPI1_CPHA 0

//设备2的时钟极性（0时不活跃，1时不活跃）
#define SPI2_CPOL 0
//设备2的时钟相位（在时钟信号SCK的奇数个，1第二个跳变沿采样）
#define SPI2_CPHA 0

#endif//SPIs_Software

//
////////////////////////////////////////////////////////////////
//结束定义软件SPIs部分



//开始定义硬件SPIs部分
////////////////////////////////////////////////////////////////
//
#ifdef SPIs_Hardware
//解释所使用的SPI端口
extern SPI_HandleTypeDef hspi1;
extern SPI_HandleTypeDef hspi2;
//重定义串口使用的SPI端口号
#define SPI_1 hspi1
#define SPI_2 hspi2
#endif//SPI_Hardware
//
////////////////////////////////////////////////////////////////
//结束定义硬件SPIs部分


#endif//SPIs_Software_H
#endif//0

