#include "soft_pwm.h"
 uint16  time_tick = 0;//����ռ�ձȵı���
 uint16	duty = 0;
void soft_pwm_init()			//100us   * 200 = 20ms (50hz)
{
//	AUXR |= 0x80;		//��ʱ��ʱ��1Tģʽ
//	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
//	TL0 = 0xA0;		//���ö�ʱ��ʼֵ
//	TH0 = 0xF6;		//���ö�ʱ��ʼֵ
//	TF0 = 0;		//���TF0��־
//	TR0 = 1;		//��ʱ��0��ʼ��ʱ
//	EA = 1;       //�������ж�

	AUXR |= 0x80;
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TL0 = 0xA0;                                 //65536-11.0592M/12/1000
	TH0 = 0xF6;
	TR0 = 1;                                    //������ʱ��
	ET0 = 1;                                    //ʹ�ܶ�ʱ���ж�
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

	if(time_tick<=duty)   //ռ�ձ�%50,�ɸ�
		FUN_PIN=1;
	else
		FUN_PIN=0;


}