/*
	Facciamo lampeggiare un LED senza usare delay
*/

const int led = LED_BUILTIN, ledSpeed = 1000;
bool state = true;
unsigned long prevMillis;

void setup ()
{
	pinMode(led, OUTPUT);	// impostiamo come output
}

void loop ()
{
	if (millis() > prevMillis + ledSpeed)
	{
		state = !state;
		prevMillis = millis();
	}
	digitalWrite(led, state);
}