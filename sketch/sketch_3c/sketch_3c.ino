/*
	Variare l'intensità luminosa di un LED a intervalli di tempo.
*/

const int led = 3, ledSpeed = 5;
void setup ()
{
	pinMode(led, OUTPUT);	// impostiamo come out
}

void loop ()
{
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