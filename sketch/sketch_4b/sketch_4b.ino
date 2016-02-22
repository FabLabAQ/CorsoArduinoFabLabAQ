/*
	Leggere continuamente il valore di un potenziometro sul terminale seriale.
 */

const int pot = A0;		// il pin dove è connesso il potenziometro

void setup ()
{
	Serial.begin(9600);		// inizializza a velocità 9600
	pinMode(pot, INPUT);	// impostiamo come input
}

void loop ()
{
	int val = analogRead(pot);						// leggiamo e dividiamo
	Serial.print("Posizione potenziometro: ");
	Serial.println(val);							// scriviamo e andiamo a capo
	delay(500);										// aspettiamo un po’
}