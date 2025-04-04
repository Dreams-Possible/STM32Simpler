#include"MPU6050.h"

//以下内容为自行补充整合
////////////////////////////////

//声明检测到的角度
float volatile MPU6050_Pitch=0;
float volatile MPU6050_Roll=0;
float volatile MPU6050_Yaw=0;

//声明检测到的陀螺仪值
int16_t volatile MPU6050_G_X=0;
int16_t volatile MPU6050_G_Y=0;
int16_t volatile MPU6050_G_Z=0;

//声明检测到的加速度
int16_t volatile MPU6050_A_X=0;
int16_t volatile MPU6050_A_Y=0;
int16_t volatile MPU6050_A_Z=0;

//声明检测到的温度值
float volatile MPU6050_Temperature=0;

//MPU6050状态声明（0不可用，1可用）
uint8_t volatile MPU6050_State=0;

//MPU6050数据状态声明（0不可用，1可用）
uint8_t volatile MPU6050_DataFlag=0;




//MPU6050初始化
void MPU6050_Initialization()
{
	int8_t MPU6050_DMP_State=0;
	//MPU6050初始化
	MPU_Init();

	//MPU6050的DMP库初始化
	MPU6050_DMP_State=MPU6050_DMP_Init();
	while(MPU6050_DMP_State)
	{
		HAL_Delay(10);
		MPU6050_DMP_State=MPU6050_DMP_Init();
		Error_Printf("M6IntEr%d\n",MPU6050_DMP_State);
	}

	//MPU6050状态可用
	MPU6050_State=1;
	Error_Printf("M6IntSc\n");
}



//如果是全局变量模式
#ifdef MPU6050_GlobalMode


//MPU6050读取温度值
void MPU6050_GetTemperature()
{
	if(MPU6050_DataFlag)
	{
		MPU6050_Temperature=MPU_Get_Temperature();
	}

}

//MPU6050读取陀螺仪值
void MPU6050_GetGyroscope()
{
	if(MPU6050_DataFlag)
	{
		//滤波
		static int16_t MPU6050_G_X_New=0;
		static int16_t MPU6050_G_Y_New=0;
		static int16_t MPU6050_G_Z_New=0;

		MPU_Get_Gyroscope(&MPU6050_G_X_New,&MPU6050_G_Y_New,&MPU6050_G_Z_New);

		MPU6050_G_X=0.3*MPU6050_G_X+0.7*MPU6050_G_X_New;
		MPU6050_G_Y=0.3*MPU6050_G_Y+0.7*MPU6050_G_Y_New;
		MPU6050_G_Z=0.3*MPU6050_G_Z+0.7*MPU6050_G_Z_New;
	}
}

//MPU6050读取加速度值
void MPU6050_GetAccelerometer()
{
	if(MPU6050_DataFlag)
	{
		MPU_Get_Accelerometer((int16_t *)&MPU6050_A_X,(int16_t *)&MPU6050_A_Y,(int16_t *)&MPU6050_A_Z);
	}
}

//MPU6050读取姿态角数据
void MPU6050_GetAttitudeAngle()
{
	if(MPU6050_DataFlag)
	{
		//滤波
		static float MPU6050_Pitch_New=0;
		static float MPU6050_Roll_New=0;
		static float MPU6050_Yaw_New=0;

		MPU6050_DMP_Get_Data(&MPU6050_Pitch_New,&MPU6050_Roll_New,&MPU6050_Yaw_New);


		MPU6050_Pitch=0.3*MPU6050_Pitch+0.7*MPU6050_Pitch_New;
		MPU6050_Roll=0.3*MPU6050_Roll+0.7*MPU6050_Roll_New;
		MPU6050_Yaw=0.3*MPU6050_Yaw+0.7*MPU6050_Yaw_New;
	}

}


//MPU6050数值显示
void MPU6050_Printf()
{
	Error_Printf("P=%.2f\n",MPU6050_Pitch);
	Error_Printf("R=%.2f\n",MPU6050_Roll);
	Error_Printf("Y=%.2f\n",MPU6050_Yaw);

//	Error_Printf("X=%d\n",MPU6050_G_X);
//	Error_Printf("Y=%d\n",MPU6050_G_Y);
//	Error_Printf("Z=%d\n",MPU6050_G_Z);
}


#endif//MPU6050_GlobalMode

//如果是参数传递模式
#ifdef MPU6050_ParameterMode



//MPU6050读取温度值
float MPU6050_GetTemperature()
{
	if(MPU6050_DataFlag)
	{
		return MPU_Get_Temperature();
	}

}

//MPU6050读取陀螺仪值
void MPU6050_GetGyroscope(float*MPU6050_G_X,float*MPU6050_G_Y,float*MPU6050_G_Z)
{
	if(MPU6050_DataFlag)
	{
		//滤波
		static int16_t MPU6050_G_X_New=0;
		static int16_t MPU6050_G_Y_New=0;
		static int16_t MPU6050_G_Z_New=0;

		MPU_Get_Gyroscope(&MPU6050_G_X_New,&MPU6050_G_Y_New,&MPU6050_G_Z_New);

		*MPU6050_G_X=0.3*(*MPU6050_G_X)+0.7*MPU6050_G_X_New;
		*MPU6050_G_Y=0.3*(*MPU6050_G_Y)+0.7*MPU6050_G_Y_New;
		*MPU6050_G_Z=0.3*(*MPU6050_G_Z)+0.7*MPU6050_G_Z_New;
	}
}

//MPU6050读取加速度值
void MPU6050_GetAccelerometer(int16_t*MPU6050_A_X,int16_t*&MPU6050_A_Y,int16_t*MPU6050_A_Z)
{
	if(MPU6050_DataFlag)
	{
		MPU_Get_Accelerometer(MPU6050_A_X,MPU6050_A_Y,MPU6050_A_Z);
	}
}

//MPU6050读取姿态角数据
void MPU6050_GetAttitudeAngle(float*MPU6050_Pitch,float*MPU6050_Roll,float*MPU6050_Yaw)
{
	if(MPU6050_DataFlag)
	{
		//滤波
		static float MPU6050_Pitch_New=0;
		static float MPU6050_Roll_New=0;
		static float MPU6050_Yaw_New=0;

		MPU6050_DMP_Get_Data(&MPU6050_Pitch_New,&MPU6050_Roll_New,&MPU6050_Yaw_New);


		*MPU6050_Pitch=0.3*(*MPU6050_Pitch)+0.7*MPU6050_Pitch_New;
		*MPU6050_Roll=0.3*(*MPU6050_Roll)+0.7*MPU6050_Roll_New;
		*MPU6050_Yaw=0.3*(*MPU6050_Yaw)+0.7*MPU6050_Yaw_New;
	}

}



//MPU6050姿态角数值显示
void MPU6050_Printf(float MPU6050_Pitch,float MPU6050_Roll,float MPU6050_Yaw)
{
	Error_Printf("P=%.2f\n",MPU6050_Pitch);
	Error_Printf("R=%.2f\n",MPU6050_Roll);
	Error_Printf("Y=%.2f\n",MPU6050_Yaw);


}





#endif//MPU6050_ParameterMode



//定时刷新数据
//该部分在ExternalInterrup（外部中断）中

////////////////////////////////
//以上内容为自行补充整合



//以下内容参考其他历程
////////////////////////////////


//以下是MPU6050的相关函数
////////////////////////////////////////////////////////////////


//设置MPU6050陀螺仪传感器满量程范围
//fsr:0,±250dps;1,±500dps;2,±1000dps;3,±2000dps
//返回值:0,设置成功
//    其他,设置失败
uint8_t MPU_Set_Gyro_Fsr(uint8_t fsr)
{
	return MPU6050_SendData(MPU_GYRO_CFG_REG,fsr<<3);//设置陀螺仪满量程范围
}

//设置MPU6050加速度传感器满量程范围
//fsr:0,±2g;1,±4g;2,±8g;3,±16g
//返回值:0,设置成功
//    其他,设置失败
uint8_t MPU_Set_Accel_Fsr(uint8_t fsr)
{
	return MPU6050_SendData(MPU_ACCEL_CFG_REG,fsr<<3);//设置加速度传感器满量程范围
}

//设置MPU6050的数字低通滤波器
//lpf:数字低通滤波频率(Hz)
//返回值:0,设置成功
//    其他,设置失败
uint8_t MPU_Set_LPF(uint16_t lpf)
{
	uint8_t data=0;
	if(lpf>=188)data=1;
	else if(lpf>=98)data=2;
	else if(lpf>=42)data=3;
	else if(lpf>=20)data=4;
	else if(lpf>=10)data=5;
	else data=6;
	return MPU6050_SendData(MPU_CFG_REG,data);//设置数字低通滤波器
}

//设置MPU6050的采样率(假定Fs=1KHz)
//rate:4~1000(Hz)
//返回值:0,设置成功
//    其他,设置失败
uint8_t MPU_Set_Rate(uint16_t rate)
{
	uint8_t data;
	if(rate>1000)rate=1000;
	if(rate<4)rate=4;
	data=1000/rate-1;
	data=MPU6050_SendData(MPU_SAMPLE_RATE_REG,data);//设置数字低通滤波器
 	return MPU_Set_LPF(rate/2);//自动设置LPF为采样率的一半
}

//初始化MPU6050
//返回值:0,成功
//    其他,错误代码
uint8_t MPU_Init(void)
{
	//uint8_t res;
	MPU6050_SendData(MPU_PWR_MGMT1_REG,0X80);//复位MPU6050
	HAL_Delay(100);
	MPU6050_SendData(MPU_PWR_MGMT1_REG,0X00);//唤醒MPU6050
	MPU_Set_Gyro_Fsr(3);//陀螺仪传感器,±2000dps
	MPU_Set_Accel_Fsr(0);//加速度传感器,±2g
	MPU_Set_Rate(50);//设置采样率50Hz
    //MPU6050_SendData(MPU_INT_EN_REG,0X00);//关闭所有中断
    MPU6050_SendData(MPU_INT_EN_REG, 0X01);//开启FIFO中断
    //MPU6050_SendData(MPU_USER_CTRL_REG,0X00);//I2C主模式关闭
    //MPU6050_SendData(MPU_FIFO_EN_REG,0X00);//关闭FIFO
	MPU6050_SendData(MPU_INTBP_CFG_REG,0X80);//INT引脚低电平有效
	//res=MPU6050_ReadByte(MPU_DEVICE_ID_REG);
	//if(res==MPU6050_Address)//器件ID正确
	{
		MPU6050_SendData(MPU_PWR_MGMT1_REG,0X01);//设置CLKSEL,PLL,X轴为参考
		MPU6050_SendData(MPU_PWR_MGMT2_REG,0X00);//加速度与陀螺仪都工作
		MPU_Set_Rate(50);//设置采样率为50Hz
 	}//else
		//return 1;
	return 0;
}

//得到温度值
//返回值:温度值(扩大了100倍)
float MPU_Get_Temperature(void)
{
    uint8_t buf[2];
    short raw;
	float temp;
	MPU6050_ReadData(MPU_TEMP_OUTH_REG,2,buf);
	raw=((uint16_t)buf[0]<<8)|buf[1];
	temp=36.53+((double)raw)/340;
	return temp*100;
}

//得到陀螺仪值(原始值)
//gx,gy,gz:陀螺仪x,y,z轴的原始读数(带符号)
//返回值:0,成功
//    其他,错误代码
uint8_t MPU_Get_Gyroscope(short *gx,short *gy,short *gz)
{
    uint8_t buf[6],res;
	res=MPU6050_ReadData(MPU_GYRO_XOUTH_REG,6,buf);
	if(res==0)
	{
		*gx=((uint16_t)buf[0]<<8)|buf[1];
		*gy=((uint16_t)buf[2]<<8)|buf[3];
		*gz=((uint16_t)buf[4]<<8)|buf[5];
	}
    return res;;
}

//得到加速度值(原始值)
//gx,gy,gz:陀螺仪x,y,z轴的原始读数(带符号)
//返回值:0,成功
//    其他,错误代码
uint8_t MPU_Get_Accelerometer(short *ax,short *ay,short *az)
{
    uint8_t buf[6],res;
	res=MPU6050_ReadData(MPU_ACCEL_XOUTH_REG,6,buf);
	if(res==0)
	{
		*ax=((uint16_t)buf[0]<<8)|buf[1];
		*ay=((uint16_t)buf[2]<<8)|buf[3];
		*az=((uint16_t)buf[4]<<8)|buf[5];
	}
  return res;;
}

////////////////////////////////////////////////////////////////
//以上是MPU6050的相关函数


//以下是MPU6050的DMP库相关的函数
////////////////////////////////////////////////////////////////

#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h"
#include <math.h>

#define DEFAULT_MPU_HZ  (100)
#define Q30				(1073741824.0f)
/* The sensors can be mounted onto the board in any orientation. The mounting
 * matrix seen below tells the MPL how to rotate the raw data from thei
 * driver(s).
 * TODO: The following matrices refer to the configuration on an internal test
 * board at Invensense. If needed, please modify the matrices to match the
 * chip-to-body matrix for your particular set up.
 */
static signed char gyro_orientation[9] = {-1, 0, 0,
                                           0,-1, 0,
                                           0, 0, 1};

/* These next two functions converts the orientation matrix (see
 * gyro_orientation) to a scalar representation for use by the DMP.
 * NOTE: These functions are borrowed from Invensense's MPL.
 */
static unsigned short inv_row_2_scale(const signed char *row)
{
    unsigned short b;

    if (row[0] > 0)
        b = 0;
    else if (row[0] < 0)
        b = 4;
    else if (row[1] > 0)
        b = 1;
    else if (row[1] < 0)
        b = 5;
    else if (row[2] > 0)
        b = 2;
    else if (row[2] < 0)
        b = 6;
    else
        b = 7;      // error
    return b;
}

static  unsigned short inv_orientation_matrix_to_scalar(
    const signed char *mtx)
{
    unsigned short scalar;

    /*
       XYZ  010_001_000 Identity Matrix
       XZY  001_010_000
       YXZ  010_000_001
       YZX  000_010_001
       ZXY  001_000_010
       ZYX  000_001_010
    */

    scalar = inv_row_2_scale(mtx);
    scalar |= inv_row_2_scale(mtx + 3) << 3;
    scalar |= inv_row_2_scale(mtx + 6) << 6;

    return scalar;
}

static int run_self_test(void)
{
    int result;
    long gyro[3], accel[3];

    result = mpu_run_self_test(gyro, accel);
    if (result == 0x3) {
        /* Test passed. We can trust the gyro data here, so let's push it down
         * to the DMP.
         */
        float sens;
        unsigned short accel_sens;
        mpu_get_gyro_sens(&sens);
        gyro[0] = (long)(gyro[0] * sens);
        gyro[1] = (long)(gyro[1] * sens);
        gyro[2] = (long)(gyro[2] * sens);
        dmp_set_gyro_bias(gyro);
        mpu_get_accel_sens(&accel_sens);
        accel[0] *= accel_sens;
        accel[1] *= accel_sens;
        accel[2] *= accel_sens;
        dmp_set_accel_bias(accel);
    }else
	{
		return -1;
	}
	return 0;
}

//MPU6050的DMP库初始化
int MPU6050_DMP_Init(void)
{
	int result;
	struct int_param_s int_param;
	result = mpu_init(&int_param);
	if(result != 0)
	{
		return -1;
	}
    result = mpu_set_sensors(INV_XYZ_GYRO | INV_XYZ_ACCEL);
	if(result != 0)
	{
		return -2;
	}
    result = mpu_configure_fifo(INV_XYZ_GYRO | INV_XYZ_ACCEL);
	if(result != 0)
	{
		return -3;
	}
    result = mpu_set_sample_rate(DEFAULT_MPU_HZ);
	if(result != 0)
	{
		return -4;
	}
	result = dmp_load_motion_driver_firmware();
	if(result != 0)
	{
		return -5;
	}
    result = dmp_set_orientation(
        inv_orientation_matrix_to_scalar(gyro_orientation));
	if(result != 0)
	{
		return -6;
	}
    result = dmp_enable_feature(DMP_FEATURE_6X_LP_QUAT | DMP_FEATURE_TAP |
								DMP_FEATURE_ANDROID_ORIENT | DMP_FEATURE_SEND_RAW_ACCEL |
								DMP_FEATURE_SEND_CAL_GYRO | DMP_FEATURE_GYRO_CAL);
	if(result != 0)
	{
		return -7;
	}
    result = dmp_set_fifo_rate(DEFAULT_MPU_HZ);
	if(result != 0)
	{
		return -8;
	}
	result = run_self_test();
	if(result != 0)
	{
		return -9;
	}
    result = mpu_set_dmp_state(1);
	if(result != 0)
	{
		return -10;
	}
	return 0;

}

//读取MPU6050经过DMP处理后的数据
int MPU6050_DMP_Get_Data(float *pitch, float *roll, float *yaw)
{
	float q0 = 0.0f;
	float q1 = 0.0f;
	float q2 = 0.0f;
	float q3 = 0.0f;
	short gyro[3];
	short accel[3];
	long quat[4];
    unsigned long timestamp;
	short sensors;
	unsigned char more;
	if(dmp_read_fifo(gyro, accel, quat, &timestamp, &sensors, &more))
	{
		return -1;
	}
	if(sensors & INV_WXYZ_QUAT)
	{
		q0 = quat[0] / Q30;
        q1 = quat[1] / Q30;
        q2 = quat[2] / Q30;
        q3 = quat[3] / Q30;
		
		*pitch  = asin(-2 * q1 * q3 + 2 * q0 * q2) * 57.3;
        *roll   = atan2(2 * q2 * q3 + 2 * q0 * q1, -2 * q1 * q1 - 2 * q2 * q2 + 1) * 57.3;
        *yaw    = atan2(2 * (q1 * q2 + q0 * q3), q0 * q0 + q1 * q1 - q2 * q2 - q3 * q3) * 57.3;
		
	}else
	{
		return -2;
	}
	return 0;
}

////////////////////////////////////////////////////////////////
//以上是MPU6050的DMP库相关的函数


////////////////////////////////
//以上内容参考其他历程
