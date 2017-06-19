#define	RESLADDERPIN	A5
#define	PIEZZOPIN	8

int notes[] = {
	262, 294, 330, 349,
};

void setup() {
	Serial.begin(9600);
}

void loop() {
	int key = analogRead(RESLADDERPIN);
	if (key == 1023) // max
		tone(PIEZZOPIN, notes[0]);
	else if (key >= 990 && key <= 1010)
		tone(PIEZZOPIN, notes[1]);
	else if (key >= 505 && key <= 515)
		tone(PIEZZOPIN, notes[2]);
	else if (key >= 5 && key <= 10)
		tone(PIEZZOPIN, notes[3]);
	else
		noTone(PIEZZOPIN);
}
