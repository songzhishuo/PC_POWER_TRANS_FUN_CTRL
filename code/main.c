#include "system.h"
#include "PCA_PWM.h"
#include "ds18b20.h"
#include "soft_pwm.h"
uint8 flag = 0;
uint16 pwm_data = 0;
uint16 tem = 0;
void main()
{
    P3M0 = 0x08; P3M1 = 0x00; 
	//inter_pwm_init();
	soft_pwm_init();
	soft_pwm_set_duty(0);
	EA =1;
	while(1)
	{
		tem = ds18b20_get();
		if(tem <= 2500)
			soft_pwm_set_duty(0);
		else if((tem > 2500) && (tem <= 3000))
			soft_pwm_set_duty(7   0);
		else if((tem > 3000) && (tem <= 4000))
			soft_pwm_set_duty(100);
		else if(tem > 4500)
			soft_pwm_set_duty(200);

		delay_ms(1*1000);
	}


}