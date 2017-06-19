#define	PHOTORESPIN	A0
#define	PIEZOPIN	8

int high = 1023;
int low  =    0;

void setup() {
	// initialize digital pin LED_BUILTIN as an output.
	pinMode(LED_BUILTIN, OUTPUT);
	digitalWrite(LED_BUILTIN, HIGH);
	while (millis() < 5000) {
		int light = analogRead(PHOTORESPIN);
		high = max(high, light);
		low = min(low, light);
	}
	digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
	int light = analogRead(PHOTORESPIN);
	int pitch = map(light, low, high, 50, 4000);
	tone(PIEZOPIN, pitch, 20);
	delay(10);
}
