#include"W25Qx.h"
#ifdef W25Qx_H



#ifdef SPIs_H

//W25Qx读ID
uint32_t W25Qx_ReadID()
{
	uint32_t ID=0;
	W25Qx_SPI_Start();
	W25Qx_SPI_ExchangeByte(W25Qx_ReadID_BIN);
	ID=W25Qx_SPI_ExchangeByte(W25Qx_SPI_NoneByte);
	ID<<=8;
	ID|=W25Qx_SPI_ExchangeByte(W25Qx_SPI_NoneByte);
	ID<<=8;
	ID|=W25Qx_SPI_ExchangeByte(W25Qx_SPI_NoneByte);
	W25Qx_SPI_End();
	Error_Printf("W2_ID=%d\n",ID);
	return ID;
}

//W25Qx写使能（每次写之前都需要）
void W25Qx_WriteEnable(void)
{
	W25Qx_SPI_Start();
	W25Qx_SPI_ExchangeByte(W25Qx_WriteEnable_BIN);
	W25Qx_SPI_End();
}

//W25Qx等待忙
void W25Qx_WaitBusy(void)
{
	W25Qx_SPI_Start();
	W25Qx_SPI_ExchangeByte(W25Qx_State_BIN);
	while ((W25Qx_SPI_ExchangeByte(W25Qx_SPI_NoneByte)&0x01)==1)
	{
		//等待忙状态解除
		Error_Printf("W25_Wt\n");
	}
	W25Qx_SPI_End();
}

//W25Qx写入
//地址格式：0x000000
//地址寄存器有24位
void W25Qx_Write(uint32_t Address, uint8_t *Data, uint16_t DataLength)
{
	W25Qx_WaitBusy();
	W25Qx_WriteEnable();

	W25Qx_SPI_Start();
	W25Qx_SPI_ExchangeByte(W25Qx_Write_BIN);
	W25Qx_SPI_ExchangeByte((uint8_t)Address>>16);
	W25Qx_SPI_ExchangeByte((uint8_t)Address>>8);
	W25Qx_SPI_ExchangeByte((uint8_t)Address);
	for (uint16_t a=0;a<DataLength;++a)
	{
		W25Qx_SPI_ExchangeByte(Data[a]);
	}
	W25Qx_SPI_End();

}

//W25Qx擦除
//地址格式：0x000000
//地址寄存器有24位
void W25Qx_Clean(uint32_t Address)
{
	W25Qx_WaitBusy();
	W25Qx_WriteEnable();

	W25Qx_SPI_Start();
	W25Qx_SPI_ExchangeByte(W25Qx_Clean_BIN);
	W25Qx_SPI_ExchangeByte((uint8_t)Address>>16);
	W25Qx_SPI_ExchangeByte((uint8_t)Address>>8);
	W25Qx_SPI_ExchangeByte((uint8_t)Address);
	W25Qx_SPI_End();
}

//W25Qx读取
//地址格式：0x000000
//地址寄存器有24位
void W25Qx_ReadData(uint32_t Address, uint8_t *Data, uint32_t DataLength)
{
	W25Qx_SPI_Start();
	W25Qx_SPI_ExchangeByte(W25Qx_Read_BIN);
	W25Qx_SPI_ExchangeByte((uint8_t)Address>>16);
	W25Qx_SPI_ExchangeByte((uint8_t)Address>>8);
	W25Qx_SPI_ExchangeByte((uint8_t)Address);
	for (uint32_t a=0;a<DataLength;++a)
	{
		Data[a]=W25Qx_SPI_ExchangeByte(W25Qx_SPI_NoneByte);
	}
	W25Qx_SPI_End();
}

#endif//SPIs_H



#endif//W25Qx_H
