/*
	Questo sketch contiene una breve guida di riferimento
	per la sintassi e le funzioni base Arduino
	IGNORE: TEST EDIT DA LUIGI TESSITORE 220216
*/

// ************* Lezione 1 parte 1 *************

// *** funzioni fondamentali di Arduino ***
void setup()
{
	// il codice inserito qui gira soltanto una volta all'accensione
}

void loop()
{
	// il codice scritto qui viene ripetuto all'infinito
}

// *** dichiarazione e inizializzazione di variabili ***
// tipi interi
int i;
int i = 0;
// caratteri
char a = 'a';
// array
int i[8];
int i[] = { x, y, z};
char abc[] = { 'a', 'b', 'c' };
char abc[] = "abc";
unsigned int i;
const char a = 'a';
const int led = 13;
bool 
bool b = true;
bool b = false;

// *** funzioni pin digitali ***
// impostare un pin come input, output o input con pull-up
pinMode(pin, OUTPUT);
pinMode(pin, INPUT);
pinMode(pin, INPUT_PULLUP);
// uscita digitale
digitalWrite(pin, HIGH);
digitalWrite(pin, LOW);
digitalWrite(pin, espressione o variabile booleana);
// lettura digitale
bool stat = digitalRead(pin);
digitalWrite(pin1, !digitalRead(pin2));

// *** funzioni tempo ***
// bloccare l'esecuzione
delay(millisecondi);
delayMicroseconds(microsecondi);
// conoscere il tempo trascorso dall'accensione, in millisecondi o microsecondi
unsigned long time = millis();
unsigned long time = micros();

// ************* Fine lezione 1 parte 1 *************

// ************* Lezione 1 parte 2 *************

// *** strutture di controllo del C++ ***

// se è vera l'espressione tra parentesi tonde esegui
if (condizione)
{
	// istruzioni
}
// se è vera l'espressione tra parentesi tonde esegui le istruzioni,
// altrimenti esegui altre istruzioni
if (condizione)
{
	// istruzioni
}
else
{
	// istruzioni alternative
}
// if in cascata
if (prima condizione)
{
	// istruzioni
}
else if (seconda condizione)
{
	// altre istruzioni
}

// finchè è vera la condizione tra parentesi esegui le istruzioni
while (condizione)
{
    // istruzioni
}
// esegui le istruzioni finchè è vera la condizione tra parentesi
do
{
    // istruzioni
}
while (condizione);

// ciclo for
for(inizializzazione; condizione; incremento)
{
    // istruzioni
}
// un esempio chiaro
for(int i=0; i<n; i++)
{
    // istruzioni
}

// possibili condizioni all'interno di strutture di controllo
