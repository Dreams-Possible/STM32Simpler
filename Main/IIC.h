#if 1
#ifndef IIC_H
#define IIC_H
#include"SimpleMain.h"



//选择使用软件IIC还是硬件IIC
#define IIC_Software
//#define IIC_Hardware


//提供两个版本，前两个为直接传值，后四个为传指针
#if defined(IIC_Software)||defined(IIC_Hardware)
//发送字节
//设备地址，字节
int8_t IIC_SendByte(uint8_t DeviceAddress,uint8_t Byte);

//向寄存器写字节
//设备地址，寄存器地址，字节
int8_t IIC_WriteByte(uint8_t DeviceAddress,uint8_t RegisterAddress,uint8_t Byte);



//发送数据
//设备地址，数据长度，数据地址
int8_t IIC_SendData(uint8_t DeviceAddress,uint8_t DataLength,uint8_t *Data);

//接收数据
//设备地址，数据长度，数据地址
int8_t IIC_ReceiveData(uint8_t DeviceAddress,uint8_t DataLength,uint8_t *Data);

//向寄存器写数据
//设备地址，寄存器地址，数据长度，数据地址
int8_t IIC_WriteData(uint8_t DeviceAddress,uint8_t RegisterAddress,uint8_t DataLength,uint8_t *Data);

//从寄存器读数据
//设备地址，寄存器地址，数据长度，数据地址
int8_t IIC_ReadData(uint8_t DeviceAddress,uint8_t RegisterAddress,uint8_t DataLength,uint8_t *Data);
#endif//defined(IIC_Software)||defined(IIC_Hardware)



#ifdef IIC_Software
//IIC通信引脚名称默认为IIC_SCL和IIC_SDA
//IIC_SCL引脚，开漏输出，初始高，默认上拉
//IIC_SDA引脚，开漏输出，初始高，默认上拉
#define IIC_SCL(x) HAL_GPIO_WritePin(IIC_SCL_GPIO_Port,IIC_SCL_Pin,(GPIO_PinState)(x))
#define IIC_SDA(x) HAL_GPIO_WritePin(IIC_SDA_GPIO_Port,IIC_SDA_Pin,(GPIO_PinState)(x))
#define IIC_SDA_In HAL_GPIO_ReadPin(IIC_SDA_GPIO_Port,IIC_SDA_Pin)//重定义SDA读取

//IIC通讯开始
void IIC_Start();
//IIC通讯结束
void IIC_End();
//IIC读取应答
int8_t IIC_InACK();
//IIC发送应答
void IIC_OutACK(uint8_t ACK);
#endif//IIC_Software


#ifdef IIC_Hardware
//解释所使用的IIC端口
extern I2C_HandleTypeDef hi2c1;
extern I2C_HandleTypeDef hi2c2;
//重定义使用的IIC端口号
#define IIC_Hardware1 hi2c1
#define IIC_Hardware2 hi2c2
#endif//IIC_Hardware



#endif//IIC_Software_H
#endif//0
