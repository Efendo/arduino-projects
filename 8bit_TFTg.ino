#include <Adafruit_GFX.h>
#include <Adafruit_TFTLCD.h>

String bit = "";

#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0

#define LCD_RESET A4

#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

void wait(bool condition) {
  while (condition != 1) {
    delay(10);
  }
}

void setup() {
  Serial.begin(9600);
  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  tft.setRotation(1);
  tft.fillScreen(BLACK);
}

void loop() {
  tft.fillScreen(BLACK);
  tft.fillRect(0, 215, 840, 25, WHITE);
  tft.setTextColor(GREEN);
  tft.setTextSize(4);
  tft.setCursor(70, 100);
  bit = "";
  for (int i = 0; i < 8; i++) {
    bit += String(random(0, 2));
  }
  tft.println(bit);
  delay(100);
}
