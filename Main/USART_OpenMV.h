#if 0
#ifndef USART_OpenMV_H
#define USART_OpenMV_H
#include"SimpleMain.h"



//串口配置：默认波特率115200
//打开DMA的RX和TX通道，其余默认即可
//务必打开串口默认中断
//需要注意，串口收发是由串口硬件完成（包括DMA），而不是由CPU直接完成，所以CPU需要有意识的延迟以等待相关硬件完成动作
//因此，在发送时和接收时都应该考虑到数据交换过快导致的硬件错误
//这里推荐使用轮询发送，DMA不定长接收
//虽然也提供了DMA发送，但是延迟太高易吞数据，不推荐使用


//解释所使用的串口
extern UART_HandleTypeDef huart3;
//解释所使用的DMA
extern DMA_HandleTypeDef hdma_usart3_rx;
extern DMA_HandleTypeDef hdma_usart3_tx;
//重定义串口使用的串口号
#define USART_OpenMV huart3
//重定义DMA使用的串口
#define USART_OpenMV_RX hdma_usart3_rx
#define USART_OpenMV_TX hdma_usart3_tx
//串口接收的数据
extern uint8_t USART_OpenMV_Data[32];

//串口初始化（开启串口DMA中断，负责接收数据，若仅发送可不需要，必须在IDE中打开串口NVIC中断）
void USART_OpenMV_Initialization();
//串口格式化输出
void USART_OpenMV_Printf(const char *CharacterString,...);
//串口格式化输出DMA
void USART_OpenMV_Printf_DMA(const char *CharacterString,...);
//串口处理接收的数据
void USART_OpenMV_Process();







//OpenMV数值
extern double OpenMVNumber;
//OpenMV标志
//0无消息1新消息
extern uint8_t OpenMV_Flag;




#endif//USART_OpenMV_H
#endif//0
