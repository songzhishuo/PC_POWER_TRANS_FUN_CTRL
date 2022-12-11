#ifndef __SYSTEM_H__
#define __SYSTEM_H__


#include <STC8G.H>

typedef unsigned int 			uint16;
typedef unsigned char 		uint8;

typedef unsigned char 		u8;
typedef unsigned int  		u16;
typedef unsigned long 		u32;

sbit FUN_PIN = P3^3 ;
sbit DQ = P3^2;    			 //单总线接口 ds18b20

void delay_ms(uint16 ms);
#endif