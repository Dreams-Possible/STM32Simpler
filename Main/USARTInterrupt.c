#include"USARTInterrupt.h"
#ifdef USARTInterrupt_H


//开始定义串口中断部分
////////////////////////////////////////////////////////////////
//

//所有DMA串口中断（借助HAL库实现部分，在HAL库中，所有的DMA串口中断被集中在一个函数里处理）
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef*huart,uint16_t Size)
{
	Error_Printf("UTRx_");

	//串口1
	#ifdef UART1_H
	if(huart==&UART1)
	{
		Error_Printf("UART\n");
		//串口处理数据
		UART1_Process();
		//串口初始化
		UART1_Initialization();
	}
	#endif//UART1_H


}

//所有串口错误中断（借助HAL库实现部分，在HAL库中，所有的串口错误中断被集中在一个函数里处理）
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
	Error_Printf("UTEr_");

	//串口1
	#ifdef UART1_H
	if(huart==&UART1)
	{
		Error_Printf("UART\n");
		//进入错误中断时串口状态被标志为繁忙，需要解锁之后才能继续使能串口接收中断
		__HAL_UNLOCK(huart);
		//串口初始化
		UART1_Initialization();
	}
	#endif//UART1_H
}

//
////////////////////////////////////////////////////////////////
//结束定义串口中断部分

#endif//USARTInterrupt_H















