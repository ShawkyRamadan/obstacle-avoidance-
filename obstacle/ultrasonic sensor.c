/*
 * ultrasonic sensor.c
 *
 * Created: 26/2/2024 12:01:24 AM
 *  Author: Shawky Ramadan
 */ 

#include <avr/io.h>

#define  F_CPU 8000000UL
#include <util/delay.h>
	
	
	unsigned short a,b,high,distance;
	void vintultra(void)
	{
		DIO_vsetPINDir('D',7,1);//init ultra
		DIO_vsetPINDir('D',6,0);
	}
	
	unsigned short ultraread(void)
    
    {	
		TCCR1A = 0;
		TIFR = (1<<ICF1);  	/* Clear ICF (Input Capture flag)  */
		DIO_write('D',7,1);
		_delay_us(50);
		DIO_write('D',7,0);
	
	    TCCR1B = 0xc1;  	/* Rising edge, no prescaler , noise canceler*/
	    while ((TIFR&(1<<ICF1)) == 0);
	    a = ICR1;  		/* Take value of capture register */
	    TIFR = (1<<ICF1);  	/* Clear ICF flag */
	    TCCR1B = 0x81;  	/* Falling edge, no prescaler ,noise canceler*/
	    while ((TIFR&(1<<ICF1)) == 0);
	    b = ICR1;  		/* Take value of capture register */
	    TIFR = (1<<ICF1);  	/* Clear ICF flag */
		TCNT1=0;
	    TCCR1B = 0;  		/* Stop the timer */
		high=b-a;
		distance=((high*34600)/(F_CPU*2)) ;
		return distance;
	}		
		

