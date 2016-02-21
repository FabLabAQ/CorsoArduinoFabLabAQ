/*
	Cambiare lo stato di un LED da spento a
	lampeggiante alla pressione di un pulsante.
*/

const int led = 2, button = 3, ledSpeed = 1000, debounce = 250;
bool blinkState, LEDstate = true, prevState = false, buttonState;
unsigned long prevDebounce, prevBlink;

void setup ()
{
	pinMode(led, OUTPUT);	// impostiamo come output
	pinMode(button, INPUT_PULLUP);	// impostiamo come input
}

void loop ()
{
	buttonState = digitalRead(button);

	if (buttonState != prevState && millis() > prevDebounce + debounce)
	{
		blinkState = !blinkState;
		prevDebounce = millis();
	}
	
	prevState = buttonState;

	if (blinkState)
	{
		if (millis() > prevBlink + ledSpeed)
		{
			LEDstate = !LEDstate;
			prevBlink = millis();
		}
		digitalWrite(led, LEDstate);
	}
	else
	{
		digitalWrite(led, LOW);
	}
}