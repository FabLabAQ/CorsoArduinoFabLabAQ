/*
	Pilotare due motori con un ponte H intero.
	I pin en1 ed en2 devono essere PWM.
*/

const int dir1a = 2, dir1b = 4, en1 = 3, pot1 = A0, button1 = 5,
          dir2a = 7, dir2b = 8, en2 = 6, pot2 = A1, button2 = 9;
bool state1, state2;

void setup ()
{
	pinMode(dir1a, OUTPUT);	// impostiamo come output
	pinMode(dir1b, OUTPUT);	// impostiamo come output
	pinMode(en1, OUTPUT);	// impostiamo come output
	pinMode(pot1, INPUT);	// impostiamo come input
	pinMode(button1, INPUT_PULLUP);	// impostiamo come input con pullup

	pinMode(dir2a, OUTPUT);	// impostiamo come output
	pinMode(dir2b, OUTPUT);	// impostiamo come output
	pinMode(en2, OUTPUT);	// impostiamo come output
	pinMode(pot2, INPUT);	// impostiamo come input
	pinMode(button2, INPUT_PULLUP);	// impostiamo come input con pullup
}

void loop ()
{
	int val1 = analogRead(pot1) /4;	// leggiamo e dividiamo
	int val2 = analogRead(pot2) /4;	// leggiamo e dividiamo

	analogWrite(en1, val1);			// 
	analogWrite(en2, val2);			// 

	if (!digitalRead(button1))
	{
		state1 = !state1;
		digitalWrite(dir1a, state1);
		digitalWrite(dir1b, !state1);
		delay(200);
	}

	if (!digitalRead(button2))
	{
		state2 = !state2;
		digitalWrite(dir2a, state2);
		digitalWrite(dir2b, !state2);
		delay(200);
	}
}