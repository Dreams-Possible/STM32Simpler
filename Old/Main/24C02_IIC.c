#include"24C02_IIC.h"
#ifdef A24C02_IIC_H

#if defined(IIC_Software)||defined(IIC_Hardware)



//24C02写数据
int8_t A24C02_WriteData(uint8_t RegisterAddress,uint8_t DataLength,uint8_t *Data)
{
	return IIC_WriteData(A24C02_Address,RegisterAddress,DataLength,Data);
}

//24C02读数据
int8_t A24C02_ReadData(uint8_t RegisterAddress,uint8_t DataLength,uint8_t *Data)
{
	return IIC_ReadData(A24C02_Address,RegisterAddress,DataLength,Data);
}



#endif//defined(IIC_Software)||defined(IIC_Hardware)
#endif//A24C02_IIC_H
