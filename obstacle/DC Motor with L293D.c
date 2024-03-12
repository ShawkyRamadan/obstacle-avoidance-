/*
 * DC_Motor_with_L293D.c
 *
 * Created: 26/2/2024 12:01:24 AM
 *  Author: Shawky Ramadan
 */ 


#include <avr/io.h>
#include "DIO.h"
#include "DC Motor with L293D.h"
#include "std_macros.h"


	void DC_MOTOR_vInit(void)
	{
		
	
	 DIO_vsetPINDir('D',0,1);
	 DIO_vsetPINDir('D',1,1);
	 DIO_vsetPINDir('D',2,1);
	 DIO_vsetPINDir('D',3,1);
	 DIO_vsetPINDir('A',3,1);
	 DIO_vsetPINDir('A',0,1);	
	SET_BIT(PORTD,2);
	SET_BIT(PORTD,3);
	 DIO_vsetPINDir('C',0,1);
	 DIO_vsetPINDir('C',1,1);
	 DIO_vsetPINDir('C',2,1);
	 DIO_vsetPINDir('C',3,1);
	 DIO_vsetPINDir('A',1,1);
	 DIO_vsetPINDir('A',2,1);
	SET_BIT(PORTC,2);
	SET_BIT(PORTC,3);
	}
	void motor_move_forward()
	{
	SET_BIT(PORTD,0);
	SET_BIT(PORTA,1);
	SET_BIT(PORTC,0);
	SET_BIT(PORTA,3);
	CLR_BIT(PORTD,1);
	CLR_BIT(PORTA,0);
	CLR_BIT(PORTC,1);
	CLR_BIT(PORTA,2);	
	}
		
	void motor_stop()
	{
		CLR_BIT(PORTD,0);
		CLR_BIT(PORTA,1);
		CLR_BIT(PORTC,0);
		CLR_BIT(PORTA,3);
		CLR_BIT(PORTD,1);
		CLR_BIT(PORTA,0);
		CLR_BIT(PORTC,1);
		CLR_BIT(PORTA,2);
			
	}
	void motor_move_left()
	{
		
		SET_BIT(PORTA,3);
		SET_BIT(PORTD,0);
		
	}
	void motor_move_right()
	{
		
		SET_BIT(PORTC,0);
		SET_BIT(PORTA,1);
		
	}	
   void motor_move_backward()
   {
	   SET_BIT(PORTD,1);
	   SET_BIT(PORTA,0);
	   SET_BIT(PORTC,1);
	   SET_BIT(PORTA,2);
   }
