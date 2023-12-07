int redPin = 11;
int greenPin = 10;
int bluePin = 9;
int inputPin = 2;
int pirState = LOW;
int val = 0;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(inputPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  val = digitalRead(inputPin);
  if (val == HIGH) {
    if (pirState == LOW) {
      pirState = HIGH;
      analogWrite(redPin, 255);
      analogWrite(greenPin, 255);
      analogWrite(bluePin, 255);
    }
  } else {
    if (pirState == HIGH) {
      pirState = LOW;
      analogWrite(redPin, 0);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, 0);
    }
  }
}
