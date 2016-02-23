/*
	Pilotare un LED RGB con la comunicazione seriale.
	I comandi da inviare sono del tipo: "L0 255" per accendere il primo led, "L0 0" per spegnerlo
*/

const int RGBpins[3] = { 3, 5, 6 };

void setup ()
{
	Serial.begin(9600);		// inizializza a velocità 9600
	for(int i=0; i<3; i++)
	{
		pinMode(RGBpins[i], OUTPUT);	// impostiamo come out
	}
}

void loop ()
{
	if (Serial.read() == 'L')
	{
		int i = Serial.parseInt();
		int value = Serial.parseInt();
		analogWrite(RGBpins[i], value);
	}
}