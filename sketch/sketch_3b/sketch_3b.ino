/*
	Accendere una serie di LED secondo la posizione di un potenziometro.
	I LED sono connessi tra ledMin e ledMax compresi.
	Versione senza array.
*/

const int ledMin = 2, ledMax = 7, pot = A0, ledVal = 1024 / (ledMax - ledMin +1);

void setup ()
{
	for(int i=ledMin; i<=ledMax; i++)
	{
		pinMode(i, OUTPUT);
	}
	pinMode(pot, INPUT);	// impostiamo come input
}

void loop ()
{
	int val = ledMin + analogRead(pot) / ledVal;

	for(int i=ledMin; i<val; i++)
	{
		digitalWrite(i, HIGH);
	}

	for(int i=ledMax; i>=val; i--)
	{
		digitalWrite(i, LOW);
	}
}