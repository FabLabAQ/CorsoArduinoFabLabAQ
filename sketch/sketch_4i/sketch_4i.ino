/*
	Comandare più LED dal terminale seriale.
	I comandi da inviare sono del tipo: "L0 255" per accendere il primo led, "L0 0" per spegnerlo
*/

const int ledNum = 6, leds[ledNum] = { 3, 5, 6, 9, 10, 11 };

void setup ()
{
	Serial.begin(9600);		// inizializza a velocità 9600
	for(int i=0; i<=ledNum; i++)
	{
		pinMode(leds[i], OUTPUT);	// impostiamo come out
	}
}

void loop ()
{
	if (Serial.read() == 'L')
	{
		int i = Serial.parseInt();
		int value = Serial.parseInt();
		analogWrite(leds[i], value);
	}
}