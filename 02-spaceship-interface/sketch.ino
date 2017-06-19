#define FIRST_RED_LED_PIN	5
#define SECOND_RED_LED_PIN	4
#define GREEN_LED_PIN		3
#define PUSH_BUTTON_PIN		2

void setup() {
	pinMode(PUSH_BUTTON_PIN,    INPUT);
	pinMode(FIRST_RED_LED_PIN,  OUTPUT);
	pinMode(SECOND_RED_LED_PIN, OUTPUT);
	pinMode(GREEN_LED_PIN,      OUTPUT);
}

void loop() {
	int state   = digitalRead(PUSH_BUTTON_PIN);
	int pressed = (state == HIGH);
	if (pressed) {
		digitalWrite(GREEN_LED_PIN,      LOW);
		digitalWrite(FIRST_RED_LED_PIN,  HIGH);
		digitalWrite(SECOND_RED_LED_PIN, LOW);
		delay(250);
		digitalWrite(FIRST_RED_LED_PIN,  LOW);
		digitalWrite(SECOND_RED_LED_PIN, HIGH);
		delay(250);
	} else {
		digitalWrite(GREEN_LED_PIN,      HIGH);
		digitalWrite(FIRST_RED_LED_PIN,  LOW);
		digitalWrite(SECOND_RED_LED_PIN, LOW);
	}
}
