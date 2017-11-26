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
	DigitalIn Rec_Switch(PB_6);
//Define output bus for the RGB LED
	DigitalOut recordON_Red(PA_2);
	DigitalOut recordOFF_Green(PA_3);
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

void shutUP(int &index){
	speaker = 0;
	index++;
}

void playNote(float freq, bool playingBack){
	speaker = 0.7;
	speaker.period(freq);
	if(!playingBack) {
		wait(0.1);
	}
}
		
void playBack(float noteSave[], float noteTime[], int marker) {
	device.baud(9600);
	int count;
	for(count = 0; count < marker; count++) {
		playNote(noteSave[count], true);
		wait(noteTime[count]);
	}
}
	

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(){
		float noteSave[100] = {0};
		float noteTime[100] = {0.1};
		int noteMarker = 0;
		
		bool recording = false;
	
	while(1) {
		recordON_Red = 0;
		recordOFF_Green = 0;
		if(!recording) {
			recordON_Red = 0;
			recordOFF_Green = 0;
			delay(1);
			wait(1);
		}
		if (switch_1 == 0) {//If button 1 was pressed
			//Play Middle C
			playNote(.00382, false);
			noteSave[noteMarker] = .00382;
		}
		if (switch_1 == 1) {
			shutUP(noteMarker);
		}
		if (switch_2 == 0) {
			//Play Middle D
			playNote(.00341, false);
			noteSave[noteMarker] = .00341;
		}
		if (switch_2 == 1) {
			shutUP(noteMarker);
		}
		if (switch_3 == 0) {
			//Play Middle E
			playNote(.00303, false);
			noteSave[noteMarker] = .00303;
		}
		if (switch_3 == 1) {
			shutUP(noteMarker);
		}
		if (switch_4 == 0) {
			//Play Middle F
			playNote(.00286, false);
			noteSave[noteMarker] = .00286;
		}
		if (switch_4 == 1) {
			shutUP(noteMarker);
		}
		if (switch_5 == 0) {
			//Play Middle G
			playNote(.00255, false);
			noteSave[noteMarker] = .00255;
		}
		if (switch_5 == 1) {
			shutUP(noteMarker);
		}
		if (switch_6 == 0) {
			//Play Middle A
			playNote(.00227, false);
			noteSave[noteMarker] = .00227;
		}
		if (switch_6 == 1) {
			shutUP(noteMarker);
		}
		if (switch_7 == 0) {
			//Play Middle B
			playNote(.00202, false);
			noteSave[noteMarker] = .00202;
		}
		if (switch_7 == 1) {
			shutUP(noteMarker);
		}
	}
	playBack(noteSave, noteTime, noteMarker);
}

// *******************************CSUSM Copyright (c) Tobin and Teddy 2017*************************************
