/*
	Comandare più LED dal terminale seriale.
	I comandi da inviare sono del tipo: "L2 1" per accendere il led 2, "L2 0" per spegnerlo
*/

const int ledMin = 2, ledMax = 7;

void setup ()
{
	Serial.begin(9600);		// inizializza a velocità 9600
	for(int i=ledMin; i<=ledMax; i++)
	{
		pinMode(i, OUTPUT);	// impostiamo come out
	}
}

void loop ()
{
	if (Serial.read() == 'L')
	{
		int led = Serial.parseInt();
		bool value = Serial.parseInt();
		digitalWrite(led, value);
	}
}