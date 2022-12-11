#include "soft_pwm.h"
 uint16  time_tick = 0;//定义占空比的变量
 uint16	duty = 0;
void soft_pwm_init()			//100us   * 200 = 20ms (50hz)
{
//	AUXR |= 0x80;		//定时器时钟1T模式
//	TMOD &= 0xF0;		//设置定时器模式
//	TL0 = 0xA0;		//设置定时初始值
//	TH0 = 0xF6;		//设置定时初始值
//	TF0 = 0;		//清除TF0标志
//	TR0 = 1;		//定时器0开始计时
//	EA = 1;       //开启总中断

	AUXR |= 0x80;
	TMOD &= 0xF0;		//设置定时器模式
	TL0 = 0xA0;                                 //65536-11.0592M/12/1000
	TH0 = 0xF6;
	TR0 = 1;                                    //启动定时器
	ET0 = 1;                                    //使能定时器中断
	EA = 1;

	time_tick = 0;
}


void soft_pwm_set_duty(uint16 mduty)
{
	duty = mduty;
}

void Time0_ISR(void) interrupt 1
{
	time_tick++;

	if(time_tick>=200)
			time_tick=0;

	if(time_tick<=duty)   //占空比%50,可改
		FUN_PIN=1;
	else
		FUN_PIN=0;


}