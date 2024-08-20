#include"SPIs.h"
#ifdef SPIs_H



//开始定义SPI1公共部分（片选信号）
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


//
////////////////////////////////////////////////////////////////
//结束定义SPI1公共部分（片选信号）



//开始定义SPI1软件部分
////////////////////////////////////////////////////////////////
//

#ifdef SPI1_Software

////SPI初始化
//uint8_t SPI_Initialization()
//{
//	SPI1_End();//SPI结束
//	SPI1_SCK(SPI1_CPOL);//时钟状态：不活跃
//}



//SPI1发送字节（单独使用无效）
void SPI1_OutByte(uint8_t Byte)
{
    uint8_t a=0;
    for(a=0;a<8;++a)
    {
    	SPI1_MOSI(Byte&(0x80>>a));//将16进制数一位一位取出来
    	SPI1_SCK(1-SPI1_CPOL);//时钟状态：活跃
    	SPI1_SCK(SPI1_CPOL);//时钟状态：不活跃
    }
}

//SPI接收字节（单独使用无效）
uint8_t SPI1_ExchangeByte(uint8_t Byte)
{
    for(uint8_t a=0;a<8;++a)
    {
    	SPI1_MOSI(Byte&0x80);//SPI特性接受需同时发送（发送什么无所谓）
    	Byte<<=1;
    	SPI1_SCK(1-SPI1_CPOL);//时钟状态：活跃
		if(SPI_MISO)
		{
			Byte|=0x01;//将16进制数一位一位读入
		}
		SPI1_SCK(SPI1_CPOL);//时钟状态：不活跃
    }
    return Byte;
}

//发送字节
void SPI1_SendByte(uint8_t Byte)
{
	SPI1_Start();//SPI开始
	SPI_OutByte(Byte);
	SPI1_End();//SPI结束
}

//发送数据
//数据长度，数据地址
void SPI1_SendData(uint8_t DataLength,uint8_t *Data)
{
	SPI1_Start();//SPI开始

	for(uint8_t a=0;a<DataLength;++a)
	{
		SPI_OutByte(Data[a]);
	}

	SPI1_End();//SPI结束
}

//接收字节
uint8_t SPI1_ReceiveByte()
{
	SPI1_Start();//SPI开始
	uint8_t Byte=SPI1_ExchangeByte(SPI_NoneByte);
    SPI1_End();//SPI结束
    return Byte;
}

//接收数据
//数据长度，数据地址
void SPI1_ReceiveData(uint8_t DataLength,uint8_t *Data)
{
	SPI1_Start();//SPI开始
	for(uint8_t a=0;a<DataLength;++a)
	{

		*Data=SPI1_ExchangeByte(SPI_NoneByte);
		++Data;
	}
    SPI1_End();//SPI结束
}

//交换字节
uint8_t SPI1_SwapByte(uint8_t Byte)
{
	SPI1_Start();//SPI开始
	Byte=SPI1_ExchangeByte(Byte);
    SPI1_End();//SPI结束
    return Byte;
}


//交换数据
void SPI1_SwapData(uint8_t *SendData,uint8_t *ReceiveData,uint8_t DataLength)
{
	SPI1_Start();//SPI开始
	for(uint8_t a=0;a<DataLength;++a)
	{

		*ReceiveData=SPI1_ExchangeByte(*SendData);
		++SendData;
		++ReceiveData;
	}
    SPI1_End();//SPI结束
}

#endif//SPI1_Software


//
////////////////////////////////////////////////////////////////
//结束定义SPI1软件部分





//开始定义SPI1硬件部分
////////////////////////////////////////////////////////////////
//

#ifdef SPI1_Hardware

//发送字节
void SPI1_SendByte(uint8_t Byte)
{
	uint8_t Byte_Byte[1]={Byte};
	HAL_SPI_Transmit(&SPI1_Port,Byte_Byte,1,HAL_MAX_DELAY);

}

//发送数据
//数据长度，数据地址
void SPI1_SendData(uint8_t DataLength,uint8_t *Data)
{

	HAL_SPI_Transmit(&SPI1_Port,Data,DataLength,HAL_MAX_DELAY);

}



//SPI接收字节（单独使用无效）
uint8_t SPI1_ExchangeByte(uint8_t SendByte)
{
	uint8_t ReceiveByte=0;

	HAL_SPI_TransmitReceive(&SPI1_Port,&SendByte,&ReceiveByte,1,HAL_MAX_DELAY);

	return ReceiveByte;

}



#endif//SPI1_Hardware


//
////////////////////////////////////////////////////////////////
//结束定义SPI1硬件部分














//开始定义SPI2公共部分（片选信号）
////////////////////////////////////////////////////////////////
//

//设备1SPI开始
void SPI2_Start()
{
	SPI2_CS(SPI2_CSMD);//选中设备
}


//设备1SPI结束
void SPI2_End()
{
	SPI2_CS(1-SPI2_CSMD);//取消选中设备
}


//
////////////////////////////////////////////////////////////////
//结束定义SPI2公共部分（片选信号）



//开始定义SPI2软件部分
////////////////////////////////////////////////////////////////
//

#ifdef SPI2_Software

////SPI初始化
//uint8_t SPI_Initialization()
//{
//	SPI2_End();//SPI结束
//	SPI2_SCK(SPI2_CPOL);//时钟状态：不活跃
//}



//SPI2发送字节（单独使用无效）
void SPI2_OutByte(uint8_t Byte)
{
    uint8_t a=0;
    for(a=0;a<8;++a)
    {
    	SPI2_MOSI(Byte&(0x80>>a));//将16进制数一位一位取出来
    	SPI2_SCK(1-SPI2_CPOL);//时钟状态：活跃
    	SPI2_SCK(SPI2_CPOL);//时钟状态：不活跃
    }
}

//SPI接收字节（单独使用无效）
uint8_t SPI2_ExchangeByte(uint8_t Byte)
{
    for(uint8_t a=0;a<8;++a)
    {
    	SPI2_MOSI(Byte&0x80);//SPI特性接受需同时发送（发送什么无所谓）
    	Byte<<=1;
    	SPI2_SCK(1-SPI2_CPOL);//时钟状态：活跃
		if(SPI_MISO)
		{
			Byte|=0x01;//将16进制数一位一位读入
		}
		SPI2_SCK(SPI2_CPOL);//时钟状态：不活跃
    }
    return Byte;
}

//发送字节
void SPI2_SendByte(uint8_t Byte)
{
	SPI2_Start();//SPI开始
	SPI_OutByte(Byte);
	SPI2_End();//SPI结束
}

//发送数据
//数据长度，数据地址
void SPI2_SendData(uint8_t DataLength,uint8_t *Data)
{
	SPI2_Start();//SPI开始

	for(uint8_t a=0;a<DataLength;++a)
	{
		SPI_OutByte(Data[a]);
	}

	SPI2_End();//SPI结束
}

//接收字节
uint8_t SPI2_ReceiveByte()
{
	SPI2_Start();//SPI开始
	uint8_t Byte=SPI2_ExchangeByte(SPI_NoneByte);
    SPI2_End();//SPI结束
    return Byte;
}

//接收数据
//数据长度，数据地址
void SPI2_ReceiveData(uint8_t DataLength,uint8_t *Data)
{
	SPI2_Start();//SPI开始
	for(uint8_t a=0;a<DataLength;++a)
	{

		*Data=SPI2_ExchangeByte(SPI_NoneByte);
		++Data;
	}
    SPI2_End();//SPI结束
}

//交换字节
uint8_t SPI2_SwapByte(uint8_t Byte)
{
	SPI2_Start();//SPI开始
	Byte=SPI2_ExchangeByte(Byte);
    SPI2_End();//SPI结束
    return Byte;
}


//交换数据
void SPI2_SwapData(uint8_t *SendData,uint8_t *ReceiveData,uint8_t DataLength)
{
	SPI2_Start();//SPI开始
	for(uint8_t a=0;a<DataLength;++a)
	{

		*ReceiveData=SPI2_ExchangeByte(*SendData);
		++SendData;
		++ReceiveData;
	}
    SPI2_End();//SPI结束
}

#endif//SPI2_Software


//
////////////////////////////////////////////////////////////////
//结束定义SPI2软件部分





//开始定义SPI2硬件部分
////////////////////////////////////////////////////////////////
//

#ifdef SPI2_Hardware

//发送字节
void SPI2_SendByte(uint8_t Byte)
{
	uint8_t Byte_Byte[1]={Byte};
	HAL_SPI_Transmit(&SPI2_Port,Byte_Byte,1,HAL_MAX_DELAY);

}

//发送数据
//数据长度，数据地址
void SPI2_SendData(uint8_t DataLength,uint8_t *Data)
{

	HAL_SPI_Transmit(&SPI2_Port,Data,DataLength,HAL_MAX_DELAY);

}



//SPI接收字节（单独使用无效）
uint8_t SPI2_ExchangeByte(uint8_t SendByte)
{
	uint8_t ReceiveByte=0;

	HAL_SPI_TransmitReceive(&SPI2_Port,&SendByte,&ReceiveByte,1,HAL_MAX_DELAY);

	return ReceiveByte;

}



#endif//SPI2_Hardware


//
////////////////////////////////////////////////////////////////
//结束定义SPI2硬件部分

#endif//SPIs_H
