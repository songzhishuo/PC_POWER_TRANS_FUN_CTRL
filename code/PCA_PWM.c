
#include "PCA_PWM.h"
void inter_pwm_init()
{
	P_SW1 = 0x30;                               //ECI_4/P3.5, CCP0_4/P3.3, CCP1_4/P3.2, CCP2_4/P3.1,CCP3_4/P3.0
	
	CCON = 0x00;
	CMOD = 0xFF;                                //PCAʱ��Ϊϵͳʱ��
	CL = 0x00;
	CH = 0x00;
	
	
	CCAPM0 = 0x42;                              //PCAģ��0ΪPWM����ģʽ
	PCA_PWM0 = 0xc0;                            //PCAģ��1���10λPWM
	CCAP0L = 0x00;
	CCAP0H = 0x00;
	
	CR = 1;                                     //����PCA��ʱ��
}


void inter_pwm_ctrl(uint16 setPWM)
{
    PCA_PWM0=0x30&(setPWM>>4)|0xc0;//����λXCCAPnH[1:0]
    CCAP0H = setPWM;//��8λCCAPnH[7:0]

}