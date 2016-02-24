/*
	Pilotare un servocomando usando i pulsanti con incrementi a ogni pressione.
*/

#include <Servo.h>
const int servoPin = 11, buttonPlus = 3, buttonMinus = 2;
int pos = 90;
bool pressed;

Servo servo;

void setup ()
{
	servo.attach(servoPin);
	pinMode(buttonMinus, INPUT_PULLUP);
	pinMode(buttonPlus, INPUT_PULLUP);
}

void loop ()
{
	if (!digitalRead(buttonPlus) && !pressed)
	{
		pos += 9;
		if (pos > 180)
		{
			pos = 180;
		}
		delay(10);
		pressed = true;
	}
	else if (digitalRead(buttonPlus))
	{
		pressed = false;
	}

	if (!digitalRead(buttonMinus) && !pressed)
	{
		pos -= 9;
		if (pos < 0)
		{
			pos = 0;
		}
		delay(10);
		pressed = true;
	}
	else if (digitalRead(buttonMinus))
	{
		pressed = false;
	}

	servo.write(pos);
}