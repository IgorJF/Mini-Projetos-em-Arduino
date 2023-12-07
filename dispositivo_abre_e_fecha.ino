#include <Servo.h>

int ledVermelho = 12;
int ledVerde = 11;
int botaoVermelho = 7;
int botaoVerde = 6;
Servo meuServo;

int estadoBotaoVerdeAnterior = 0;
int estadoBotaoVermelhoAnterior = 0;
int servoAberto = 0; 

void setup() {
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(botaoVermelho, INPUT);
  pinMode(botaoVerde, INPUT);
  meuServo.attach(9);
  meuServo.write(0); 
}

void loop() {
 
  int estadoBotaoVerde = digitalRead(botaoVerde);
  if (estadoBotaoVerde == HIGH && estadoBotaoVerdeAnterior == LOW) {
    digitalWrite(ledVerde, HIGH); 
    digitalWrite(ledVermelho, LOW); 
    if (servoAberto == 0) {
      meuServo.write(180); 
      servoAberto = 1;
    }
    delay(1000); 
  } else {
    digitalWrite(ledVerde, LOW); 
  }
  estadoBotaoVerdeAnterior = estadoBotaoVerde;


  int estadoBotaoVermelho = digitalRead(botaoVermelho);
  if (estadoBotaoVermelho == HIGH && estadoBotaoVermelhoAnterior == LOW) {
    digitalWrite(ledVerde, LOW); 
    digitalWrite(ledVermelho, HIGH); 
    if (servoAberto == 1) {
      meuServo.write(0); 
      servoAberto = 0;
    }
    delay(1000); 
  } else {
    digitalWrite(ledVermelho, LOW); 
  }
  estadoBotaoVermelhoAnterior = estadoBotaoVermelho;
}
