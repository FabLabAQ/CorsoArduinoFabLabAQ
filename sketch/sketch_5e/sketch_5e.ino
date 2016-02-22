/*
	CPilotare un servocomando con la comunicazione seriale.
	I comandi da inviare sono del tipo: "S 180"
*/

#include <Servo.h>
const int servoPin = 11;
Servo servo;

void setup ()
{
	Serial.begin(9600);		// inizializza a velocità 9600
	servo.attach(servoPin);
}

void loop ()
{
	if (Serial.read() == 'S')
	{
		int value = Serial.parseInt();
		servo.write(value);
	}
}