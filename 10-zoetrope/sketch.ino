#define	CONTROLPIN1	2
#define	CONTROLPIN2	3
#define	ENABLEPIN	9
#define	DIRECTIONPIN	4
#define	ONOFFPIN	5
#define	POTPIN		A0

void setup() {
	Serial.begin(9600);
	pinMode(DIRECTIONPIN, INPUT);
	pinMode(ONOFFPIN,     INPUT);
	pinMode(CONTROLPIN1,  OUTPUT);
	pinMode(CONTROLPIN2,  OUTPUT);
	pinMode(ENABLEPIN,    OUTPUT);
	digitalWrite(ENABLEPIN, LOW);
}

int prev_on_off     = LOW;
int prev_left_right = LOW;
int enabled   = 0;
int direction = 0;

void loop() {
	int on_off     = digitalRead(ONOFFPIN);
	int left_right = digitalRead(DIRECTIONPIN);
	int speed = analogRead(POTPIN) / 4;

	if (on_off != prev_on_off && on_off == HIGH)
		enabled = !enabled;
	if (left_right != prev_left_right && left_right == HIGH)
		direction = !direction;

	if (direction) {
		digitalWrite(CONTROLPIN1, HIGH);
		digitalWrite(CONTROLPIN2, LOW);
	} else {
		digitalWrite(CONTROLPIN1, LOW);
		digitalWrite(CONTROLPIN2, HIGH);
	}

	analogWrite(ENABLEPIN, enabled ? speed : 0);
	Serial.print("enabled=");
	Serial.print(enabled);
	Serial.print(",direction=");
	Serial.print(direction);
	Serial.print(",speed=");
	Serial.println(speed);

	prev_on_off     = on_off;
	prev_left_right = left_right;
}
