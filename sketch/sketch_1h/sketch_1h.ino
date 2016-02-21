/*
	Uso di or per accendere un LED se viene
	premuto almeno uno dei due (o più) pulsanti
	equivale a mettere in parallelo i pulsanti
*/

const int led = 2;		// il pin dove è il primo LED
const int button1 = 3;		// il pin dove è il primo pulsante
const int button2 = 4;	// il pin dove è il secondo pulsante
bool button1status, button2status;

void setup ()
{
	pinMode(led, OUTPUT);	// impostiamo come output
	pinMode(button1, INPUT_PULLUP);	// impostiamo come input
	pinMode(button2, INPUT_PULLUP);	// impostiamo come input
}

void loop ()
{
	button1status = !digitalRead(button1);
	button2status = !digitalRead(button2);

	digitalWrite(led, button1status || button2status);	// acceso se true
}