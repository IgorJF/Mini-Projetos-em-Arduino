#include <Adafruit_NeoPixel.h>


#define     NUMPIXELS      16   
#define     PIN            6
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int  num_LED = 0x00;
int  aux = 0;
int  pot_value = 0;

void setup() 
{ 
  Serial.begin(115200);
  pinMode(A0,  INPUT);
  pixels.begin(); 
} 

void loop() 
{
  pot_value = analogRead(A0);
  num_LED = map(pot_value, 1023, 0, 0, 19);

  for(int i=19;i>=num_LED;i-=1) {
    pixels.setPixelColor(i, pixels.Color(255,0,0)); 
    pixels.show();
  } 
  for(int j=(num_LED-1); j>=0; j-=1) {
    pixels.setPixelColor(j, pixels.Color(0,0,0));
    pixels.show();
  }
}

