/*
	usiamo una variabile booleana per accendere un LED
	spegnendo l’altro quando premiamo un pulsante
	senza l'ausilio di struttore di controllo
*/

const int led0 = 2;		// il pin dove è il primo LED
const int led1 = 3;		// il pin dove è il secondo LED
const int button = 4;	// il pin dove è il pulsante

void setup ()
{
	pinMode(led0, OUTPUT);	// impostiamo come output
	pinMode(led1, OUTPUT);	// impostiamo come output
	pinMode(button, INPUT_PULLUP);	// impostiamo come input
	// usiamo il pullup interno per non ricorrere a quello esterno
}

void loop ()
{
	// leggiamo lo stato del pulsante e salviamolo nella variabile
	bool stat = digitalRead(button);

	digitalWrite(led0, stat);	// acceso se stat è true

	digitalWrite(led1, !stat);	// spento se stat è true (!true = false)
}