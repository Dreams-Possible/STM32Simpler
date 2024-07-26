#include"Infrared.h"
#ifdef Infrared_H

uint8_t Infrared_S1=0;
uint8_t Infrared_S2=0;
uint8_t Infrared_S3=0;
uint8_t Infrared_S4=0;

uint8_t Infrared_S1_Backup=0;
uint8_t Infrared_S2_Backup=0;
uint8_t Infrared_S3_Backup=0;
uint8_t Infrared_S4_Backup=0;

uint8_t Infrared_S1_Test=0;
uint8_t Infrared_S2_Test=0;
uint8_t Infrared_S3_Test=0;
uint8_t Infrared_S4_Test=0;


//红外检测
void Infrared_Detection()
{
    //OLED_Printf("here\n");
    Infrared_S1=Infrared_S1_In;
    Infrared_S2=Infrared_S2_In;
    Infrared_S3=Infrared_S3_In;
    Infrared_S4=Infrared_S4_In;
    //JDY31_Send("红外检测完毕\n");
}

/*
//红外检测
void Infrared_Detection()
{

    Infrared_S1_Test=Infrared_S1_Read;
    Infrared_S2_Test=Infrared_S2_Read;
    Infrared_S3_Test=Infrared_S3_Read;
    Infrared_S4_Test=Infrared_S4_Read;



    if(0.7*Infrared_S1_Backup+0.3*Infrared_S1_Test>0.5)
    {
    	Infrared_S1=1;
    }else
    {
    	Infrared_S1=0;
    }
    if(0.7*Infrared_S2_Backup+0.3*Infrared_S2_Test>0.5)
    {
    	Infrared_S1=1;
    }else
    {
    	Infrared_S1=0;
    }
    if(0.7*Infrared_S3_Backup+0.3*Infrared_S3_Test>0.5)
    {
    	Infrared_S1=1;
    }else
    {
    	Infrared_S1=0;
    }
    if(0.7*Infrared_S4_Backup+0.3*Infrared_S4_Test>0.5)
    {
    	Infrared_S1=1;
    }else
    {
    	Infrared_S1=0;
    }

    Infrared_S1_Backup=Infrared_S1_Test;
    Infrared_S2_Backup=Infrared_S2_Test;
    Infrared_S3_Backup=Infrared_S3_Test;
    Infrared_S4_Backup=Infrared_S4_Test;

}*/

#endif//Infrared_H
