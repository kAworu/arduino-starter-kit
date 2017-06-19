#define	POTPIN	A0
#include <Servo.h>

Servo myServo;

void setup() {
	myServo.attach(9);
	Serial.begin(9600);
}

void loop() {
	int pot = analogRead(POTPIN);
	Serial.print("Potentiometer=");
	Serial.print(pot);
	int angle = map(pot, 0, 1023, 0, 179);
	Serial.print(", angle=");
	Serial.println(angle);
	myServo.write(angle);
	delay(15);
}
