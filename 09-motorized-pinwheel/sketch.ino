#define	SWITCHPIN	2
#define	MOTORPIN	9
#define	PMPIN		A0

void setup() {
	Serial.begin(9600);
	pinMode(SWITCHPIN, INPUT);
	pinMode(MOTORPIN,  OUTPUT);
}

void loop() {
	int state = digitalRead(SWITCHPIN);
	int rate  = analogRead(PMPIN);
	Serial.print("state=");
	Serial.print(state == HIGH ? "HIGH" : "LOW");
	Serial.print(", rate=");
	Serial.println(rate);
	// controlled by the switch button
	//digitalWrite(MOTORPIN, state);
	// controlled by the Potentiometer
	// NOTE: rate is [0,1023] and analogWrite expect [0,255] hence we divide
	// by 4.
	analogWrite(MOTORPIN, rate / 4);
}
