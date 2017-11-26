/*----------------------------------------------------------------------------
LAB EXERCISE - DIGITAL INPUTS AND OUTPUTS
PROGRAMMING USING MBED API
 ----------------------------------------
 In this exercise you need to use the mbed API functions to:
 
	1) Define BusIn, BusOut interfaces for inputs and outputs
	2) The RGB LED is controlled by the buttons:
			+ Button 1 - light RED
			+ Button 2 - light BLUE
			+ Button 3 - light GREEN
			+ Button 4 - light WHITE (RED, GREEN and BLUE at the same time)
			
	GOOD LUCK!
 *----------------------------------------------------------------------------*/

#include "mbed.h"
#include "pindef.h"

//Define input bus
	DigitalIn switch_1(PA_10);
	DigitalIn switch_2(PB_3);
	DigitalIn switch_3(PB_5);
	DigitalIn switch_4(PB_4);

//Define output bus for the RGB LED
	DigitalOut record(PB_10);

void delay(float time) {
	volatile int i;
	for (i = 0; i < 1000000*time; i++);
}
Serial device(UART_TX, UART_RX);
Timer t;

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(){
	int count = 0;
	bool s1, s2, s3, s4;
	s1 = false;
	s2 = false;
	s3 = false;
	s4 = false;
	t.start();
		device.printf("Sup, world?");
		t.stop();
		device.printf("Sup world took %d ms", t.read_ms());
	wait(20);
	while(1){
		record = 0;
		
		if (switch_1 == 0) { //if button 1 was pressed
			t.start();
		}
		if (switch_1 == 1) {
			t.stop();
			device.printf("t=%d", t.read_ms());
			wait(5);
		}	
	}
	while(1) {
			record = 1;
			delay(1);
			record = 0;
			delay(1);
	}
}

// *******************************ARM University Program Copyright (c) ARM Ltd 2016*************************************
