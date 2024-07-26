#include"SYN6288.h"
#ifdef SYN6288_H




//串口初始化（开启串口DMA中断，负责接收数据，若仅发送可不需要，必须先在IDE中打开串口NVIC中断）
void USART_SYN6288_Initialization()
{
	//接收任意字节中断
	HAL_UARTEx_ReceiveToIdle_DMA(&USART_SYN6288,USART_SYN6288_Data,sizeof(USART_SYN6288_Data));
	//关闭DMA接收过半中断
	__HAL_DMA_DISABLE_IT(&USART_SYN6288_RX,DMA_IT_HT);
}





//串口格式化输出（只支持字母和数字）
void USART_SYN6288_Printf1(const char *CharacterString,...)
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

	uint8_t FrameData[5];
	uint8_t Music=0;
	FrameData[0]=0xfd;//帧头
	FrameData[1]=0x00;//数据区长度的高字节
	FrameData[2]=strlen((char*)StringData)+3;//数据区长度的低字节
	FrameData[3]=0x01;//合成播放命令
	FrameData[4]=0x01|Music<<4;//背景音乐设定

	//计算校验码
	uint8_t ECC=0;
	for(uint8_t a=0;a<5;++a)
	{
		ECC^=FrameData[a];//帧头异或校验
	}
	for(uint8_t a=0;a<strlen((char*)StringData);++a)
	{
		ECC^=(StringData[a]);//数据异或校验
	}

	//串口发送
	HAL_UART_Transmit(&USART_SYN6288,FrameData,5,HAL_MAX_DELAY);
	HAL_UART_Transmit(&USART_SYN6288,StringData,strlen((char*)StringData),HAL_MAX_DELAY);
	HAL_UART_Transmit(&USART_SYN6288,&ECC,1,HAL_MAX_DELAY);
}



//串口格式化输出（只支持中文，要求格式必须为gbk）
void USART_SYN6288_Printf2(uint8_t *StringData)
{

	uint8_t FrameData[5];
	uint8_t Music=0;
	FrameData[0]=0xfd;//帧头
	FrameData[1]=0x00;//数据区长度的高字节
	FrameData[2]=strlen((char*)StringData)+3;//数据区长度的低字节
	FrameData[3]=0x01;//合成播放命令
	FrameData[4]=0x01|Music<<4;//背景音乐设定

	//计算校验码
	uint8_t ECC=0;
	for(uint8_t a=0;a<5;++a)
	{
		ECC^=FrameData[a];//帧头异或校验
	}
	for(uint8_t a=0;a<strlen((char*)StringData);++a)
	{
		ECC^=(StringData[a]);//数据异或校验
	}

	//串口发送
	HAL_UART_Transmit(&USART_SYN6288,FrameData,5,HAL_MAX_DELAY);
	HAL_UART_Transmit(&USART_SYN6288,StringData,strlen((char*)StringData),HAL_MAX_DELAY);
	HAL_UART_Transmit(&USART_SYN6288,&ECC,1,HAL_MAX_DELAY);


}




#endif//SYN6288_H
