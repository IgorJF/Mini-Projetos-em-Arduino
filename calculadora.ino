#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Keypad.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

const byte ROWS = 4; 
const byte COLS = 4; 
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String input = "";
float num1 = 0;
float num2 = 0;
char operation = ' ';

void setup() {
  Wire.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
  display.display();
  delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  char key = keypad.getKey();
  if (key != NO_KEY) {
    if (key >= '0' && key <= '9') {
      input += key;
      display.clearDisplay();
      display.setCursor(0, 0);
      display.println(input);
      display.display();
    } else if (key == 'A' || key == 'B' || key == 'C' || key == 'D') {
      num1 = input.toFloat();
      operation = key;
      input = "";
    } else if (key == '#') { 
      num2 = input.toFloat();
      float result = 0;
      switch (operation) {
        case 'A':
          result = num1 + num2;
          break;
        case 'B':
          result = num1 - num2;
          break;
        case 'C':
          result = num1 * num2;
          break;
        case 'D':
          if (num2 != 0) {
            result = num1 / num2;
          } else {
            result = NAN; 
          }
          break;
        default:
          break;
      }
      display.clearDisplay();
      display.setCursor(0, 0);
      display.print("Resultado: ");
      display.println(result);
      display.display();
      input = "";
      num1 = 0;
      num2 = 0;
      operation = ' ';
    }
  }
}
