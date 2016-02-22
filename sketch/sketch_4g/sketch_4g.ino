/*
	Regolare la luminosità di un LED dal terminale seriale.
	I comandi da inviare sono del tipo: L0, L127, fino a L255
*/

const int led = 3;

void setup ()
{
	Serial.begin(9600);		// inizializza a velocità 9600
	pinMode(led, OUTPUT);	// impostiamo come out
}

void loop ()
{
	if (Serial.read() == 'L')
	{
		int value = Serial.parseInt();
		analogWrite(led, value);
	}
}