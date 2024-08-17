#include"USARTInterrupt.h"
#ifdef USARTInterrupt_H


//开始定义串口中断部分
////////////////////////////////////////////////////////////////
//

//所有DMA串口中断（借助HAL库实现部分，在HAL库中，所有的DMA串口中断被集中在一个函数里处理）
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef*huart,uint16_t Size)
{
	USART_UART_Printf("UTRx_");

	//默认串口
	#ifdef USART_UART_H
	if(huart==&USART_UART)
	{
		USART_UART_Printf("UART\n");
		//串口处理数据
		USART_UART_Process();
		//串口初始化
		USART_UART_Initialization();
	}
	#endif//USART_UART_H

	//JDY31
	#ifdef USART_JDY31_H
	if(huart==&USART_JDY31)
	{
		USART_UART_Printf("JDY\n");
		//串口处理数据
		USART_JDY31_Process();
		//串口初始化
		USART_JDY31_Initialization();
	}
	#endif//USART_JDY31_H

	//OpenMV
	#ifdef USART_OpenMV_H
	if(huart==&USART_OpenMV)
	{
		USART_UART_Printf("OpenMV\n");
		//串口处理数据
		USART_OpenMV_Process();
		//串口初始化
		USART_OpenMV_Initialization();
	}
	#endif//USART_OpenMV_H

}

//所有串口错误中断（借助HAL库实现部分，在HAL库中，所有的串口错误中断被集中在一个函数里处理）
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
	USART_UART_Printf("UTEr_");

	//默认串口
	#ifdef USART_UART_H
	if(huart==&USART_UART)
	{
		USART_UART_Printf("UART\n");
		//进入错误中断时串口状态被标志为繁忙，需要解锁之后才能继续使能串口接收中断
		__HAL_UNLOCK(huart);
		//串口初始化
		USART_UART_Initialization();
	}
	#endif//USART_UART_H

	//JDY31
	#ifdef USART_JDY31_H
	if(huart==&USART_JDY31)
	{
		USART_UART_Printf("JDY\n");
		//进入错误中断时串口状态被标志为繁忙，需要解锁之后才能继续使能串口接收中断
		__HAL_UNLOCK(huart);
		//串口初始化
		USART_JDY31_Initialization();
	}
	#endif//USART_JDY31_H

	//OpenMV
	#ifdef USART_OpenMV_H
	if(huart==&USART_OpenMV)
	{
		USART_UART_Printf("OPMV\n");
		//进入错误中断时串口状态被标志为繁忙，需要解锁之后才能继续使能串口接收中断
		__HAL_UNLOCK(huart);
		//串口初始化
		USART_OpenMV_Initialization();
	}
	#endif//USART_OpenMV_H


//	//星瞳AI
//	#ifdef SingTownAI_H
//	if(huart==&USART_SingTownAI)
//	{
//		USART_UART_Printf("STAI\n");
//		//进入错误中断时串口状态被标志为繁忙，需要解锁之后才能继续使能串口接收中断
//		__HAL_UNLOCK(huart);
//	}
//	#endif//SingTownAI_H

}



//
////////////////////////////////////////////////////////////////
//结束定义串口中断部分

#endif//USARTInterrupt_H















