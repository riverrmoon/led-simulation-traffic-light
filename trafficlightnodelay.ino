const int led = 2;
const int led2 = 22;
const int led3 = 23;

const int leds[] = { led, led2, led3 };

unsigned long current;
const int interval = 2000;
bool start = true;

void setup() {
  for (int i = 0; i <= 2; i++) {
    pinMode(leds[i], OUTPUT);
  }
  Serial.begin(9600);
  while (start) {
    Serial.println("Start");
    if (millis() - current >= interval) {
      start = false;
    }
  }
}

void loop() {
  for (int i = 2; i >= 0;) {
    if (millis() - current >= interval) {
      current = millis();
      digitalWrite(leds[i], HIGH);
      i--;
    }
    if (i >= 0) {
      digitalWrite(leds[i], LOW);
      digitalWrite(leds[i - 1], LOW);
    } else if (i < 0) {
      digitalWrite(leds[i], LOW);
      digitalWrite(leds[i + 2], LOW);
    }
  }
}
