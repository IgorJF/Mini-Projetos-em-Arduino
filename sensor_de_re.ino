#define TRIG_PIN 6
#define ECHO_PIN 5
#define BUZZER_PIN 3
#define RED_PIN 11
#define GREEN_PIN 10
#define BLUE_PIN 9

long duration, distance;
int buzzerSpeed;
int buzzerTone;
int redValue, greenValue, blueValue;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
  // Calcula a distancia
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
    redValue = 255;
    greenValue = 0;
    blueValue = 0;
  } else if (distance >= 10 && distance <= 30) {
    buzzerSpeed = 100;
    buzzerTone = 1000;
    redValue = 0;
    greenValue = 0;
    blueValue = 255;
  } else {
    buzzerSpeed = 200;
    buzzerTone = 500;
    redValue = 0;
    greenValue = 255;
    blueValue = 0;
  }

  analogWrite(RED_PIN, redValue);
  analogWrite(GREEN_PIN, greenValue);
  analogWrite(BLUE_PIN, blueValue);
  tone(BUZZER_PIN, buzzerTone);
  delay(buzzerSpeed);
  noTone(BUZZER_PIN);
  delay(100); 
}
