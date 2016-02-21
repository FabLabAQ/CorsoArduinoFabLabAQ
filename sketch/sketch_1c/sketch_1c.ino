/*
	usiamo una variabile booleana per accendere un LED
	spegnendo l’altro quando premiamo un pulsante
	senza l'ausilio di variabili
*/

const int led0 = 2;		// il pin dove è il primo LED
const int led1 = 3;		// il pin dove è il secondo LED
const int button = 4;	// il pin dove è il pulsante

void setup ()
{
	pinMode(led0, OUTPUT);	// impostiamo come output
	pinMode(led1, OUTPUT);	// impostiamo come output
	pinMode(button, INPUT);	// impostiamo come input
}

void loop ()
{
	digitalWrite(led0, digitalRead(button));	// acceso se true

	digitalWrite(led1, !digitalRead(button));	// spento se true
}