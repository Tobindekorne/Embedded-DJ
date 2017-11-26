#include "mbed.h"
#include "pindef.h"

//Defining Note Frequencies
float C_M_Note = 0.00382;
float D_M_Note = 0.00341;
float	E_M_Note = 0.00301;
float	F_M_Note = 0.00286;
float	G_M_Note = 0.00255;
float	A_M_Note = 0.00227;
float	B_M_Note = 0.00202;
	
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

//No Real-Time PlayBack
void DEBUGdisplayNPlayNotes(float noteSave[], int count) {
	int i;
	for(i = 0; i < count; i++) {
		device.printf("\n\r");
		device.printf("%i, %f", i + 1, noteSave[i]);
		playNote(noteSave[i]);
		wait(.5);
	}
}
/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(){
	device.baud(9600);
	device.printf("Debug Log: Program Start");
	
	bool s1, s2, s3, s4, s5, s6, s7, s8 = false;
	
	int noteMarker = 0;
	float noteSave[100] = {0};
	
	while(1 && noteMarker != 10) {
		device.printf("%i ", noteMarker);
		if (switch_1 == 0) {//If button 1 was pressed
			if(!s1){
				noteSave[noteMarker] = C_M_Note;
				noteMarker++;
				s1 = true;
			}
			//Play Middle C
			playNote(C_M_Note);
			device.printf("%f ", C_M_Note);
		}
		if (switch_1 == 1) {
			shutUP();
			s1 = false;
		}
		if (switch_2 == 0) {
			if(!s2){
				noteSave[noteMarker] = D_M_Note;
				noteMarker++;
				s2 = true;
			}
			//Play Middle D
			playNote(D_M_Note);
			device.printf("%f ", D_M_Note);
		}
		if (switch_2 == 1) {
			shutUP();
			s2 = false;
		}
		if (switch_3 == 0) {
			if(!s3){
				noteSave[noteMarker] = E_M_Note;
				noteMarker++;
				s3 = true;
			}
			//Play Middle E
			playNote(E_M_Note);
			device.printf("%f ", E_M_Note);
		}
		if (switch_3 == 1) {
			shutUP();
			s3 = false;
		}
		if (switch_4 == 0) {
			if(!s4) {
				noteSave[noteMarker] = F_M_Note;
				noteMarker++;
				s4 = true;
			}
			//Play Middle F
			playNote(F_M_Note);
			device.printf("%f ", F_M_Note);
		}
		if (switch_4 == 1) {
			shutUP();
			s4 = false;
		}
		if (switch_5 == 0) {
			if(!s5){
				noteSave[noteMarker] = G_M_Note;
				noteMarker++;
				s5 = true;
			}
			//Play Middle G
			playNote(G_M_Note);
			device.printf("%f ", G_M_Note);
		}
		if (switch_5 == 1) {
			shutUP();
			s5 = false;
		}
		if (switch_6 == 0) {
			if(!s6){
				noteSave[noteMarker] = A_M_Note;
				noteMarker++;
				s6 = true;
			}
			//Play Middle A
			playNote(A_M_Note);
			device.printf("%f ", A_M_Note);
		}
		if (switch_6 == 1) {
			shutUP();
			s6 = false;
		}
		if (switch_7 == 0) {
			if(!s7){
				noteSave[noteMarker] = B_M_Note;
				noteMarker++;
				s7 = true;
			}
			//Play Middle B
			playNote(B_M_Note);
			device.printf("%f ", B_M_Note);
		}
		if (switch_7 == 1) {
			shutUP();
			s7 = false;
		}
	}
	DEBUGdisplayNPlayNotes(noteSave, noteMarker);
}

// *******************************CSUSM Copyright (c) Tobin and Teddy 2017*************************************
