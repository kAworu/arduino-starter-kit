#define	RLEDPIN		11
#define	GLEDPIN		9
#define	BLEDPIN		10
#define	RSENSORPIN	A2
#define	GSENSORPIN	A1
#define	BSENSORPIN	A0

void setup() {
	Serial.begin(9600);
	pinMode(RLEDPIN, OUTPUT);
	pinMode(GLEDPIN, OUTPUT);
	pinMode(BLEDPIN, OUTPUT);
}

int red    = 0;
int green  = 0;
int blue   = 0;

void loop() {
	red = analogRead(RSENSORPIN);
	delay(5);
	green = analogRead(GSENSORPIN);
	delay(5);
	blue = analogRead(BSENSORPIN);
	Serial.print("Sensor raw values: R=");
	Serial.print(red);
	Serial.print(",G=");
	Serial.print(green);
	Serial.print(",B=");
	Serial.println(blue);
	analogWrite(RLEDPIN, red   / 4);
	analogWrite(GLEDPIN, green / 4);
	analogWrite(BLEDPIN, blue  / 4);
	delay(250);
}
