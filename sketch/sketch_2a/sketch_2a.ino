/*
	Cambiamo lo stato di un LED da acceso a spento
	quando premiamo un pulsante, salvando lo stato
*/

const int led = 2;		// il pin dove è il LED
const int button = 3;	// il pin dove è il pulsante
bool state = true;

void setup ()
{
	pinMode(led, OUTPUT);	// impostiamo come output
	pinMode(button, INPUT_PULLUP);	// impostiamo come input
}

void loop ()
{
	if (!digitalRead(button))
	{
		state = !state;
		digitalWrite(led, state);
		delay(200);
	}
}