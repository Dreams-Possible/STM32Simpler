#include"USART_JDY31.h"
#ifdef USART_JDY31_H

//该驱动代码已经过时
//目前已不再进行维护


//串口接收的数据（最大暂定32个字节）
uint8_t USART_JDY31_Data[32]=
		{
			0
		};


//串口初始化（开启串口DMA中断，负责接收数据，若仅发送可不需要，必须先在IDE中打开串口NVIC中断）
void USART_JDY31_Initialization()
{
	//接收任意字节中断
	HAL_UARTEx_ReceiveToIdle_DMA(&USART_JDY31,USART_JDY31_Data,sizeof(USART_JDY31_Data));
	//关闭DMA接收过半中断
	__HAL_DMA_DISABLE_IT(&USART_JDY31_RX,DMA_IT_HT);
}

//串口格式化输出
void USART_JDY31_Printf(const char *CharacterString,...)
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
	HAL_UART_Transmit(&USART_JDY31,StringData,strlen((char*)StringData),HAL_MAX_DELAY);
}


//串口处理接收的数据
void USART_JDY31_Process()
{

	//清空接收值
	memset(USART_UART_Data,0,sizeof(USART_JDY31_Data));
}


#endif//JDY31_H

