#if 1
#ifndef USART_UART1_H
#define USART_UART1_H
#include"SimpleMain.h"



//配置如下
////////////////////////////////////////////////////////////////
//

//串口配置：默认波特率115200
//打开DMA的RX和TX通道，其余默认即可
//务必打开串口默认中断
//需要注意，串口收发是由串口硬件完成（包括DMA），而不是由CPU直接完成，所以CPU需要有意识的延迟以等待相关硬件完成动作
//因此，在发送时和接收时都应该考虑到数据交换过快导致的硬件错误
//这里推荐使用轮询发送，DMA不定长接收
//虽然也提供了DMA发送，但是延迟太高易吞数据，不推荐使用

//将下方的huart1更改为你实际使用的串口即可

//
////////////////////////////////////////////////////////////////
//结束配置




//开始串口配置
////////////////////////////////////////////////////////////////
//

//解释所使用的串口
extern UART_HandleTypeDef huart1;
//解释所使用的DMA
extern DMA_HandleTypeDef hdma_usart1_rx;
extern DMA_HandleTypeDef hdma_usart1_tx;
//重定义串口使用的串口号
#define USART_UART1 huart1
//重定义DMA使用的串口
#define USART_UART1_RX hdma_usart1_rx
#define USART_UART1_TX hdma_usart1_tx
//串口接收的数据
extern uint8_t USART_UART1_Data[32];

//串口初始化（开启串口DMA中断，负责接收数据，若仅发送可不需要，必须在IDE中打开串口NVIC中断）
void USART_UART1_Initialization();
//串口格式化输出
void USART_UART1_Printf(const char *CharacterString,...);
//串口格式化输出DMA
void USART_UART1_Printf_DMA(const char *CharacterString,...);
//串口处理接收的数据
void USART_UART1_Process();


//
////////////////////////////////////////////////////////////////
//结束串口配置



#endif//USART_UART1_H
#endif//0
