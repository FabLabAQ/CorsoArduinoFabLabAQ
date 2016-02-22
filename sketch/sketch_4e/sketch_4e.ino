/*
	Comandare un LED dal terminale seriale.
 */

const int led = 2;
char input;

void setup ()
{
	Serial.begin(9600);		// inizializza a velocità 9600
	pinMode(led, OUTPUT);	// impostiamo come out
}

void loop ()
{
	if (Serial.available())
	{
		input = Serial.read();
	}

	if (input == '1')
	{
		digitalWrite(led, HIGH);
	}
	else
	{
		digitalWrite(led, LOW);
	}
}