/*
	Pilotare un motore con metà ponte H.
	I pin en1 ed en2 devono essere PWM.
*/

const int dir1a = 2, dir1b = 4, en1 = 3, pot1 = A0, button1 = 5;
bool state1;

void setup ()
{
	pinMode(dir1a, OUTPUT);	// impostiamo come output
	pinMode(dir1b, OUTPUT);	// impostiamo come output
	pinMode(en1, OUTPUT);	// impostiamo come output
	pinMode(pot1, INPUT);	// impostiamo come input
	pinMode(button1, INPUT_PULLUP);	// impostiamo come input con pullup
}

void loop ()
{
	int val1 = analogRead(pot1) /4;	// leggiamo e dividiamo
	analogWrite(en1, val1);			// 

	if (!digitalRead(button1))
	{
		state1 = !state1;
		digitalWrite(dir1a, state1);
		digitalWrite(dir1b, !state1);
		delay(200);
	}
}