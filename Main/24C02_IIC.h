#if 0
#ifndef A24C02_IIC_H
#define A24C02_IIC_H
#include"SimpleMain.h"
#if defined(IIC_Software)||defined(IIC_Hardware)



//重定义设备地址
#define A24C02_Address 0xa0

//24C02写数据
int8_t A24C02_WriteData(uint8_t RegisterAddress,uint8_t DataLength,uint8_t *Data);

//24C02读数据
int8_t A24C02_ReadData(uint8_t RegisterAddress,uint8_t DataLength,uint8_t *Data);



#endif//defined(IIC_Software)||defined(IIC_Hardware)
#endif//A24C02_IIC_H
#endif//0


