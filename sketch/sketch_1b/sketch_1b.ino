/*
	Accendiamo un LED alla pressione del pulsante
*/

const int led = 2,	button = 3; // dichiarazione dei pin

void setup ()		// gira solo all’accensione
{
	pinMode(led, OUTPUT);	// impostiamo come output
	pinMode(button, INPUT);	// impostiamo come input
}

void loop ()		// gira all’infinito, in loop appunto
{
	// inseriamo la lettura all'interno della scrittura
	digitalWrite(led, digitalRead(button));
}