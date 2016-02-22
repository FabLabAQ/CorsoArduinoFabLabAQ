/*
	Leggere lo stato di un pulsante sul terminale seriale solo se viene premuto e senza ripetizioni.
 */

const int button = 5;
bool pressing;

void setup()
{
	Serial.begin(9600);
	pinMode(button, INPUT_PULLUP);
}

void loop()
{
	if (!digitalRead(button) && !pressing)
	{
		Serial.println("Pulsante ON.");
		pressing = true;
		delay(50);
	}
	else if (digitalRead(button))
	{
		pressing = false;
	}
}