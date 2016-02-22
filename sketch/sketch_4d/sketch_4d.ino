/*
	Leggere il valore di un potenziometro sul terminale seriale solo se è cambiato significativamente.
 */

const int pot = A0, sample = 200;// error = 3;
unsigned long val, lastVal;

void setup ()
{
	Serial.begin(9600);		// inizializza a velocità 9600
	pinMode(pot, INPUT);	// impostiamo come input
}

void loop ()
{
	val = 0;

	for(int i=0; i<sample; i++)
	{
	    val += analogRead(pot);
	}

	val /= sample;

	if (lastVal != val)
	{
		Serial.print("Potenziometro: ");
		Serial.println(val);							// scriviamo e andiamo a capo
	}

	lastVal = val;
}