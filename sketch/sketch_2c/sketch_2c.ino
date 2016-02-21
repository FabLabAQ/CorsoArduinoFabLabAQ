/*
	Interruttore con debounce avanzato
*/

const int led = 2, button = 3, debounce = 250;
bool LEDstate = true, prevState = false, buttonState;
unsigned long prevMillis;

void setup ()
{
	pinMode(led, OUTPUT);	// impostiamo come output
	pinMode(button, INPUT_PULLUP);	// impostiamo come input
}

void loop ()
{
	buttonState = digitalRead(button);

	if (buttonState != prevState && millis() > prevMillis + debounce)
	{
		LEDstate = !LEDstate;
		prevMillis = millis();
	}
	
	digitalWrite(led, LEDstate);
	prevState = buttonState;
}