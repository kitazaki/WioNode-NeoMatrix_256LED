#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <ESP8266WiFi.h>

#define PIN 5

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(32, 8, PIN,  // wide x high = 32 x 8
  NEO_MATRIX_BOTTOM    + NEO_MATRIX_RIGHT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);
 
const uint16_t colors[] = {
  matrix.Color(255, 0, 0),
  matrix.Color(0, 255, 0),
  matrix.Color(0, 0, 255),
  matrix.Color(255, 255, 0),
  matrix.Color(255, 0, 255),
  matrix.Color(0, 255, 255),
  matrix.Color(255, 255, 255)
};
 
void setup() {
  pinMode(15, OUTPUT);     // for Wio-Node
  digitalWrite(15, 1);     // for Wio-Node
  WiFi.disconnect();       // to disable Wi-Fi
  WiFi.mode(WIFI_OFF);     // to disable Wi-Fi
  WiFi.forceSleepBegin();  // to disable Wi-Fi
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(50);  // brightness [5 - 50]
  matrix.setTextColor(colors[0]);
}
 
int x = matrix.width();
int pass = 0;

void loop() {
  matrix.fillScreen(0);
  matrix.setCursor(x, 0);
//  matrix.print(F("SIerIoTLT x TechNight @SoftBank"));  // text message 
  matrix.print(F("SoftBank DeepTech"));  // text message 
//                12345678901234567890123456789012345678901234567890
  if(--x < -102)  // 6 x 17 = 102    = 6LED x (# of letters)
  {
    x = matrix.width();
    if(++pass >= 7) pass = 0;  // # of Colors
    matrix.setTextColor(colors[pass]);
  }
  matrix.show();
  delay(60);  // 
}

