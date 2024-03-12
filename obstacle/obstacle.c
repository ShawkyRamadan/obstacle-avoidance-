/*
 * obstacle.c
 *
  * Created: 26/2/2019 12:01:24 AM
  *  Author: Shawky Ramadan
 */ 


#include <avr/io.h>
#include "DIO.h"
#include "servo motor.h"
#include "LCD.h"
#include "DC Motor with L293D.h"
#include "ultrasonic sensor.h"
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)

{
	vintultra();
	 DC_MOTOR_vInit();
	  LCD_vInit();
	   
	  char dis_right,dis_left;
	  short dis;
	
    while(1)
    {
		dis=ultraread();
	
       if(dis >40)
       {
			LCD_clearscreen();
	       motor_move_forward();
		   LCD_vSend_string("forward");
       }
	   else if (dis<40)
	   {
		  
		   motor_stop();
		   
		   Servo_angle(0);
		   _delay_ms(1000);
		   dis_right=ultraread();
		   _delay_ms(300);
		   Servo_angle(180);
		   _delay_ms(1000);
		   dis_left=ultraread();
		   _delay_ms(300);
		   Servo_angle(90); 
		  
		   if(dis_right>dis_left)
		   {	
			   LCD_clearscreen();
			  
			  LCD_vSend_string("right");
			  motor_move_right();
			  _delay_ms(300);
		   }
		   else if(dis_right<dis_left)
		   {
			   LCD_clearscreen();
			   
			   LCD_vSend_string("left");
			   motor_move_left();
			   _delay_ms(300);
		   }
		   else
		   {
			 LCD_clearscreen();
			 LCD_vSend_string("backward");
			 motor_move_backward();
			 _delay_ms(300);  
			   
			   
		   }
		  
		}
	}
}	