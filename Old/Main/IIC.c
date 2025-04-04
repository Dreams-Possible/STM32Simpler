#include "IIC.h"
#ifdef IIC_H




#ifdef IIC_Software
//IIC通讯开始
void IIC_Start()
{
	IIC_SDA(1);
	IIC_SCL(1);
	IIC_SDA(0);//此时已经形成开始条件
	IIC_SCL(0);//先将SCL拉低为后面数据发送做准备
}

//IIC通讯结束
void IIC_End()
{
	IIC_SDA(0);
	IIC_SCL(1);
	IIC_SDA(1);//此时已经形成结束条件
}

//IIC读取应答
int8_t IIC_InACK()
{
	uint8_t ACK;
	IIC_SDA(1);//释放SDA
	IIC_SCL(1);
	ACK=IIC_SDA_In;//读取ACK
	IIC_SCL(0);
	return ACK;
}

//IIC发送应答
void IIC_OutACK(uint8_t ACK)
{
	IIC_SDA(ACK);//应答生效，1不生效(NACK)，0生效(ACK)
	IIC_SCL(1);
	IIC_SCL(0);
}

//IIC接收字节
int8_t IIC_InByte()
{
    uint8_t Byte=0;
    IIC_SDA(1);//释放SDA
    for(uint8_t a=0;a<8;++a)
	{
		IIC_SCL(1);
		if(IIC_SDA_In)
		{
			Byte|=(0x80>>a);//将16进制数一位一位读入
		};
		IIC_SCL(0);
	}
    return Byte;//读取到的数据
}

//IIC发送字节
void IIC_OutByte(uint8_t Byte)
{
    for(uint8_t a=0;a<8;++a)
    {
    	IIC_SDA(Byte&(0x80>>a));//将16进制数一位一位取出来
    	IIC_SCL(1);
    	IIC_SCL(0);
    }
}



//发送字节
//设备地址，字节
int8_t IIC_SendByte(uint8_t DeviceAddress,uint8_t Byte)
{
	IIC_Start();//开始
	IIC_OutByte(DeviceAddress|0);//发送设备地址以及写入标志0
	if(IIC_InACK())
	{//等待应答信号
		USART_UART_Printf("ICSdEr1\n");
		return -1;//通信失败
	};

	IIC_OutByte(Byte);//发送要写入的数据
	if(IIC_InACK())
	{//等待应答信号
		USART_UART_Printf("ICSdEr2\n");
		return -2;//通信失败
	};

	IIC_End();//结束
	USART_UART_Printf("ICSdSc\n");
	return 0;//通信成功
}

//向寄存器写字节
//设备地址，寄存器地址，字节
int8_t IIC_WriteByte(uint8_t DeviceAddress,uint8_t RegisterAddress,uint8_t Byte)
{
	IIC_Start();//开始
	IIC_OutByte(DeviceAddress|0);//发送设备地址以及写入标志0
	if(IIC_InACK())
	{//等待应答信号
		USART_UART_Printf("ICWtEr1\n");
		return -1;//通信失败
	};
	IIC_OutByte(RegisterAddress);//发送将要写入的寄存器的地址
	if(IIC_InACK())
	{//等待应答信号
		USART_UART_Printf("ICWtEr2\n");
		return -2;//通信失败
	};

	IIC_OutByte(Byte);//发送要写入的数据
	if(IIC_InACK())
	{//等待应答信号
		USART_UART_Printf("ICWtEr3\n");
		return -3;//通信失败
	}

	IIC_End();//结束
	//USART_UART_Printf("ICWtSc\n");
	//HAL_Delay(10);
	return 0;//通信成功
}



//发送数据
//设备地址，数据长度，数据地址
int8_t IIC_SendData(uint8_t DeviceAddress,uint8_t DataLength,uint8_t *Data)
{
	IIC_Start();//开始
	IIC_OutByte(DeviceAddress|0);//发送设备地址以及写入标志0
	if(IIC_InACK())
	{//等待应答信号
		USART_UART_Printf("ICSdEr1\n");
		return -1;//通信失败
	};

	if(DataLength==1)
	{
		IIC_OutByte(*Data);//发送要写入的数据
		if(IIC_InACK())
		{//等待应答信号
			USART_UART_Printf("ICSdEr2\n");
			return -2;//通信失败
		};
	}else
	{
		for(uint8_t a=0;a<DataLength;++a)
		{
			IIC_OutByte(Data[a]);//发送要写入的数据
			if(IIC_InACK())
			{//等待应答信号
				USART_UART_Printf("ICSdEr2\n");
				return -2;//通信失败
			};
		}
	}

	IIC_End();//结束
	//USART_UART_Printf("ICSdSc\n");
	return 0;//通信成功
}

//接收数据
//设备地址，数据长度，数据地址
int8_t IIC_ReceiveData(uint8_t DeviceAddress,uint8_t DataLength,uint8_t *Data)
{
	IIC_Start();//开始
	IIC_OutByte(DeviceAddress|1);//发送设备地址以及读取标志1
	if(IIC_InACK())
	{//等待应答信号
		USART_UART_Printf("ICRds1\n");
		return -1;//通信失败
	};
	while(DataLength)
	{
		*Data=IIC_InByte();//接收数据
		if(DataLength==1)
		{
			IIC_OutACK(1);//应答信号
		}else
		{
			IIC_OutACK(0);//应答信号
		}
		--DataLength;
		++Data;
	}
	IIC_End();//结束
	USART_UART_Printf("ICRdSc\n");
	return 0;//通信成功
}

//向寄存器写数据
//设备地址，寄存器地址，数据长度，数据地址
int8_t IIC_WriteData(uint8_t DeviceAddress,uint8_t RegisterAddress,uint8_t DataLength,uint8_t *Data)
{
	IIC_Start();//开始
	IIC_OutByte(DeviceAddress|0);//发送设备地址以及写入标志0
	if(IIC_InACK())
	{//等待应答信号
		USART_UART_Printf("ICWtEr1\n");
		return -1;//通信失败
	};
	IIC_OutByte(RegisterAddress);//发送将要写入的寄存器的地址
	if(IIC_InACK())
	{//等待应答信号
		USART_UART_Printf("ICWtEr2\n");
		return -2;//通信失败
	};

	for(uint8_t a=0;a<DataLength;++a)
	{
		IIC_OutByte(Data[a]);//发送要写入的数据
		if(IIC_InACK())
		{//等待应答信号
			USART_UART_Printf("ICWtEr3\n");
			return -3;//通信失败
		};
	}


	IIC_End();//结束
	//USART_UART_Printf("ICWtSc\n");
	//HAL_Delay(10);
	return 0;//通信成功
}

//从寄存器读数据
//设备地址，寄存器地址，数据长度，数据地址
int8_t IIC_ReadData(uint8_t DeviceAddress,uint8_t RegisterAddress,uint8_t DataLength,uint8_t *Data)
{
	IIC_Start();//开始
	IIC_OutByte(DeviceAddress|0);//发送设备地址以及写入标志0
	if(IIC_InACK())
	{//等待应答信号
		USART_UART_Printf("ICRdEr1\n");
		return -1;//通信失败
	};
	IIC_OutByte(RegisterAddress);//发送将要读取数据的寄存器的地址
	if(IIC_InACK())
	{//等待应答信号
		USART_UART_Printf("ICRdEr2\n");
		return -2;//通信失败
	};
	IIC_Start();//继续开始
	IIC_OutByte(DeviceAddress|1);//发送设备地址以及读取标志1
	if(IIC_InACK())
	{//等待应答信号
		USART_UART_Printf("ICRdEr3\n");
		return -3;//通信失败
	};
	while(DataLength)
	{
		*Data=IIC_InByte();//接收数据
		if(DataLength==1)
		{
			IIC_OutACK(1);//应答信号
		}else
		{
			IIC_OutACK(0);//应答信号
		}
		--DataLength;
		++Data;
	}
	IIC_End();//结束
	//USART_UART_Printf("ICRdSc\n");
	return 0;//通信成功
}
#endif//IIC_Software



#ifdef IIC_Hardware
//发送字节
//设备地址，字节
int8_t IIC_SendByte(uint8_t DeviceAddress,uint8_t Byte)
{
	uint8_t Byte_Byte[1]={Byte};

	if(HAL_I2C_Master_Transmit(&IIC_Hardware1,DeviceAddress,Byte_Byte,1,HAL_MAX_DELAY)==HAL_OK)
	{
		return 0;
	}else
	{
		USART_UART_Printf("ICSdEr4\n");
		return -1;
	}
}

//向寄存器写字节
//设备地址，寄存器地址，字节
int8_t IIC_WriteByte(uint8_t DeviceAddress,uint8_t RegisterAddress,uint8_t Byte)
{
	uint8_t Byte_Byte[1]={Byte};

	if(HAL_I2C_Mem_Write(&IIC_Hardware1,DeviceAddress,RegisterAddress,I2C_MEMADD_SIZE_8BIT,Byte_Byte,1,HAL_MAX_DELAY)==HAL_OK)
	{
		return 0;
	}else
	{
		USART_UART_Printf("ICWtEr4\n");
		return -1;
	}
}



//发送数据
//设备地址，数据长度，数据地址
int8_t IIC_SendData(uint8_t DeviceAddress,uint8_t DataLength,uint8_t *Data)
{
	if(HAL_I2C_Master_Transmit(&IIC_Hardware1,DeviceAddress,Data,DataLength,HAL_MAX_DELAY)==HAL_OK)
	{
		return 0;
	}else
	{
		USART_UART_Printf("ICSdEr4\n");
		return -1;
	}
}

//接收数据
//设备地址，数据长度，数据地址
int8_t IIC_ReceiveData(uint8_t DeviceAddress,uint8_t DataLength,uint8_t *Data)
{
	if(HAL_I2C_Master_Receive(&IIC_Hardware1,DeviceAddress,Data,DataLength,HAL_MAX_DELAY)==HAL_OK)
	{
		return 0;
	}else
	{
		USART_UART_Printf("ICRcEr4\n");
		return -1;
	}
}

//向寄存器写数据
//设备地址，寄存器地址，数据长度，数据地址
int8_t IIC_WriteData(uint8_t DeviceAddress,uint8_t RegisterAddress,uint8_t DataLength,uint8_t *Data)
{
	if(HAL_I2C_Mem_Write(&IIC_Hardware1,DeviceAddress,RegisterAddress,I2C_MEMADD_SIZE_8BIT,Data,DataLength,HAL_MAX_DELAY)==HAL_OK)
	{
		return 0;
	}else
	{
		USART_UART_Printf("ICWtEr4\n");
		return -1;
	}
}

//从寄存器读数据
//设备地址，寄存器地址，数据长度，数据地址
int8_t IIC_ReadData(uint8_t DeviceAddress,uint8_t RegisterAddress,uint8_t DataLength,uint8_t *Data)
{
	if(HAL_I2C_Mem_Read(&IIC_Hardware1,DeviceAddress,RegisterAddress,I2C_MEMADD_SIZE_8BIT,Data,DataLength,HAL_MAX_DELAY)==HAL_OK)
	{
		return 0;
	}else
	{
		USART_UART_Printf("ICRdEr4\n");
		return -1;
	}

}


//发送字节
//设备地址，字节
int8_t IIC_SendByte_DMA(uint8_t DeviceAddress,uint8_t Byte)
{
	uint8_t Byte_Byte[1]={Byte};

	if(HAL_I2C_Master_Transmit_DMA(&IIC_Hardware1,DeviceAddress,Byte_Byte,1)==HAL_OK)
	{
		return 0;
	}else
	{
		USART_UART_Printf("ICSdEr4\n");
		return -1;
	}
}

//向寄存器写字节
//设备地址，寄存器地址，字节
int8_t IIC_WriteByte_DMA(uint8_t DeviceAddress,uint8_t RegisterAddress,uint8_t Byte)
{
	uint8_t Byte_Byte[1]={Byte};

	if(HAL_I2C_Mem_Write_DMA(&IIC_Hardware1,DeviceAddress,RegisterAddress,I2C_MEMADD_SIZE_8BIT,Byte_Byte,1)==HAL_OK)
	{
		return 0;
	}else
	{
		USART_UART_Printf("ICWtEr4\n");
		return -1;
	}
}



//发送数据
//设备地址，数据长度，数据地址
int8_t IIC_SendData_DMA(uint8_t DeviceAddress,uint8_t DataLength,uint8_t *Data)
{
	if(HAL_I2C_Master_Transmit_DMA(&IIC_Hardware1,DeviceAddress,Data,DataLength)==HAL_OK)
	{
		return 0;
	}else
	{
		USART_UART_Printf("ICSdEr4\n");
		return -1;
	}
}

//接收数据
//设备地址，数据长度，数据地址
int8_t IIC_ReceiveData_DMA(uint8_t DeviceAddress,uint8_t DataLength,uint8_t *Data)
{
	if(HAL_I2C_Master_Receive_DMA(&IIC_Hardware1,DeviceAddress,Data,DataLength)==HAL_OK)
	{
		return 0;
	}else
	{
		USART_UART_Printf("ICRcEr4\n");
		return -1;
	}
}

//向寄存器写数据
//设备地址，寄存器地址，数据长度，数据地址
int8_t IIC_WriteData_DMA(uint8_t DeviceAddress,uint8_t RegisterAddress,uint8_t DataLength,uint8_t *Data)
{
	if(HAL_I2C_Mem_Write_DMA(&IIC_Hardware1,DeviceAddress,RegisterAddress,I2C_MEMADD_SIZE_8BIT,Data,DataLength)==HAL_OK)
	{
		return 0;
	}else
	{
		USART_UART_Printf("ICWtEr4\n");
		return -1;
	}
}

//从寄存器读数据
//设备地址，寄存器地址，数据长度，数据地址
int8_t IIC_ReadData_DMA(uint8_t DeviceAddress,uint8_t RegisterAddress,uint8_t DataLength,uint8_t *Data)
{
	if(HAL_I2C_Mem_Read_DMA(&IIC_Hardware1,DeviceAddress,RegisterAddress,I2C_MEMADD_SIZE_8BIT,Data,DataLength)==HAL_OK)
	{
		return 0;
	}else
	{
		USART_UART_Printf("ICRdEr4\n");
		return -1;
	}

}
#endif//IIC_Hardware



#endif//IIC_H





