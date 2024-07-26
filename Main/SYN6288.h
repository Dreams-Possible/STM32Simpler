#if 0
#ifndef SYN6288_H
#define SYN6288_H
#include"SimpleMain.h"



//串口配置：默认波特率9600


//解释所使用的串口
extern UART_HandleTypeDef huart3;
//解释所使用的DMA
extern DMA_HandleTypeDef hdma_usart3_rx;
extern DMA_HandleTypeDef hdma_usart3_tx;
//重定义串口使用的串口号
#define USART_SYN6288 huart3
//重定义DMA使用的串口
#define USART_SYN6288_RX hdma_usart3_rx
#define USART_SYN6288_TX hdma_usart3_tx
//串口接收的数据
extern uint8_t USART_SYN6288_Data[32];

//串口初始化（开启串口DMA中断，负责接收数据，若仅发送可不需要，必须在IDE中打开串口NVIC中断）
void USART_SYN6288_Initialization();
//串口格式化输出
void USART_SYN6288_Printf(const char *CharacterString,...);
//串口格式化输出DMA
void USART_SYN6288_Printf_DMA(const char *CharacterString,...);
//串口处理接收的数据
void USART_SYN6288_Process();


#endif//SYN6288_H
#endif//0

