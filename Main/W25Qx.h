#if 1
#ifndef W25Qx_H
#define W25Qx_H
#include"SimpleMain.h"

#ifdef SPIs_H


//重定义设备
#define W25Qxx_SPI_Start SPI_Start_2
#define W25Qxx_SPI_End SPI_End_2

//W25Qxx读ID
void W25Qxx_ReadID(uint32_t *ID);

//W25Qxx写使能（每次写之前都需要）
void W25Qxx_WriteEnable(void);
//W25Qxx等待忙
void W25Qxx_WaitBusy(void);

//W25Qxx写入
//地址格式：0x000000
//地址寄存器有24位
void W25Qxx_Write(uint32_t Address, uint8_t *Data, uint16_t DataLength);

//W25Qxx擦除
//地址格式：0x000000
//地址寄存器有24位
void W25Qxx_Clean(uint32_t Address);

//W25Qxx读取
//地址格式：0x000000
//地址寄存器有24位
void W25Qxx_ReadData(uint32_t Address, uint8_t *Data, uint32_t DataLength);



#define W25Qxx_ReadID_BIN 0x9f
#define W25Qxx_WriteEnable_BIN 0x06
#define W25Qxx_State_BIN 0x05
#define W25Qxx_Write_BIN 0x02
#define W25Qxx_Clean_BIN 0x20
#define W25Qxx_Read_BIN 0x03



#endif//SPI_H
#endif//W25Qxx_H
#endif//0

