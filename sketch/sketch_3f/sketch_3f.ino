/*
	Regolare la velocità di variazione di luminosità di un LED con un potenziometro.
*/

const int led = 3, pot = A0;
void setup ()
{
	pinMode(led, OUTPUT);	// impostiamo come out
	pinMode(pot, INPUT);
}

void loop ()
{
	int ledSpeed = analogRead(pot) / 100;
	
	for(int i=0; i<255; i++)
	{
		analogWrite(led, i);
		delay(ledSpeed);
	}

	for(int i=255; i>0; i--)
	{
		analogWrite(led, i);
		delay(ledSpeed);
	}
}