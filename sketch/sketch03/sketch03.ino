/*
	Versione avanzata del classico blink,
	ricordate Kitt?
*/

const int ledMin = 2, ledMax = 7, LEDspeed = 100;

void setup()
{
	// impostiamo come output i pin
	for(int i=ledMin; i<=ledMax; i++)
	{
		pinMode(i, OUTPUT);
	}
}

void loop()
{
	// accendiamo i LED
	for(int i=ledMin; i<=ledMax; i++)
	{
		digitalWrite(i, HIGH);
		digitalWrite(i-1, LOW);
		delay(LEDspeed);
	}
	// spegniamo i LED
	for(int i=ledMax; i>=ledMin; i--)
	{
		digitalWrite(i, HIGH);
		digitalWrite(i+1, LOW);
		delay(LEDspeed);
	}
}