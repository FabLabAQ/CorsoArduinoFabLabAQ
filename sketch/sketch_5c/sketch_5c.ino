/*
	Pilotare un servocomando usando un potenziometro.
*/

#include <Servo.h>
const int servoPin = 11, pot = A0;
int pos;

Servo servo;

void setup ()
{
	servo.attach(servoPin);
	pinMode(pot, INPUT);		// non necessario in caso di analog in
}

void loop ()
{
	pos = analogRead(pot);
	pos = map(pos, 0, 1023, 0, 179);
	servo.write(pos);
}