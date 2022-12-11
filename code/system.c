#include "system.h"
#include <intrins.h> 
void delay_ms(uint16 ms)		//@24.000MHz
{
	unsigned char i, j;

	while(ms --)
	{
		_nop_();
		i = 32;
		j = 40;
		do
		{
			while (--j);
		} while (--i);
	}
}
