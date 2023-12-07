#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define DHTPIN 5
#define DHTTYPE DHT22

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 

#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

DHT dht(DHTPIN, DHTTYPE);

const int blue = 2; 
const int red = 3;  

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C, false, false)) {
    Serial.println(F("Erro ao iniciar o display OLED"));
    for (;;)
      ;
  }

  display.display();
  delay(2000);
  display.clearDisplay();
}

void loop() {
  delay(2000);

  float temperature = dht.readTemperature(); // Ler temperatura em Celsius

  if (isnan(temperature)) {
    Serial.println(F("Erro ao ler dados do DHT!"));
    return;
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Temperatura:");

  display.setTextSize(2);
  display.setCursor(0, 16);
  display.print(temperature);
  display.println(" *C");
  display.display();

  if (temperature < 20) {
    digitalWrite(blue, HIGH);
    digitalWrite(red, LOW);
  } else {
    digitalWrite(blue, LOW);
    digitalWrite(red, HIGH);
  }
}
