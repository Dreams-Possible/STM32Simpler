#include"Keys.h"
#ifdef Keys_H


//开始定义按键部分
////////////////////////////////////////////////////////////////
//

uint8_t Key1_Scan_State=0;
uint32_t Key1_Scan_Counter=0;

//Key1按键扫描
void Key1_Scan()
{
	if(Key1==0)
	{//当按键第一次按下开始计时
		if(Key1_Scan_Counter==0)
		{
			Key1_Scan_Counter=Timer1_Counter1;
		}
	}else
	{
		//按键弹起，只响应大于50毫秒的按压过程，用于消抖
		if(Key1_Scan_Counter!=0)
		{
			if(Timer1_Counter1-Key1_Scan_Counter>1000)
			{
				//当按下时间超过一秒，取消当前按键行为并清除按键状态
				Key1_Scan_State=0;
				Key1_Scan_Counter=0;
				USART_UART_Printf("K1R\n");
			}else
			if(Timer1_Counter1-Key1_Scan_Counter>50)
			{
				//每按下一次按键状态加一，通常情况应该响应每一次按键
				++Key1_Scan_State;
				Key1_Scan_Counter=0;
				USART_UART_Printf("K1\n");
			}
		}
	}
}

uint8_t Key2_Scan_State=0;
uint32_t Key2_Scan_Counter=0;
//Key2按键扫描
void Key2_Scan()
{
	if(Key2==0)
	{//当按键第一次按下开始计时
		if(Key2_Scan_Counter==0)
		{
			Key2_Scan_Counter=Timer1_Counter1;
		}
	}else
	{
		//按键弹起，只响应大于50毫秒的按压过程，用于消抖
		if(Key2_Scan_Counter!=0)
		{
			if(Timer1_Counter1-Key2_Scan_Counter>1000)
			{
				//当按下时间超过一秒，取消当前按键行为并清除按键状态
				Key2_Scan_State=0;
				Key2_Scan_Counter=0;
				USART_UART_Printf("K2R\n");
			}else
			if(Timer1_Counter1-Key2_Scan_Counter>50)
			{
				//每按下一次按键状态加一，通常情况应该响应每一次按键
				++Key2_Scan_State;
				Key2_Scan_Counter=0;
				USART_UART_Printf("K2\n");
			}
		}
	}
}



uint8_t Key3_Scan_State=0;
uint32_t Key3_Scan_Counter=0;
//Key3按键扫描
void Key3_Scan()
{
	if(Key3==0)
	{//当按键第一次按下开始计时
		if(Key3_Scan_Counter==0)
		{
			Key3_Scan_Counter=Timer1_Counter1;
		}
	}else
	{
		//按键弹起，只响应大于50毫秒的按压过程，用于消抖
		if(Key3_Scan_Counter!=0)
		{
			if(Timer1_Counter1-Key3_Scan_Counter>1000)
			{
				//当按下时间超过一秒，取消当前按键行为并清除按键状态
				Key3_Scan_State=0;
				Key3_Scan_Counter=0;
				USART_UART_Printf("K3R\n");
			}else
			if(Timer1_Counter1-Key2_Scan_Counter>50)
			{
				//每按下一次按键状态加一，通常情况应该响应每一次按键
				++Key3_Scan_State;
				Key3_Scan_Counter=0;
				USART_UART_Printf("K3\n");
			}
		}
	}
}



uint8_t Key4_Scan_State=0;
uint32_t Key4_Scan_Counter=0;
//Key4按键扫描
void Key4_Scan()
{
	if(Key4==0)
	{//当按键第一次按下开始计时
		if(Key4_Scan_Counter==0)
		{
			Key4_Scan_Counter=Timer1_Counter1;
		}
	}else
	{
		//按键弹起，只响应大于50毫秒的按压过程，用于消抖
		if(Key4_Scan_Counter!=0)
		{
			if(Timer1_Counter1-Key4_Scan_Counter>1000)
			{
				//当按下时间超过一秒，取消当前按键行为并清除按键状态
				Key4_Scan_State=0;
				Key4_Scan_Counter=0;
				USART_UART_Printf("K4R\n");
			}else
			if(Timer1_Counter1-Key4_Scan_Counter>50)
			{
				//每按下一次按键状态加一，通常情况应该响应每一次按键
				++Key4_Scan_State;
				Key4_Scan_Counter=0;
				USART_UART_Printf("K4\n");
			}
		}
	}
}




uint8_t Key5_Scan_State=0;
uint32_t Key5_Scan_Counter=0;
//Key5按键扫描
void Key5_Scan()
{
	if(Key5==0)
	{//当按键第一次按下开始计时
		if(Key5_Scan_Counter==0)
		{
			Key5_Scan_Counter=Timer1_Counter1;
		}
	}else
	{
		//按键弹起，只响应大于50毫秒的按压过程，用于消抖
		if(Key5_Scan_Counter!=0)
		{
			if(Timer1_Counter1-Key5_Scan_Counter>1000)
			{
				//当按下时间超过一秒，取消当前按键行为并清除按键状态
				Key5_Scan_State=0;
				Key5_Scan_Counter=0;
				USART_UART_Printf("K5R\n");
			}else
			if(Timer1_Counter1-Key5_Scan_Counter>50)
			{
				//每按下一次按键状态加一，通常情况应该响应每一次按键
				++Key5_Scan_State;
				Key5_Scan_Counter=0;
				USART_UART_Printf("K5\n");
			}
		}
	}
}



uint8_t Key6_Scan_State=0;
uint32_t Key6_Scan_Counter=0;
//Key6按键扫描
void Key6_Scan()
{
	if(Key6==0)
	{//当按键第一次按下开始计时
		if(Key6_Scan_Counter==0)
		{
			Key6_Scan_Counter=Timer1_Counter1;
		}
	}else
	{
		//按键弹起，只响应大于50毫秒的按压过程，用于消抖
		if(Key6_Scan_Counter!=0)
		{
			if(Timer1_Counter1-Key6_Scan_Counter>1000)
			{
				//当按下时间超过一秒，取消当前按键行为并清除按键状态
				Key6_Scan_State=0;
				Key6_Scan_Counter=0;
				USART_UART_Printf("K6R\n");
			}else
			if(Timer1_Counter1-Key6_Scan_Counter>50)
			{
				//每按下一次按键状态加一，通常情况应该响应每一次按键
				++Key6_Scan_State;
				Key6_Scan_Counter=0;
				USART_UART_Printf("K6\n");
			}
		}
	}
}



uint8_t Key7_Scan_State=0;
uint32_t Key7_Scan_Counter=0;
//Key7按键扫描
void Key7_Scan()
{
	if(Key7==0)
	{//当按键第一次按下开始计时
		if(Key7_Scan_Counter==0)
		{
			Key7_Scan_Counter=Timer1_Counter1;
		}
	}else
	{
		//按键弹起，只响应大于50毫秒的按压过程，用于消抖
		if(Key7_Scan_Counter!=0)
		{
			if(Timer1_Counter1-Key7_Scan_Counter>1000)
			{
				//当按下时间超过一秒，取消当前按键行为并清除按键状态
				Key7_Scan_State=0;
				Key7_Scan_Counter=0;
				USART_UART_Printf("K7R\n");
			}else
			if(Timer1_Counter1-Key7_Scan_Counter>50)
			{
				//每按下一次按键状态加一，通常情况应该响应每一次按键
				++Key7_Scan_State;
				Key7_Scan_Counter=0;
				USART_UART_Printf("K7\n");
			}
		}
	}
}



uint8_t Key8_Scan_State=0;
uint32_t Key8_Scan_Counter=0;
//Key8按键扫描
void Key8_Scan()
{
	if(Key8==0)
	{//当按键第一次按下开始计时
		if(Key8_Scan_Counter==0)
		{
			Key8_Scan_Counter=Timer1_Counter1;
		}
	}else
	{
		//按键弹起，只响应大于50毫秒的按压过程，用于消抖
		if(Key8_Scan_Counter!=0)
		{
			if(Timer1_Counter1-Key8_Scan_Counter>1000)
			{
				//当按下时间超过一秒，取消当前按键行为并清除按键状态
				Key8_Scan_State=0;
				Key8_Scan_Counter=0;
				USART_UART_Printf("K8R\n");
			}else
			if(Timer1_Counter1-Key8_Scan_Counter>50)
			{
				//每按下一次按键状态加一，通常情况应该响应每一次按键
				++Key8_Scan_State;
				Key8_Scan_Counter=0;
				USART_UART_Printf("K8\n");
			}
		}
	}
}



//所有按键扫描
void Keys_Scan()
{
	Key1_Scan();
	Key2_Scan();
	Key3_Scan();
	Key4_Scan();
	Key5_Scan();
	Key6_Scan();
	Key7_Scan();
	Key8_Scan();
}


//
////////////////////////////////////////////////////////////////
//结束定义按键部分


#endif//Key_H
