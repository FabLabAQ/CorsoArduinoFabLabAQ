/*
	usiamo il PWM per regolare la luminosità di un LED
	o la velocità di un motore usando un potenziometro
*/

const int led = 3;	// il pin dove è connesso il LED
const int pot = A0;	// il pin del potenziometro

void setup ()
{
	pinMode(led, OUTPUT);	// impostiamo come output
	pinMode(pot, INPUT);	// impostiamo come input
}

void loop ()
{
	int val = analogRead(pot) /4;	// leggiamo e dividiamo
	// dividiamo per 4 perchè 0~1023 -> 1024/4=256 -> 0~255
	analogWrite(led, val);			// pilotiamo il LED
}