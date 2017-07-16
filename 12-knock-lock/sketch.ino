#include <Servo.h>

#define	PIEZOPIN	A0
#define	SWITCHPIN	2
#define	YELLOWLED	3
#define	GREENLED	4
#define	REDLED		5

const int quietKnock =  10;
const int loudKnock  = 100;
boolean locked = false;
int knockCount = 0;

Servo myServo;

void setup() {
	Serial.begin(9600);
	myServo.attach(9);
	pinMode(YELLOWLED, OUTPUT);
	pinMode(GREENLED,  OUTPUT);
	pinMode(REDLED,    OUTPUT);
	pinMode(SWITCHPIN, INPUT);
	digitalWrite(GREENLED, HIGH);
	myServo.write(0);
	Serial.println("The box is unlocked!");
}


boolean checkForKnock(int value) {
	boolean valid = (value > quietKnock && value < loudKnock);
	if (valid) {
		digitalWrite(YELLOWLED, HIGH);
		delay(50);
		digitalWrite(YELLOWLED, LOW);
		Serial.print("Valid knock of value: ");
	} else  {
		Serial.print("Bad knock of value: ");
	}
	Serial.println(value);
	return (valid);
}

void loop() {
	if (!locked) {
		if (digitalRead(SWITCHPIN) == HIGH) {
			locked = true;
			knockCount = 0;
			digitalWrite(GREENLED, LOW);
			digitalWrite(REDLED,   HIGH);
			myServo.write(90);
			Serial.println("The box is locked!");
			delay(1000);
		}
	} else {
		int knockVal = analogRead(PIEZOPIN);
		if (knockCount < 3 && knockVal > 0) {
			if (checkForKnock(knockVal))
				knockCount += 1;
			Serial.print(3 - knockCount);
			Serial.println(" more knocks to go");
		} else if (knockCount >= 3) {
			locked = false;
			myServo.write(0);
			delay(20);
			digitalWrite(GREENLED, HIGH);
			digitalWrite(REDLED,   LOW);
			Serial.println("The box is unlocked!");
		}
	}
}
