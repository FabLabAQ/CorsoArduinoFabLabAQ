/*
	Pilotare un servocomando autonomamente usando delay.
*/

#include <Servo.h>
const int servoPin = 11, servoSpeed = 10;
Servo servo;

void setup ()
{
	servo.attach(servoPin);
}

void loop ()
{
	for(int i=0; i<180; i++)
	{
		servo.write(i);
		delay(servoSpeed);
	}

	for(int i=180; i>0; i--)
	{
		servo.write(i);
		delay(servoSpeed);
	}
}