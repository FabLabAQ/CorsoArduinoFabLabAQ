/*
	Utilizzo di while per far lampeggiare un
	LED durante la pressione di un pulsante.
*/

const int led = 2;		// il pin dove è il LED
const int button = 3;	// il pin dove è il pulsante
const int LEDspeed = 500;

void setup ()
{
	pinMode(led, OUTPUT);	// impostiamo come output
	pinMode(button, INPUT_PULLUP);	// impostiamo come input
}

void loop ()
{
	while (!digitalRead(button))
	{
		digitalWrite(led, HIGH);
		delay(LEDspeed);
		digitalWrite(led, LOW);
		delay(LEDspeed);
	}
}