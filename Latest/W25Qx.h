#if 1
#ifndef W25Qx_H
#define W25Qx_H
#include"SimpleMain.h"

#ifdef SPIs_H





//将驱动重定义到SPIs
#define W25Qx_SPI_Start SPI2_Start
#define W25Qx_SPI_End SPI2_End
#define W25Qx_SPI_ExchangeByte SPI2_ExchangeByte
#define W25Qx_SPI_NoneByte SPI2_NoneByte

//W25Qx读ID
uint32_t W25Qx_ReadID();

//W25Qx写使能（每次写之前都需要）
void W25Qx_WriteEnable(void);
//W25Qx等待忙
void W25Qx_WaitBusy(void);

//W25Qx写入
//地址格式：0x000000
//地址寄存器有24位
void W25Qx_Write(uint32_t Address, uint8_t *Data, uint16_t DataLength);

//W25Qx擦除
//地址格式：0x000000
//地址寄存器有24位
void W25Qx_Clean(uint32_t Address);

//W25Qx读取
//地址格式：0x000000
//地址寄存器有24位
void W25Qx_ReadData(uint32_t Address, uint8_t *Data, uint32_t DataLength);



#define W25Qx_ReadID_BIN 0x9f
#define W25Qx_WriteEnable_BIN 0x06
#define W25Qx_State_BIN 0x05
#define W25Qx_Write_BIN 0x02
#define W25Qx_Clean_BIN 0x20
#define W25Qx_Read_BIN 0x03



#endif//SPIs_H
#endif//W25Qx_H
#endif//0

