#include "control.h"

int Motor;
int Encoder;
int Target_velocity = 20;

void  Set_Pwm(int motor)
{
	if (motor > 0)
		PWMA = 500, PWMB = 500 - motor;
	else 	              
		PWMB = 500, PWMA = 500 - motor;
}
