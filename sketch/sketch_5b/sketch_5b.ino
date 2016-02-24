/*
	Pilotare un servocomando autonomamente usando millis.
*/

#include <Servo.h>
const int servoPin = 11, servoSpeed = 10;
int pos = 0;
unsigned long prevMillis;
bool increase = true;
Servo servo;

void setup ()
{
	servo.attach(servoPin);
}

void loop ()
{
	if (millis() > prevMillis + servoSpeed)
	{
		if (increase || pos == 0)
		{
			pos++;
			increase = true;
		}
		if (!increase || pos == 180)
		{
			pos--;
			increase = false;
		}
		servo.write(pos);
		prevMillis = millis();
	}
}