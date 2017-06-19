#include <LiquidCrystal.h>

#define	SWITCHPIN	6

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int state = 0;
int prev  = 0;
int reply;

void setup() {
	lcd.begin(16, 2);
	pinMode(SWITCHPIN, INPUT);
	lcd.print("Ask the");
	lcd.setCursor(0, 1);
	lcd.print("Crystal Ball!");
}

void loop() {
	state = digitalRead(SWITCHPIN);
	if (state !=  prev) {
		if (state == LOW) {
			reply = random(8);
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("The ball says:");
			lcd.setCursor(0, 1);
			switch (reply) {
			case 0:
				lcd.print("Yes");
				break;
			case 1:
				lcd.print("Most likely");
				break;
			case 2:
				lcd.print("Certainly");
				break;
			case 3:
				lcd.print("Outlook good");
				break;
			case 4:
				lcd.print("Unsure");
				break;
			case 5:
				lcd.print("Ask again");
				break;
			case 6:
				lcd.print("Doubtful");
				break;
			case 7:
				lcd.print("No");
				break;
			}
		}
	}
	prev = state;
}
