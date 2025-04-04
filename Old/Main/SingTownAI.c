#include"SingTownAI.h"
#ifdef SingTownAI_H

//以下内容修改自星瞳官方文档
////////////////////////////////////////////////////////////////
struct DetectObj objs[OBJECT_MAX];

// used for printf in itm
int _write(int file, char *ptr, int len) {
	int i = 0;
	for (i = 0; i < len; i++)
		ITM_SendChar((*ptr++));
	return len;
}

int readByte() {
	unsigned char byte;
	int timeout = 2;
	if (HAL_UART_Receive(&USART_SingTownAI, &byte, 1, timeout) != HAL_OK)
		return -1;
	return byte;
}

int check_crc(unsigned char *payload) {
	unsigned char num = payload[0];
	unsigned char crc = 0;
	int i = 0, j = 0;
	for (i = 0; i < num * OBJECT_SIZE + 2; i++) {
		crc ^= payload[i];
		for (j = 0; j < 8; j++) {
			if (crc & 1)
				crc ^= 0x91;
			crc >>= 1;
		}
	}
	return crc;
}

int read_singtownaicam_objs() {
	int i;
	unsigned char num;
	unsigned char payload[OBJECT_MAX * OBJECT_SIZE + 2];
	unsigned char *obj_ptr;
	int byte;
	while (1) {
		if (readByte() != 0xeb)
			continue;
		if (readByte() != 0x90)
			continue;

		num = readByte();
		if (num < 0 || num > OBJECT_MAX)
			continue;
		payload[0] = num;

		for (i = 1; i < num * OBJECT_SIZE + 2; i++) {
			byte = readByte();
			if (byte == -1)
				break;
			payload[i] = byte;
		}

		if (check_crc(payload) != 0)
			continue;
		for (i = 0; i < num; i++) {
			obj_ptr = payload + i * OBJECT_SIZE + 1;
			objs[i].score = obj_ptr[0];
			objs[i].idx = obj_ptr[1];
			objs[i].x1 = obj_ptr[2] | (obj_ptr[3] << 8);
			objs[i].y1 = obj_ptr[4] | (obj_ptr[5] << 8);
			objs[i].x2 = obj_ptr[6] | (obj_ptr[7] << 8);
			objs[i].y2 = obj_ptr[8] | (obj_ptr[9] << 8);
		}
		return num;
	}
}

////////////////////////////////////////////////////////////////


//调用示例
//int main(void) {
//
//	int num;
//	int i;
//	while (1)
//	{
//		num = read_singtownaicam_objs();
//		printf("Found Object Number: %d\n", num);
//
//		for (i = 0; i < num; i++)
//		{
//			printf("\t%d\t%d\t[%d,\t%d,\t%d\t%d]\n", objs[i].score, objs[i].idx,
//					objs[i].x1, objs[i].y1, objs[i].x2, objs[i].y2);
//		}
//
//	}
//
//}





#endif//SingTownAI_H
