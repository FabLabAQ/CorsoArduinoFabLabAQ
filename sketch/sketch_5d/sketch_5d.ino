/*
	Pilotare un servocomando usando i pulsanti con scorrimento continuo.
*/

#include <Servo.h>
const int servoPin = 11, buttonPlus = 3, buttonMinus = 2;
int pos = 90;

Servo servo;

void setup ()
{
	servo.attach(servoPin);
	pinMode(buttonMinus, INPUT_PULLUP);
	pinMode(buttonPlus, INPUT_PULLUP);
}

void loop ()
{
	if (!digitalRead(buttonPlus))
	{
		pos++;
		if (pos > 180)
		{
			pos = 180;
		}
		delay(10);
	}
	if (!digitalRead(buttonMinus))
	{
		pos--;
		if (pos < 0)
		{
			pos = 0;
		}
		delay(10);
	}
	servo.write(pos);
}