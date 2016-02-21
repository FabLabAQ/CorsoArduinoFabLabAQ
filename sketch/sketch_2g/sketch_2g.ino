/*
	Versione avanzata del classico blink
	con l'utilizzo di array
*/

const int num = 6, LEDspeed = 200;
const int pins[num] = { 2, 3, 4, 5, 6, 7 };

void setup()
{
	// impostiamo come output i pin in sequenza
	for(int i=0; i<num; i++)
	{
		pinMode(pins[i], OUTPUT);
	}
}

void loop()
{
	// accendiamo
	for(int i=0; i<num; i++)
	{
		digitalWrite(pins[i], HIGH);
		delay(LEDspeed);
	}
	// spegniamo
	for(int i=0; i<num; i++)
	{
		digitalWrite(pins[i], LOW);
		delay(LEDspeed);
	}
}