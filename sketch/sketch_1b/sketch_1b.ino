/* vogliamo lampeggiare un LED a intervalli regolari */

const int led = 2,	button = 3; // il pin dove è connesso il LED ‘L’

void setup ()		// gira solo all’accensione
{
	pinMode(led, OUTPUT);	// impostiamo come output
	pinMode(button, INPUT);
}

void loop ()		// gira all’infinito, in loop appunto
{
	digitalWrite(led, digitalRead(button));		// 
}