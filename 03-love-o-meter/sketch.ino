#define FIRST_LED	2
#define LAST_LED	4
#define SENSOR_PIN	A0

float baseline = 20.0;

float read_temperature() {
	int val       = analogRead(SENSOR_PIN);
	float voltage = (val / 1024.0) * 5.0;
	float temp    = (voltage - 0.5) * 100;
	return (temp);
}

void setup() {
	Serial.begin(9600); // open the serial port
	for (int i = FIRST_LED; i <= LAST_LED; i++) {
		pinMode(i, OUTPUT);
		digitalWrite(i, LOW);
	}
	baseline = read_temperature();
}

void loop() {
	float temp = read_temperature();
	Serial.print("baseline: ");
	Serial.print(baseline);
	Serial.print(", °C: ");
	Serial.println(temp);
	digitalWrite(4, (temp > baseline + 3));
	digitalWrite(3, (temp > baseline + 2));
	digitalWrite(2, (temp > baseline + 1));
	delay(1000);
}
