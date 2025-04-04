#if 1
#ifndef USART_JDY31_H
#define USART_JDY31_H

#include"SimpleMain.h"

//该驱动代码已经过时
//目前已不再进行维护

//串口配置：默认波特率9600
//打开DMA的RX和TX通道，其余默认即可
//务必打开串口默认中断
//需要注意，串口收发是由串口硬件完成（包括DMA），而不是由CPU直接完成，所以CPU需要有意识的延迟以等待相关硬件完成动作
//因此，在发送时和接收时都应该考虑到数据交换过快导致的硬件错误
//这里推荐使用轮询发送，DMA不定长接收
//虽然也提供了DMA发送，但是延迟太高易吞数据，不推荐使用


//解释所使用的串口
extern UART_HandleTypeDef huart2;
//解释所使用的DMA
extern DMA_HandleTypeDef hdma_usart2_rx;
extern DMA_HandleTypeDef hdma_usart2_tx;
//重定义串口使用的串口号
#define USART_JDY31 huart2
//重定义DMA使用的串口
#define USART_JDY31_RX hdma_usart2_rx
#define USART_JDY31_TX hdma_usart2_tx
//串口接收的数据
extern uint8_t USART_JDY31_Data[32];

//串口初始化（开启串口DMA中断，负责接收数据，若仅发送可不需要，必须在IDE中打开串口NVIC中断）
void USART_JDY31_Initialization();
//串口格式化输出
void USART_JDY31_Printf(const char *CharacterString,...);
//串口处理接收的数据
void USART_JDY31_Process();




#endif//JDY31_H
#endif//0


