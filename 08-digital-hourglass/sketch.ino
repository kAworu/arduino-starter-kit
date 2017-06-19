#define	NELEM(x)	(sizeof(x) / sizeof(*(x)))
#define	SWITCHPIN	8

int ledpin[] = {
	2, 3, 4, 5, 6, 7,
};
int ledstate[] = {
	LOW, LOW, LOW, LOW, LOW, LOW
};

int prevtilt;
unsigned long prevtime;
unsigned long interval = 1000;

void reset_leds() {
	memset(ledstate, LOW, sizeof(ledstate));
}

void dim_all_leds() {
	for (int i = 0; i < NELEM(ledpin); i++)
		digitalWrite(ledpin[i], LOW);
}

void setup() {
	for (int i = 0; i < NELEM(ledpin); i++)
		pinMode(ledpin[i], OUTPUT);
	pinMode(SWITCHPIN, INPUT);
	prevtilt = digitalRead(SWITCHPIN);
	prevtime = millis();
}

void loop() {
	/* handle the tilt switch */
	int tilt = digitalRead(SWITCHPIN);
	if (prevtilt != tilt)
		reset_leds();
	prevtilt = tilt;

	unsigned long now = millis();
	if (now - prevtime > interval) {
		prevtime = now;
		/* find the first ledstate LOW and switch it up to HIGH */
		int all = 1;
		for (int i = 0; i < NELEM(ledstate); i++) {
			if (ledstate[i] == LOW) {
				all = 0;
				ledstate[i] = HIGH;
				break;
			}
		}
		if (all) {
			dim_all_leds();
			delay(100);
		}
	}
	for (int i = 0; i < NELEM(ledpin); i++)
		digitalWrite(ledpin[i], ledstate[i]);
	delay(100);
}
