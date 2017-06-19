#define	SWITCHPIN	2
#define	MOTORPIN	9
void setup() {
	pinMode(SWITCHPIN, INPUT);
	pinMode(MOTORPIN,  OUTPUT);
}

void loop() {
	int state = digitalRead(SWITCHPIN);
	digitalWrite(MOTORPIN, state);
}
