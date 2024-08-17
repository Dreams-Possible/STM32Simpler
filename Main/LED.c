#include"LED.h"
#ifdef LED_H


//开始定义灯部分
////////////////////////////////////////////////////////////////
//

//LED1
//0红1绿2蓝
void LED_1(uint8_t Color,uint8_t Switch)
{
	if(Color==0)
	{
		LED_R_1(Switch);
	}else
	if(Color==1)
	{
		LED_G_1(Switch);
	}else
	if(Color==2)
	{
		LED_B_1(Switch);
	}
}

//LED1闪烁
void LED_1_Scan(uint8_t Color)
{
	static uint8_t LED_State_1=0;

	if(LED_State_1)
	{
		LED_State_1=0;
		if(Color==0)
		{
			LED_R_1(LED_State_1);
		}else
		if(Color==1)
		{
			LED_G_1(LED_State_1);
		}else
		if(Color==2)
		{
			LED_B_1(LED_State_1);
		}
	}else
	{
		LED_State_1=1;
		if(Color==0)
		{
			LED_R_1(LED_State_1);
		}else
		if(Color==1)
		{
			LED_G_1(LED_State_1);
		}else
		if(Color==2)
		{
			LED_B_1(LED_State_1);
		}
	}

}





//LED2
//0红1绿2蓝
void LED_2(uint8_t Color,uint8_t Switch)
{
	if(Color==0)
	{
		LED_R_2(Switch);
	}else
	if(Color==1)
	{
		LED_G_2(Switch);
	}else
	if(Color==2)
	{
		LED_B_2(Switch);
	}
}

//LED2闪烁
void LED_2_Scan(uint8_t Color)
{
	static uint8_t LED_State_2=0;

	if(LED_State_2)
	{
		LED_State_2=0;
		if(Color==0)
		{
			LED_R_2(LED_State_2);
		}else
		if(Color==1)
		{
			LED_G_2(LED_State_2);
		}else
		if(Color==2)
		{
			LED_B_2(LED_State_2);
		}
	}else
	{
		LED_State_2=1;
		if(Color==0)
		{
			LED_R_2(LED_State_2);
		}else
		if(Color==1)
		{
			LED_G_2(LED_State_2);
		}else
		if(Color==2)
		{
			LED_B_2(LED_State_2);
		}
	}

}







//LED3
//0红1绿2蓝
void LED_3(uint8_t Color,uint8_t Switch)
{
	if(Color==0)
	{
		LED_R_3(Switch);
	}else
	if(Color==1)
	{
		LED_G_3(Switch);
	}else
	if(Color==2)
	{
		LED_B_3(Switch);
	}
}

//LED3闪烁
void LED_3_Scan(uint8_t Color)
{
	static uint8_t LED_State_3=0;

	if(LED_State_3)
	{
		LED_State_3=0;
		if(Color==0)
		{
			LED_R_3(LED_State_3);
		}else
		if(Color==1)
		{
			LED_G_3(LED_State_3);
		}else
		if(Color==2)
		{
			LED_B_3(LED_State_3);
		}
	}else
	{
		LED_State_3=1;
		if(Color==0)
		{
			LED_R_3(LED_State_3);
		}else
		if(Color==1)
		{
			LED_G_3(LED_State_3);
		}else
		if(Color==2)
		{
			LED_B_3(LED_State_3);
		}
	}

}




//LED流水灯Dmeo
void LED_Dmeo()
{
	static uint8_t State=0;

	LED_1(State%3,1);
	LED_1((State+1)%3,0);
	LED_1((State+2)%3,0);

	LED_2(State%3,0);
	LED_2((State+1)%3,1);
	LED_2((State+2)%3,0);

	LED_3(State%3,0);
	LED_3((State+1)%3,0);
	LED_3((State+2)%3,1);


	++State;
}



//
////////////////////////////////////////////////////////////////
//结束定义灯部分

#endif//SimpleIO_H
