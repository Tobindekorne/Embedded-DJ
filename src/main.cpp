#include "mbed.h"
#include "pindef.h"

//Define input bus
	DigitalIn switch_1(PA_10);
	DigitalIn switch_2(PB_3);
	DigitalIn switch_3(PB_5);
	DigitalIn switch_4(PB_4);
	DigitalIn switch_5(PA_5);
	DigitalIn	switch_6(PA_6);
	DigitalIn switch_7(PA_7);
//Define output bus for the RGB LED
	DigitalOut record(PB_10);

// Serial tx, rx connected to the PC via an USB cable
Serial device(UART_TX, UART_RX);

/*
Define the PWM speaker output
Define analog inputs
*/
	PwmOut speaker(D6); //define the PWM output

void delay(float time) {
	volatile int i;
	for (i = 0; i < 1000000*time; i++);
}

Timer t;

void shutUP(){
	speaker = 0;
}

void playNote(float freq){
	speaker = 0.7;
	speaker.period(freq);
	wait(0.1);
}
		

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(){
	device.baud(9600);
	device.printf("Debug Log: Program Start");
	
	bool s1, s2, s3, s4, s5, s6, s7, s8 = false;
	
	int noteMarker = 0;
	
	while(1) {
		device.printf("%i ", noteMarker);
		if (switch_1 == 0) {//If button 1 was pressed
			//Play Middle C
			if(!s1){
				noteMarker++;
				s1 = true;
			}
			playNote(.00382);
		}
		if (switch_1 == 1) {
			shutUP();
			s1 = false;
		}
		if (switch_2 == 0) {
			//Play Middle D
			playNote(.00341);
		}
		if (switch_2 == 1) {
			shutUP();
		}
		if (switch_3 == 0) {
			//Play Middle E
			playNote(.00303);
		}
		if (switch_3 == 1) {
			shutUP();
		}
		if (switch_4 == 0) {
			//Play Middle F
			playNote(.00286);
		}
		if (switch_4 == 1) {
			shutUP();
		}
		if (switch_5 == 0) {
			//Play Middle G
			playNote(.00255);
		}
		if (switch_5 == 1) {
			shutUP();
		}
		if (switch_6 == 0) {
			//Play Middle A
			playNote(.00227);
		}
		if (switch_6 == 1) {
			shutUP();
		}
		if (switch_7 == 0) {
			//Play Middle B
			playNote(.00202);
		}
		if (switch_7 == 1) {
			shutUP();
		}
	}
}

// *******************************CSUSM Copyright (c) Tobin and Teddy 2017*************************************
