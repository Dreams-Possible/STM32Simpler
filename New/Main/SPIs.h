#if 1
#ifndef SPIs_H
#define SPIs_H
#include"SimpleMain.h"


//配置如下
////////////////////////////////////////////////////////////////
//

//如果使用软件SPIs
//将任意几引脚名称设置为SPIx_CS，SPIx_MOSI，SPIx_MISO
//引脚具体配置为，默认配置即可



//如果使用硬件SPIs
//使用默认配置设置硬件SPIs即可

//SPIs对应硬件的具体函数应该在其对应部分实现，这里只提供了基本的函数

//
////////////////////////////////////////////////////////////////
//结束配置



//开始选择使用软件SPI1还是硬件SPI1
////////////////////////////////////////////////////////////////
//

//#define SPI1_Software
#define SPI1_Hardware

//
////////////////////////////////////////////////////////////////
//结束选择使用软件SPI1还是硬件SPI1




//开始定义软硬件SPI1公共函数
////////////////////////////////////////////////////////////////
//

#if defined(SPI1_Software)||defined(SPI1_Hardware)

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
#define SPI1_NoneByte 0


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
void SPI1_SendData(uint8_t DataLength,uint8_t *Data);
//SPI接收字节（单独使用无效）
uint8_t SPI1_ExchangeByte(uint8_t Byte);


#endif//defined(SPI1_Software)||defined(SPI1_Hardware)

//
////////////////////////////////////////////////////////////////
//结束定义软硬件SPI1公共函数


//开始定义软件SPI1部分
////////////////////////////////////////////////////////////////
//

#ifdef SPI1_Software
//SPI1通信引脚名称默认为
//SPI1_NSS_x引脚
//SPI1_MOSI引脚，默认配置
//SPI1_MISO引脚，默认配置

//重定义MOSI
#define SPI1_MOSI(x) HAL_GPIO_WritePin(SPI1_MOSI_GPIO_Port,SPI1_MOSI_Pin,(GPIO_PinState)(x))
//重定义MISO
#define SPI1_MISO HAL_GPIO_ReadPin(SPI1_MISO_GPIO_Port,SPI1_MISO_Pin)
//重定义SCK
#define SPI1_SCK(x) HAL_GPIO_WritePin(SPI1_SCK_GPIO_Port,SPI1_SCK_Pin,(GPIO_PinState)(x))

//设备1的时钟极性（0时不活跃，1时不活跃）
#define SPI1_CPOL 0
//设备1的时钟相位（在时钟信号SCK的奇数个，1第二个跳变沿采样）
#define SPI1_CPHA 0


#endif//SPIs_Software

//
////////////////////////////////////////////////////////////////
//结束定义软件SPI1部分



//开始定义硬件SPI1部分
////////////////////////////////////////////////////////////////
//
#ifdef SPI1_Hardware
//解释所使用的SPI端口
extern SPI_HandleTypeDef hspi1;
//重定义串口使用的SPI端口号
#define SPI1_Port hspi1
#endif//SPI1_Hardware
//
////////////////////////////////////////////////////////////////
//结束定义硬件SPI1部分












//开始选择使用软件SPI2还是硬件SPI2
////////////////////////////////////////////////////////////////
//

//#define SPI2_Software
#define SPI2_Hardware

//
////////////////////////////////////////////////////////////////
//结束选择使用软件SPI2还是硬件SPI2




//开始定义软硬件SPI2公共函数
////////////////////////////////////////////////////////////////
//

#if defined(SPI2_Software)||defined(SPI2_Hardware)

//根据未选中状态设置片选引脚初始电平和上下拉状态

//设备1选中状态（0时选中，1时选中）
#define SPI2_CSMD 0
//设备2选中状态（0时选中，1时选中）
#define SPI2_CSMD 0

//重定义NSS
//设备1
#define SPI2_CS(x) HAL_GPIO_WritePin(SPI2_CS_GPIO_Port,SPI2_CS_Pin,(GPIO_PinState)(x))
//设备2
#define SPI2_CS(x) HAL_GPIO_WritePin(SPI2_CS_GPIO_Port,SPI2_CS_Pin,(GPIO_PinState)(x))
//空字节（用来辅助接收字节）
#define SPI2_NoneByte 0


//设备1SPI开始
void SPI2_Start();

//设备2SPI开始
void SPI2_Start();

//设备1SPI结束
void SPI2_End();

//设备2SPI结束
void SPI2_End();


//发送数据
//数据长度，数据地址
void SPI2_SendData(uint8_t DataLength,uint8_t *Data);
//SPI接收字节（单独使用无效）
uint8_t SPI2_ExchangeByte(uint8_t Byte);


#endif//defined(SPI2_Software)||defined(SPI2_Hardware)

//
////////////////////////////////////////////////////////////////
//结束定义软硬件SPI2公共函数


//开始定义软件SPI2部分
////////////////////////////////////////////////////////////////
//

#ifdef SPI2_Software
//SPI2通信引脚名称默认为
//SPI2_NSS_x引脚
//SPI2_MOSI引脚，默认配置
//SPI2_MISO引脚，默认配置

//重定义MOSI
#define SPI2_MOSI(x) HAL_GPIO_WritePin(SPI2_MOSI_GPIO_Port,SPI2_MOSI_Pin,(GPIO_PinState)(x))
//重定义MISO
#define SPI2_MISO HAL_GPIO_ReadPin(SPI2_MISO_GPIO_Port,SPI2_MISO_Pin)
//重定义SCK
#define SPI2_SCK(x) HAL_GPIO_WritePin(SPI2_SCK_GPIO_Port,SPI2_SCK_Pin,(GPIO_PinState)(x))

//设备1的时钟极性（0时不活跃，1时不活跃）
#define SPI2_CPOL 0
//设备1的时钟相位（在时钟信号SCK的奇数个，1第二个跳变沿采样）
#define SPI2_CPHA 0


#endif//SPIs_Software

//
////////////////////////////////////////////////////////////////
//结束定义软件SPIs部分



//开始定义硬件SPI2部分
////////////////////////////////////////////////////////////////
//
#ifdef SPI2_Hardware
//解释所使用的SPI端口
extern SPI_HandleTypeDef hspi2;
//重定义串口使用的SPI端口号
#define SPI2_Port hspi2
#endif//SPI2_Hardware
//
////////////////////////////////////////////////////////////////
//结束定义硬件SPI2部分




#endif//SPIs_Software_H
#endif//0

