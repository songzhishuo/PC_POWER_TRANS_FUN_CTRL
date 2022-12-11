#ifndef __DS18B20_H__
#define __DS18B20_H__

#include "system.h"

void Delay_OneWire(unsigned int t);     
void Write_DS18B20(unsigned char dat);    
unsigned char Read_DS18B20(void);   
bit init_ds18b20(void);
u16 ds18b20_get(void);    //获取温度值
#endif