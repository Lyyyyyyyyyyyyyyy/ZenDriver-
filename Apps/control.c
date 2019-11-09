#include "control.h"

int Motor;
int Encoder;
int Target_velocity = 20;     //目标速度

void  Set_Pwm(int motor)      
{
	if (motor > 0)
		PWMA = 7200, PWMB = 7200 - motor;
	else 	              
		PWMB = 7200, PWMA = 7200 - motor;
}
