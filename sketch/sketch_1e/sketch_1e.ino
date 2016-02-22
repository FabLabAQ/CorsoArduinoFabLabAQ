/*
	Uso dell'operatore booleano AND per accendere un LED solo se
	entrambi i due (o più) pulsanti vengono premuti
	senza l'ausilio di variabili
	equivale a mettere in serie i pulsanti
*/

const int led = 2;		// il pin dove è il primo LED
const int button1 = 3;		// il pin dove è il primo pulsante
const int button2 = 4;	// il pin dove è il secondo pulsante

void setup ()
{
	pinMode(led, OUTPUT);	// impostiamo come output
	pinMode(button1, INPUT_PULLUP);	// impostiamo come input
	pinMode(button2, INPUT_PULLUP);	// impostiamo come input
	// ricordiamoci che con il pullup la lettura è sempre
	// HIGH/true e quando si preme il pulsante è LOW/false
}

void loop ()
{
	// invertiamo le letture dato che stiamo usando i pullup
	// fate sempre attenzione alle parentesi!
	digitalWrite(led, !digitalRead(button1) && !digitalRead(button2) );
}