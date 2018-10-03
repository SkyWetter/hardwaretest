// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
	Name:       stepper test.ino
	Created:	2018-10-01 5:06:45 PM
	Author:     DESKTOP-1I0B636\bubsington
*/

// Define User Types below here or use a .h file
//


// Define Function Prototypes that use User Types below here or use a .h file
//


// Define Functions below here or use other .ino or cpp files
// 


// The setup() function runs once each time the micro-controller starts
#include <MultiStepper.h>
#include <AccelStepper.h>
#include <Stepper.h>
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper domeStepper(400, 19, 18, 5, 17);
Stepper h20Stepper(400, 23, 22, 1, 3);

int h20hall = 0;
int domehall = 4;
int btn = 2;
int flow = 15;

int cw = 34;
int ccw = 35;
int open = 32;
int close = 33;

void setup() {

	domeStepper.setSpeed(20);
	h20Stepper.setSpeed(20);

	pinMode(h20hall, INPUT);
	pinMode(domehall, INPUT);
	pinMode(btn, INPUT);
	pinMode(flow, INPUT);

	pinMode(cw, INPUT);
	pinMode(ccw, INPUT);
	pinMode(open, INPUT);
	pinMode(close, INPUT);
	pinMode(14, OUTPUT);
	;
}

void loop() {



	Stepper domeStepper(400, 19, 18, 5, 17);
	domeStepper.step(1);


	// step one revolution  in one direction:
	//Serial.println("clockwise");

	while (digitalRead(cw) == HIGH) {
		domeStepper.step(10);
		delay(1);

	}
	while (digitalRead(ccw) == HIGH) {
		domeStepper.step(-10);
		delay(1);
	}
	while (digitalRead(open) == HIGH) {
		h20Stepper.step(10);
		delay(1);
	}

	while (digitalRead(close) == HIGH) {
		h20Stepper.step(-10);
		delay(1);
	}

	//off();

	//delay(50);


}
void lock(void) {
	digitalWrite(19, LOW);
	digitalWrite(18, HIGH);
	digitalWrite(5, LOW);
	digitalWrite(17, LOW);

	digitalWrite(22, LOW);
	digitalWrite(23, HIGH);
	digitalWrite(1, LOW);
	digitalWrite(3, LOW);
}

void off(void) {

	digitalWrite(19, LOW);
	digitalWrite(18, LOW);
	digitalWrite(5, LOW);
	digitalWrite(17, LOW);

	digitalWrite(22, LOW);
	digitalWrite(23, LOW);
	digitalWrite(1, LOW);
	digitalWrite(3, LOW);
}