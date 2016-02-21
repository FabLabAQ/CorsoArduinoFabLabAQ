/* vogliamo lampeggiare un LED a intervalli regolari */

const int pin = 13,	LEDspeed = 1000; // il pin dove è connesso il LED ‘L’

void setup ()		// gira solo all’accensione
{
	pinMode(pin, OUTPUT);	// impostiamo come output
}

void loop ()		// gira all’infinito, in loop appunto
{
	digitalWrite(pin, HIGH);	// accendiamo
	delay(LEDspeed);				// e dopo un secondo

	digitalWrite(pin, LOW);		// spegnamo
	delay(LEDspeed);				// un altro secondo e si riparte col loop
}