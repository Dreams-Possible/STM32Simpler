#include"LEDs.h"
#ifdef LEDs_H


//开始定义灯部分
////////////////////////////////////////////////////////////////
//

//LED1
//0红1绿2蓝
void LED1(uint8_t Color,uint8_t Switch)
{
	if(Color==0)
	{
		LED1_R(Switch);
	}else
	if(Color==1)
	{
		LED1_G(Switch);
	}else
	if(Color==2)
	{
		LED1_B(Switch);
	}
}

//LED1闪烁
void LED1_Scan(uint8_t Color)
{
	static uint8_t LED1_State=0;

	if(LED1_State)
	{
		LED1_State=0;
		if(Color==0)
		{
			LED1_R(LED1_State);
		}else
		if(Color==1)
		{
			LED1_G(LED1_State);
		}else
		if(Color==2)
		{
			LED1_B(LED1_State);
		}
	}else
	{
		LED1_State=1;
		if(Color==0)
		{
			LED1_R(LED1_State);
		}else
		if(Color==1)
		{
			LED1_G(LED1_State);
		}else
		if(Color==2)
		{
			LED1_B(LED1_State);
		}
	}

}





//LED2
//0红1绿2蓝
void LED2(uint8_t Color,uint8_t Switch)
{
	if(Color==0)
	{
		LED2_R(Switch);
	}else
	if(Color==1)
	{
		LED2_G(Switch);
	}else
	if(Color==2)
	{
		LED2_B(Switch);
	}
}

//LED2闪烁
void LED2_Scan(uint8_t Color)
{
	static uint8_t LED2_State=0;

	if(LED2_State)
	{
		LED2_State=0;
		if(Color==0)
		{
			LED2_R(LED2_State);
		}else
		if(Color==1)
		{
			LED2_G(LED2_State);
		}else
		if(Color==2)
		{
			LED2_B(LED2_State);
		}
	}else
	{
		LED2_State=1;
		if(Color==0)
		{
			LED2_R(LED2_State);
		}else
		if(Color==1)
		{
			LED2_G(LED2_State);
		}else
		if(Color==2)
		{
			LED2_B(LED2_State);
		}
	}

}







//LED3
//0红1绿2蓝
void LED3(uint8_t Color,uint8_t Switch)
{
	if(Color==0)
	{
		LED3_R(Switch);
	}else
	if(Color==1)
	{
		LED3_G(Switch);
	}else
	if(Color==2)
	{
		LED3_B(Switch);
	}
}

//LED3闪烁
void LED3_Scan(uint8_t Color)
{
	static uint8_t LED3_State=0;

	if(LED3_State)
	{
		LED3_State=0;
		if(Color==0)
		{
			LED3_R(LED3_State);
		}else
		if(Color==1)
		{
			LED3_G(LED3_State);
		}else
		if(Color==2)
		{
			LED3_B(LED3_State);
		}
	}else
	{
		LED3_State=1;
		if(Color==0)
		{
			LED3_R(LED3_State);
		}else
		if(Color==1)
		{
			LED3_G(LED3_State);
		}else
		if(Color==2)
		{
			LED3_B(LED3_State);
		}
	}

}




//LED流水灯Dmeo
void LEDs_Dmeo()
{
	static uint8_t State=0;

	LED1(State%3,1);
	LED1((State+1)%3,0);
	LED1((State+2)%3,0);

	LED2(State%3,0);
	LED2((State+1)%3,1);
	LED2((State+2)%3,0);

	LED3(State%3,0);
	LED3((State+1)%3,0);
	LED3((State+2)%3,1);


	++State;
}



//
////////////////////////////////////////////////////////////////
//结束定义灯部分

#endif//SimpleIO_H
