#include"SimpleIO.h"
#ifdef SimpleIO_H

//该驱动代码已经过时
//目前已不再进行维护

//LED1电平翻转
void SimpleIO_LED1()
{
	if(Pin1_In)
	{
		Pin1_Out(0);
	}else
	{
		Pin1_Out(1);
	}
}

//LED2电平翻转
void SimpleIO_LED2()
{

	if(Pin2_In)
	{
		Pin2_Out(0);
	}else
	{
		Pin2_Out(1);
	}

}

uint8_t SimpleIO_Key1_State=0;
uint32_t SimpleIO_Key1_Counter=0;

//Key1按键扫描
void SimpleIO_Key1()
{
	if(Pin3_In==0)
	{//当按键第一次按下开始计时
		if(SimpleIO_Key1_Counter==0)
		{
			SimpleIO_Key1_Counter=Timer1_Counter1;
		}
	}else
	{
		//按键弹起，只响应大于50毫秒的按压过程，用于消抖
		if(SimpleIO_Key1_Counter!=0)
		{
			if(Timer1_Counter1-SimpleIO_Key1_Counter>1000)
			{
				//当按下时间超过一秒，取消当前按键行为并清除按键状态
				SimpleIO_Key1_State=0;
				SimpleIO_Key1_Counter=0;
				USART_UART_Printf("K1R\n");
			}else
			if(Timer1_Counter1-SimpleIO_Key1_Counter>50)
			{
				//每按下一次按键状态加一，通常情况应该响应每一次按键
				++SimpleIO_Key1_State;
				SimpleIO_Key1_Counter=0;
				USART_UART_Printf("K1\n");
			}
		}
	}
}

uint8_t SimpleIO_Key2_State=0;
uint32_t SimpleIO_Key2_Counter=0;
//Key2按键扫描
void SimpleIO_Key2()
{
	if(Pin4_In==0)
	{//当按键第一次按下开始计时
		if(SimpleIO_Key2_Counter==0)
		{
			SimpleIO_Key2_Counter=Timer1_Counter1;
		}
	}else
	{
		//按键弹起，只响应大于50毫秒的按压过程，用于消抖
		if(SimpleIO_Key2_Counter!=0)
		{
			if(Timer1_Counter1-SimpleIO_Key2_Counter>1000)
			{
				//当按下时间超过一秒，取消当前按键行为并清除按键状态
				SimpleIO_Key2_State=0;
				SimpleIO_Key2_Counter=0;
				USART_UART_Printf("K2R\n");
			}else
			if(Timer1_Counter1-SimpleIO_Key2_Counter>50)
			{
				//每按下一次按键状态加一，通常情况应该响应每一次按键
				++SimpleIO_Key2_State;
				SimpleIO_Key2_Counter=0;
				USART_UART_Printf("K2\n");
			}
		}
	}
}


//蜂鸣器
//状态0关闭，状态1开启
void SimpleIO_Buzzer(uint8_t State)
{
	if(State)
	{
		Pin4_Out(0);
	}else
	{
		Pin4_Out(1);
	}
}


#endif//SimpleIO_H
