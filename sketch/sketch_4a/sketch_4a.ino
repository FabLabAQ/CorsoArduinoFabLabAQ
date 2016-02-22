/*
	Stampa della tabella ASCII sul terminale seriale.
 */

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	Serial.println("Stampa dei caratteri ASCII");

	for(int i=32; i<=126; i++)
	{
		Serial.print(i);
		Serial.print(" corrisponde: ");
		Serial.write(i);
		Serial.println("");
		delay(500);
	}
}