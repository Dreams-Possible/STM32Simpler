#include"W25Qxx.h"
#ifdef W25Qxx_H



#ifdef SPI_H



//W25Qxx读ID
void W25Qxx_ReadID(uint32_t *ID)
{
	SPI_Start();
	SPI_ExchangeByte(W25Qxx_ReadID_BIN);
	*ID=SPI_ExchangeByte(SPI_NoneByte);
	*ID<<=8;
	*ID|=SPI_ExchangeByte(SPI_NoneByte);
	*ID<<=8;
	*ID|=SPI_ExchangeByte(SPI_NoneByte);
	SPI_End();
}

//W25Qxx写使能（每次写之前都需要）
void W25Qxx_WriteEnable(void)
{
	SPI_Start();
	SPI_ExchangeByte(W25Qxx_WriteEnable_BIN);
	SPI_End();
}

//W25Qxx等待忙
void W25Qxx_WaitBusy(void)
{
	SPI_Start();
	SPI_ExchangeByte(W25Qxx_State_BIN);
	while ((SPI_ExchangeByte(SPI_NoneByte)&0x01)==1)
	{
		//等待忙状态解除
	}
	SPI_End();
}

//W25Qxx写入
//地址格式：0x000000
//地址寄存器有24位
void W25Qxx_Write(uint32_t Address, uint8_t *Data, uint16_t DataLength)
{
	W25Qxx_WaitBusy();
	W25Qxx_WriteEnable();

	SPI_Start();
	SPI_ExchangeByte(W25Qxx_Write_BIN);
	SPI_ExchangeByte((uint8_t)Address>>16);
	SPI_ExchangeByte((uint8_t)Address>>8);
	SPI_ExchangeByte((uint8_t)Address);
	for (uint16_t a=0;a<DataLength;++a)
	{
		SPI_ExchangeByte(Data[a]);
	}
	SPI_End();

}

//W25Qxx擦除
//地址格式：0x000000
//地址寄存器有24位
void W25Qxx_Clean(uint32_t Address)
{
	W25Qxx_WaitBusy();
	W25Qxx_WriteEnable();

	SPI_Start();
	SPI_ExchangeByte(W25Qxx_Clean_BIN);
	SPI_ExchangeByte((uint8_t)Address>>16);
	SPI_ExchangeByte((uint8_t)Address>>8);
	SPI_ExchangeByte((uint8_t)Address);
	SPI_End();
}

//W25Qxx读取
//地址格式：0x000000
//地址寄存器有24位
void W25Qxx_ReadData(uint32_t Address, uint8_t *Data, uint32_t DataLength)
{
	SPI_Start();
	SPI_ExchangeByte(W25Qxx_Read_BIN);
	SPI_ExchangeByte((uint8_t)Address>>16);
	SPI_ExchangeByte((uint8_t)Address>>8);
	SPI_ExchangeByte((uint8_t)Address);
	for (uint32_t a=0;a<DataLength;++a)
	{
		Data[a]=SPI_ExchangeByte(SPI_NoneByte);
	}
	SPI_End();
}

#endif//SPI_H



#endif//W25Qxx_H
