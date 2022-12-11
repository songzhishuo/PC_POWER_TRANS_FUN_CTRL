#include "ds18b20.h"



u8 ds18b20_flag;



//��������ʱ����
void Delay_OneWire(unsigned int t)  
{
	unsigned char i;
	while(t--){
		for(i=0; i<8; i++);
	}
}


void Delay_us(unsigned int x)
{
//	while(x -- )
//	{
//		_nop_();
//		_nop_();
//		_nop_();
//	}

	unsigned char i;
	while(x--)
	{
		i = 6;
		while (--i);
	}
}

//ͨ����������DS18B20дһ���ֽ�
void Write_DS18B20(unsigned char dat)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		DQ = 1;
		Delay_us(4);
		DQ = 0;
		Delay_us(4);
		DQ = dat&0x01;
		Delay_us(66);
		//Delay_us(5);
		//DQ = 1;
		dat >>= 1;
	}
	DQ = 1;
	Delay_us(4);
}

//��DS18B20��ȡһ���ֽ�
unsigned char Read_DS18B20(void)
{
	unsigned char i;
	unsigned char dat;
  
	for(i=0;i<8;i++)
	{
		DQ = 1;
		Delay_us(4);
		dat >>= 1;
		DQ = 0;
		Delay_us(4);
		DQ = 1;
		Delay_us(4);
		if(DQ)
		{
			dat |= 0x80;
		}	    
		Delay_us(66);
	}
	DQ = 1;
	return dat;
}

//DS18B20�豸��ʼ��
bit init_ds18b20(void)
{
  	bit initflag = 1;
  	
	while(initflag)
	{
		while(initflag)
		{
			DQ = 1;
			Delay_us(4);
			DQ = 0;
			Delay_us(550);
			DQ = 1;
			Delay_us(66); 
			initflag = DQ; 
		}
		Delay_us(500);
		initflag = ~DQ;
	}
 DQ = 1;
  	
  
  	return initflag;
}



u16 ds18b20_get()    //��ȡ�¶�ֵ
{
	u16 temp;
	u8 LSB,MSB;
	init_ds18b20();
	Write_DS18B20(0xcc);
	Write_DS18B20(0x44);
	init_ds18b20();
	Write_DS18B20(0xcc);
	Write_DS18B20(0xbe);
	LSB = Read_DS18B20();
	MSB = Read_DS18B20();
	MSB &= 0x0f;
	temp = ((unsigned int)MSB<<8);
	temp = temp+LSB;
	temp = temp*6.25;   //�Ŵ���100��
	return temp;
}










