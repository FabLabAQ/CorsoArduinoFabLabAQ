/*
	Pilotare un servocomando usando i pulsanti con incrementi a ogni pressione.
*/

#include <Servo.h>
const int servoPin = 11, buttonPlus = 3, buttonMinus = 2;
int pos = 90;
bool pressedPlus, pressedMinus;

Servo servo;

void setup ()
{
	servo.attach(servoPin);
	pinMode(buttonMinus, INPUT_PULLUP);
	pinMode(buttonPlus, INPUT_PULLUP);
}

void loop ()
{
	if (!digitalRead(buttonPlus) && !pressedPlus)
	{
		pos += 9;
		if (pos > 180)
		{
			pos = 180;
		}
		delay(10);
		pressedPlus = true;
	}
	else if (digitalRead(buttonPlus))
	{
		pressedPlus = false;
	}

	if (!digitalRead(buttonMinus) && !pressedMinus)
	{
		pos -= 9;
		if (pos < 0)
		{
			pos = 0;
		}
		delay(10);
		pressedMinus = true;
	}
	else if (digitalRead(buttonMinus))
	{
		pressedMinus = false;
	}

	servo.write(pos);
}