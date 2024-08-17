#include"Key.h"
#ifdef Key_H


//开始定义按键部分
////////////////////////////////////////////////////////////////
//

uint8_t Key_Scan_1_State=0;
uint32_t Key_Scan_1_Counter=0;

//Key1按键扫描
void Key_Scan_1()
{
	if(Key_1==0)
	{//当按键第一次按下开始计时
		if(Key_Scan_1_Counter==0)
		{
			Key_Scan_1_Counter=Timer1_Counter1;
		}
	}else
	{
		//按键弹起，只响应大于50毫秒的按压过程，用于消抖
		if(Key_Scan_1_Counter!=0)
		{
			if(Timer1_Counter1-Key_Scan_1_Counter>1000)
			{
				//当按下时间超过一秒，取消当前按键行为并清除按键状态
				Key_Scan_1_State=0;
				Key_Scan_1_Counter=0;
				USART_UART_Printf("K1R\n");
			}else
			if(Timer1_Counter1-Key_Scan_1_Counter>50)
			{
				//每按下一次按键状态加一，通常情况应该响应每一次按键
				++Key_Scan_1_State;
				Key_Scan_1_Counter=0;
				USART_UART_Printf("K1\n");
			}
		}
	}
}

uint8_t Key_Scan_2_State=0;
uint32_t Key_Scan_2_Counter=0;
//Key2按键扫描
void Key_Scan_2()
{
	if(Key_2==0)
	{//当按键第一次按下开始计时
		if(Key_Scan_2_Counter==0)
		{
			Key_Scan_2_Counter=Timer1_Counter1;
		}
	}else
	{
		//按键弹起，只响应大于50毫秒的按压过程，用于消抖
		if(Key_Scan_2_Counter!=0)
		{
			if(Timer1_Counter1-Key_Scan_2_Counter>1000)
			{
				//当按下时间超过一秒，取消当前按键行为并清除按键状态
				Key_Scan_2_State=0;
				Key_Scan_2_Counter=0;
				USART_UART_Printf("K2R\n");
			}else
			if(Timer1_Counter1-Key_Scan_2_Counter>50)
			{
				//每按下一次按键状态加一，通常情况应该响应每一次按键
				++Key_Scan_2_State;
				Key_Scan_2_Counter=0;
				USART_UART_Printf("K2\n");
			}
		}
	}
}



uint8_t Key_Scan_3_State=0;
uint32_t Key_Scan_3_Counter=0;
//Key3按键扫描
void Key_Scan_3()
{
	if(Key_3==0)
	{//当按键第一次按下开始计时
		if(Key_Scan_3_Counter==0)
		{
			Key_Scan_3_Counter=Timer1_Counter1;
		}
	}else
	{
		//按键弹起，只响应大于50毫秒的按压过程，用于消抖
		if(Key_Scan_3_Counter!=0)
		{
			if(Timer1_Counter1-Key_Scan_3_Counter>1000)
			{
				//当按下时间超过一秒，取消当前按键行为并清除按键状态
				Key_Scan_3_State=0;
				Key_Scan_3_Counter=0;
				USART_UART_Printf("K3R\n");
			}else
			if(Timer1_Counter1-Key_Scan_2_Counter>50)
			{
				//每按下一次按键状态加一，通常情况应该响应每一次按键
				++Key_Scan_3_State;
				Key_Scan_3_Counter=0;
				USART_UART_Printf("K3\n");
			}
		}
	}
}



uint8_t Key_Scan_4_State=0;
uint32_t Key_Scan_4_Counter=0;
//Key4按键扫描
void Key_Scan_4()
{
	if(Key_4==0)
	{//当按键第一次按下开始计时
		if(Key_Scan_4_Counter==0)
		{
			Key_Scan_4_Counter=Timer1_Counter1;
		}
	}else
	{
		//按键弹起，只响应大于50毫秒的按压过程，用于消抖
		if(Key_Scan_4_Counter!=0)
		{
			if(Timer1_Counter1-Key_Scan_4_Counter>1000)
			{
				//当按下时间超过一秒，取消当前按键行为并清除按键状态
				Key_Scan_4_State=0;
				Key_Scan_4_Counter=0;
				USART_UART_Printf("K4R\n");
			}else
			if(Timer1_Counter1-Key_Scan_4_Counter>50)
			{
				//每按下一次按键状态加一，通常情况应该响应每一次按键
				++Key_Scan_4_State;
				Key_Scan_4_Counter=0;
				USART_UART_Printf("K4\n");
			}
		}
	}
}




uint8_t Key_Scan_5_State=0;
uint32_t Key_Scan_5_Counter=0;
//Key5按键扫描
void Key_Scan_5()
{
	if(Key_5==0)
	{//当按键第一次按下开始计时
		if(Key_Scan_5_Counter==0)
		{
			Key_Scan_5_Counter=Timer1_Counter1;
		}
	}else
	{
		//按键弹起，只响应大于50毫秒的按压过程，用于消抖
		if(Key_Scan_5_Counter!=0)
		{
			if(Timer1_Counter1-Key_Scan_5_Counter>1000)
			{
				//当按下时间超过一秒，取消当前按键行为并清除按键状态
				Key_Scan_5_State=0;
				Key_Scan_5_Counter=0;
				USART_UART_Printf("K5R\n");
			}else
			if(Timer1_Counter1-Key_Scan_5_Counter>50)
			{
				//每按下一次按键状态加一，通常情况应该响应每一次按键
				++Key_Scan_5_State;
				Key_Scan_5_Counter=0;
				USART_UART_Printf("K5\n");
			}
		}
	}
}



uint8_t Key_Scan_6_State=0;
uint32_t Key_Scan_6_Counter=0;
//Key6按键扫描
void Key_Scan_6()
{
	if(Key_6==0)
	{//当按键第一次按下开始计时
		if(Key_Scan_6_Counter==0)
		{
			Key_Scan_6_Counter=Timer1_Counter1;
		}
	}else
	{
		//按键弹起，只响应大于50毫秒的按压过程，用于消抖
		if(Key_Scan_6_Counter!=0)
		{
			if(Timer1_Counter1-Key_Scan_6_Counter>1000)
			{
				//当按下时间超过一秒，取消当前按键行为并清除按键状态
				Key_Scan_6_State=0;
				Key_Scan_6_Counter=0;
				USART_UART_Printf("K6R\n");
			}else
			if(Timer1_Counter1-Key_Scan_6_Counter>50)
			{
				//每按下一次按键状态加一，通常情况应该响应每一次按键
				++Key_Scan_6_State;
				Key_Scan_6_Counter=0;
				USART_UART_Printf("K6\n");
			}
		}
	}
}



uint8_t Key_Scan_7_State=0;
uint32_t Key_Scan_7_Counter=0;
//Key7按键扫描
void Key_Scan_7()
{
	if(Key_7==0)
	{//当按键第一次按下开始计时
		if(Key_Scan_7_Counter==0)
		{
			Key_Scan_7_Counter=Timer1_Counter1;
		}
	}else
	{
		//按键弹起，只响应大于50毫秒的按压过程，用于消抖
		if(Key_Scan_7_Counter!=0)
		{
			if(Timer1_Counter1-Key_Scan_7_Counter>1000)
			{
				//当按下时间超过一秒，取消当前按键行为并清除按键状态
				Key_Scan_7_State=0;
				Key_Scan_7_Counter=0;
				USART_UART_Printf("K7R\n");
			}else
			if(Timer1_Counter1-Key_Scan_7_Counter>50)
			{
				//每按下一次按键状态加一，通常情况应该响应每一次按键
				++Key_Scan_7_State;
				Key_Scan_7_Counter=0;
				USART_UART_Printf("K7\n");
			}
		}
	}
}



uint8_t Key_Scan_8_State=0;
uint32_t Key_Scan_8_Counter=0;
//Key8按键扫描
void Key_Scan_8()
{
	if(Key_8==0)
	{//当按键第一次按下开始计时
		if(Key_Scan_8_Counter==0)
		{
			Key_Scan_8_Counter=Timer1_Counter1;
		}
	}else
	{
		//按键弹起，只响应大于50毫秒的按压过程，用于消抖
		if(Key_Scan_8_Counter!=0)
		{
			if(Timer1_Counter1-Key_Scan_8_Counter>1000)
			{
				//当按下时间超过一秒，取消当前按键行为并清除按键状态
				Key_Scan_8_State=0;
				Key_Scan_8_Counter=0;
				USART_UART_Printf("K8R\n");
			}else
			if(Timer1_Counter1-Key_Scan_8_Counter>50)
			{
				//每按下一次按键状态加一，通常情况应该响应每一次按键
				++Key_Scan_8_State;
				Key_Scan_8_Counter=0;
				USART_UART_Printf("K8\n");
			}
		}
	}
}



//按键扫描
void Key_Scan_All()
{
	Key_Scan_1();
	Key_Scan_2();
	Key_Scan_3();
	Key_Scan_4();
	Key_Scan_5();
	Key_Scan_6();
	Key_Scan_7();
	Key_Scan_8();
}


//
////////////////////////////////////////////////////////////////
//结束定义按键部分


#endif//Key_H
