/*
	Accendere una serie di LED secondo la posizione di un potenziometro.
	Versione con array.
*/

const int ledNum = 6, leds[ledNum] = { 2, 3, 4, 5, 6, 7 }, pot = A0, ledVal = 1024 / ledNum;

void setup ()
{
	for(int i=0; i<ledNum; i++)
	{
		pinMode(leds[i], OUTPUT);
	}
	pinMode(pot, INPUT);	// impostiamo come input
}

void loop ()
{
	int val = analogRead(pot);

	for(int i=0; i<ledNum; i++)
	{
		if (val > ledVal * (i+1))
		{
			digitalWrite(leds[i], HIGH);
		}
		else
		{
			digitalWrite(leds[i], LOW);
		}
	}
}