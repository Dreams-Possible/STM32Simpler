#include"SPIs.h"
#ifdef SPIs_H



//开始定义SPIs公共部分（片选信号）
////////////////////////////////////////////////////////////////
//

//设备1SPI开始
void SPI1_Start()
{
	SPI1_CS(SPI1_CSMD);//选中设备
}


//设备1SPI结束
void SPI1_End()
{
	SPI1_CS(1-SPI1_CSMD);//取消选中设备
}


//设备2SPI开始
void SPI2_Start()
{
	SPI2_CS(SPI2_CSMD);//选中设备
}


//设备2SPI结束
void SPI2_End()
{
	SPI2_CS(1-SPI2_CSMD);//取消选中设备
}



//
////////////////////////////////////////////////////////////////
//结束定义SPIs公共部分（片选信号）



//开始定义SPIs软件部分
////////////////////////////////////////////////////////////////
//

#ifdef SPIs_Software

////SPI初始化
//uint8_t SPI_Initialization()
//{
//	SPI_End();//SPI结束
//	SPI_SCK(SPI1_CPOL);//时钟状态：不活跃
//}



//SPI发送字节（单独使用无效）
void SPI_OutByte(uint8_t Byte)
{
    uint8_t a=0;
    for(a=0;a<8;++a)
    {
    	SPI_MOSI(Byte&(0x80>>a));//将16进制数一位一位取出来
    	SPI_SCK(1-SPI1_CPOL);//时钟状态：活跃
    	SPI_SCK(SPI1_CPOL);//时钟状态：不活跃
    }
}

//SPI接收字节（单独使用无效）
uint8_t SPI_ExchangeByte(uint8_t Byte)
{
    for(uint8_t a=0;a<8;++a)
    {
    	SPI_MOSI(Byte&0x80);//SPI特性接受需同时发送（发送什么无所谓）
    	Byte<<=1;
    	SPI_SCK(1-SPI1_CPOL);//时钟状态：活跃
		if(SPI_MISO)
		{
			Byte|=0x01;//将16进制数一位一位读入
		}
		SPI_SCK(SPI1_CPOL);//时钟状态：不活跃
    }
    return Byte;
}

//发送字节
void SPI_SendByte(uint8_t Byte)
{
	SPI_Start();//SPI开始
	SPI_OutByte(Byte);
	SPI_End();//SPI结束
}

//发送数据
//数据长度，数据地址
void SPI_SendData(uint8_t DataLength,uint8_t *Data)
{
	SPI_Start();//SPI开始

	for(uint8_t a=0;a<DataLength;++a)
	{
		SPI_OutByte(Data[a]);
	}

	SPI_End();//SPI结束
}

//接收字节
uint8_t SPI_ReceiveByte()
{
	SPI_Start();//SPI开始
	uint8_t Byte=SPI_ExchangeByte(SPI_NoneByte);
    SPI_End();//SPI结束
    return Byte;
}

//接收数据
//数据长度，数据地址
void SPI_ReceiveData(uint8_t DataLength,uint8_t *Data)
{
	SPI_Start();//SPI开始
	for(uint8_t a=0;a<DataLength;++a)
	{

		*Data=SPI_ExchangeByte(SPI_NoneByte);
		++Data;
	}
    SPI_End();//SPI结束
}

//交换字节
uint8_t SPI_SwapByte(uint8_t Byte)
{
	SPI_Start();//SPI开始
	Byte=SPI_ExchangeByte(Byte);
    SPI_End();//SPI结束
    return Byte;
}


//交换数据
void SPI_SwapData(uint8_t *SendData,uint8_t *ReceiveData,uint8_t DataLength)
{
	SPI_Start();//SPI开始
	for(uint8_t a=0;a<DataLength;++a)
	{

		*ReceiveData=SPI_ExchangeByte(*SendData);
		++SendData;
		++ReceiveData;
	}
    SPI_End();//SPI结束
}

#endif//SPIs_Software


//
////////////////////////////////////////////////////////////////
//结束定义SPIs软件部分





//开始定义SPIs硬件部分
////////////////////////////////////////////////////////////////
//

#ifdef SPIs_Hardware

//发送字节
void SPI_SendByte(uint8_t Byte)
{
	uint8_t Byte_Byte[1]={Byte};
	HAL_SPI_Transmit(&SPI_2,Byte_Byte,1,HAL_MAX_DELAY);

}

////SPI接收字节（单独使用无效）
//uint8_t SPI_ExchangeByte(uint8_t Byte)
//{
//	//while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) != SET);	//等待发送数据寄存器空
//
//	uint8_t Byte_Byte[1]={Byte};
//
//	HAL_SPI_Transmit(&SPI_2,Byte_Byte,1,HAL_MAX_DELAY);
//
//	//while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) != SET);	//等待接收数据寄存器非空
//
//	return HAL_SPI_Receive(&SPI_2,Byte_Byte,1,HAL_MAX_DELAY);
//}




//SPI接收字节（单独使用无效）
uint8_t SPI_ExchangeByte(uint8_t SendByte)
{
	uint8_t ReceiveByte=0;

	HAL_SPI_TransmitReceive(&SPI_2,&SendByte,&ReceiveByte,1,HAL_MAX_DELAY);

	return ReceiveByte;

}



#endif//SPIs_Hardware


//
////////////////////////////////////////////////////////////////
//结束定义SPIs硬件部分



#endif//SPIs_H
