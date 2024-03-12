/*
 * servo_motor.c
 *
 * Created: 26/2/2024 12:01:24 AM
 *  Author: Shawky Ramadan
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "std_macros.h"
#include "timer.h"


	void Servo_angle(char angle)
	{
		
		if(angle==0)
		{
		timer1_wave_fastPWM(1);
		}
		else if(angle==180)
		{
		timer1_wave_fastPWM(2);
		}
		else if(angle==90)
		{
			timer1_wave_fastPWM(1.5);
		}
		else
		{
			timer1_wave_fastPWM(0);
		}
	}


