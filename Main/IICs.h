#if 1
#ifndef IICs_H
#define IICs_H
#include"SimpleMain.h"




//配置如下
////////////////////////////////////////////////////////////////
//

//如果使用软件IIC
//将任意两引脚名称设置为IICx_SCL和IICx_SDA
//引脚具体配置为，开漏输出，初始高，默认上拉

//如果使用硬件IIC
//使用默认配置设置硬件IIC即可

//这里提供了几乎所有可能用到的IIC函数，只需要将对应硬件驱动函数重定义至此即可

//
////////////////////////////////////////////////////////////////
//结束配置




//选择使用软件IIC1还是硬件IIC1
////////////////////////////////////////////////////////////////
//
//#define IIC1_Software
#define IIC1_Hardware
//
////////////////////////////////////////////////////////////////
//结束选择使用软件IIC1还是硬件IIC1





//开始定义软硬件IIC1公共函数
////////////////////////////////////////////////////////////////
//
//提供两个版本，前两个为直接传值，后四个为传指针
#if defined(IIC1_Software)||defined(IIC1_Hardware)
//发送字节
//设备地址，字节
int8_t IIC1_SendByte(uint8_t DeviceAddress,uint8_t Byte);

//向寄存器写字节
//设备地址，寄存器地址，字节
int8_t IIC1_WriteByte(uint8_t DeviceAddress,uint8_t RegisterAddress,uint8_t Byte);


//发送数据
//设备地址，数据长度，数据地址
int8_t IIC1_SendData(uint8_t DeviceAddress,uint8_t DataLength,uint8_t *Data);

//接收数据
//设备地址，数据长度，数据地址
int8_t IIC1_ReceiveData(uint8_t DeviceAddress,uint8_t DataLength,uint8_t *Data);

//向寄存器写数据
//设备地址，寄存器地址，数据长度，数据地址
int8_t IIC1_WriteData(uint8_t DeviceAddress,uint8_t RegisterAddress,uint8_t DataLength,uint8_t *Data);

//从寄存器读数据
//设备地址，寄存器地址，数据长度，数据地址
int8_t IIC1_ReadData(uint8_t DeviceAddress,uint8_t RegisterAddress,uint8_t DataLength,uint8_t *Data);
#endif//defined(IIC1_Software)||defined(IIC1_Hardware)

//
////////////////////////////////////////////////////////////////
//结束定义软硬件IIC1公共函数



//开始定义软件IIC1部分
////////////////////////////////////////////////////////////////
//


#ifdef IIC1_Software
//IIC通信引脚名称默认为IIC1_SCL和IIC1_SDA
//IIC1_SCL引脚，开漏输出，初始高，默认上拉
//IIC1_SDA引脚，开漏输出，初始高，默认上拉
#define IIC1_SCL(x) HAL_GPIO_WritePin(IIC1_SCL_GPIO_Port,IIC1_SCL_Pin,(GPIO_PinState)(x))
#define IIC1_SDA(x) HAL_GPIO_WritePin(IIC1_SDA_GPIO_Port,IIC1_SDA_Pin,(GPIO_PinState)(x))
#define IIC1_SDA_In HAL_GPIO_ReadPin(IIC1_SDA_GPIO_Port,IIC1_SDA_Pin)//重定义SDA读取

//IIC通讯开始
void IIC1_Start();
//IIC通讯结束
void IIC1_End();
//IIC读取应答
int8_t IIC1_InACK();
//IIC发送应答
void IIC1_OutACK(uint8_t ACK);
#endif//IIC1_Software
//
////////////////////////////////////////////////////////////////
//结束定义软件IIC1部分


//开始定义硬件IIC1部分
////////////////////////////////////////////////////////////////
//
#ifdef IIC1_Hardware
//解释所使用的IIC端口
extern I2C_HandleTypeDef hi2c1;
//重定义使用的IIC端口号
#define I2C1_Hardware hi2c1
#endif//IIC1_Hardware

//
////////////////////////////////////////////////////////////////
//结束定义硬件IIC1部分






#endif//IIC1_Hardware
#endif//0
