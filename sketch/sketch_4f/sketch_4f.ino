/*
	Comandare un LED dal terminale seriale con una stringa di testo specifica.
*/

const int led = 2;
String input;
const String ON = "LED ON", OFF = "LED OFF";
bool LEDstate;

void setup ()
{
	Serial.begin(9600);		// inizializza a velocità 9600
	pinMode(led, OUTPUT);	// impostiamo come out
}

void loop ()
{
	while (Serial.available())
	{
		delay(5);
		char c = Serial.read();
		input += c;
	}

	input.trim();

	if (input == ON)
	{
		LEDstate = HIGH;
	}
	else if (input == OFF)
	{
		LEDstate = LOW;
	}

	input = "";
	digitalWrite(led, LEDstate);
}