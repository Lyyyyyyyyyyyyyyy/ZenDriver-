/*
  *******************************************************************************
  * @file    PID.c
  * @author  Luu-yy
  * @version  
  * @date    
  * @brief   PID¹¦ÄÜº¯Êý
  ******************************************************************************
  */

#include "PID.h"

void PWM_Limit(int motor)
{
	int Amplitude = 7200;
    if(motor > Amplitude)
		motor = Amplitude;
    if(motor < -Amplitude)
		motor = -Amplitude;
}

int Incremental_PI(int Encoder, int Target)
{
	pid.Kp = 150;
	pid.Ki = 40;

	pid.err = Encoder - Target;
	pid.pwm += pid.Kp*(pid.err - pid.err_last) + pid.Ki*pid.err;

	if (pid.pwm>7200)
		pid.pwm = 7200;
	else if (pid.pwm<-7200)
		pid.pwm = -7200;
	
	pid.err_last = pid.err;

	return pid.pwm;
}
