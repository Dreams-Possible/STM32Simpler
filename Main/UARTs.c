#include"UARTs.h"
#ifdef UARTs_H


//开始定义空串口部分
////////////////////////////////////////////////////////////////
//

//串口格式化输出
void UART0_Printf(const char *CharacterString,...)
{
	return;
}

//
////////////////////////////////////////////////////////////////
//结束定义空串口部分




//开始定义串口1部分
////////////////////////////////////////////////////////////////
//


//串口接收的数据（最大暂定32个字节）
uint8_t UART1_Data[32]=
		{
			0
		};


//串口初始化（开启串口DMA中断，负责接收数据，若仅发送可不需要，必须先在IDE中打开串口NVIC中断）
void UART1_Initialization()
{
	//接收任意字节中断
	HAL_UARTEx_ReceiveToIdle_DMA(&UART1,UART1_Data,sizeof(UART1_Data));
	//关闭DMA接收过半中断
	__HAL_DMA_DISABLE_IT(&UART1_RX,DMA_IT_HT);

	memset(UART1_Data,0,sizeof(UART1_Data));
}

//串口格式化输出
void UART1_Printf(const char *CharacterString,...)
{
	//最大暂定32个字符
	uint8_t StringData[32]=
		{
			0
		};
	//使用可变参数列表
	va_list args;
	va_start(args,CharacterString);
	//将参数传递给vsprintf函数
	vsprintf((char*)StringData,(char*)CharacterString,args);
	//结束可变参数列表
	va_end(args);
	//串口发送
	HAL_UART_Transmit(&UART1,StringData,strlen((char*)StringData),HAL_MAX_DELAY);
}

//串口格式化输出DMA（两次发送时间间隔太短会吞数据）
void UART1_Printf_DMA(const char *CharacterString,...)
{
	//最大暂定32个字符
	uint8_t StringData[32]=
		{
			0
		};
	//使用可变参数列表
	va_list args;
	va_start(args,CharacterString);
	//将参数传递给vsprintf函数
	vsprintf((char*)StringData,(char*)CharacterString,args);
	//结束可变参数列表
	va_end(args);
	//串口发送
	HAL_UART_Transmit_DMA(&UART1,StringData,strlen((char*)StringData));
}


//串口处理接收的数据
void UART1_Process()
{

	//清空接收值
	memset(UART1_Data,0,sizeof(UART1_Data));
}


//
////////////////////////////////////////////////////////////////
//结束定义串口1部分


#endif//UART1_H
