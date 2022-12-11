#ifndef __SOFT_PWM_H__
#define __SOFT_PWM_H__

#include "system.h"


void soft_pwm_init();
void soft_pwm_set_duty(uint16 mduty);
#endif