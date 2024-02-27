const int pinSensorSom = 7; 
const int pinLed = 8;      
const int pinBuzzer = 3;    

int estadoLed = LOW;
int ultimoEstadoSom = LOW;
unsigned long tempoUltimaBatida = 0;
unsigned long intervaloEntreBatidas = 1000; 

void setup() {
  pinMode(pinSensorSom, INPUT);
  pinMode(pinLed, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);
  digitalWrite(pinLed, estadoLed);
  Serial.begin(9600);
}

void loop() {
  int estadoSom = digitalRead(pinSensorSom);

  if (estadoSom != ultimoEstadoSom) {
    // Se detectar uma batida de palmas e já tiver passado tempo suficiente desde a última batida
    if (estadoSom == HIGH && millis() - tempoUltimaBatida > intervaloEntreBatidas) {
      if (estadoLed == LOW) {
        estadoLed = HIGH; 
        tone(pinBuzzer, 1000); 
      } else {
        estadoLed = LOW;  
        tone(pinBuzzer, 500); 
      }
      digitalWrite(pinLed, estadoLed); 
      tempoUltimaBatida = millis();     
    }
    ultimoEstadoSom = estadoSom; 
  }

  // Desliga o buzzer após um curto período para evitar que ele fique ligado continuamente
  if (millis() - tempoUltimaBatida > 50) {
    noTone(pinBuzzer);
  }
}

