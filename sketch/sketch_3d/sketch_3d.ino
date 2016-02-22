/*
	Accendere una serie di LED secondo la posizione di un potenziometro.
	Versione con array.
*/

const int ledNum = 6, leds[ledNum] = { 3, 5, 6, 9, 10, 11 }, ledSpeed = 5;

void setup ()
{
	for(int i=0; i<ledNum; i++)
	{
		pinMode(leds[i], OUTPUT);
	}
}

void loop ()
{
	for(int i=0; i<ledNum; i++)
	{
		for(int j=0; j<255; j++)
		{
			analogWrite(leds[i], j);
			delay(ledSpeed);
		}
	}

	for(int i=ledNum -1; i>0; i--)
	{
		for(int j=255; j>0; j--)
		{
			analogWrite(leds[i], j);
			delay(ledSpeed);
		}
	}
}