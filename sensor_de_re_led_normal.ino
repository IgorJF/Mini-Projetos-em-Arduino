#define TRIG_PIN 6
#define ECHO_PIN 5
#define BUZZER_PIN 3
#define LED_PIN 8

long duration, distance;
int buzzerSpeed;
int buzzerTone;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration / 2) / 29.1;

  if (distance < 10) {
    buzzerSpeed = 50; 
    buzzerTone = 1500; 
    ledBlink(50); 
  } else if (distance >= 10 && distance <= 30) {
    buzzerSpeed = 100; 
    buzzerTone = 1000; 
    ledBlink(300); 
  } else {
    buzzerSpeed = 200; 
    buzzerTone = 500; 
    ledBlink(500); 
  }

  // Emite o tom do buzzer
  tone(BUZZER_PIN, buzzerTone);
  delay(buzzerSpeed);
  noTone(BUZZER_PIN);
}

void ledBlink(int interval) {
  digitalWrite(LED_PIN, HIGH);
  delay(interval / 2);
  digitalWrite(LED_PIN, LOW);
  delay(interval / 2); 
}
