#include <Adafruit_GFX.h>
#include <Adafruit_TFTLCD.h>

int Cline = 0;
int line = 0;

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

void setup() {
  Serial.begin(9600);
  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  tft.setRotation(1);
  tft.fillScreen(BLACK);
  tft.setCursor(0, 0);
  tft.setTextColor(GREEN);
  tft.setTextSize(4);
  tft.println("Console");
  delay(1000);
  Cline = 0;
  line = 0;
  tft.setTextSize(2);
  tft.fillScreen(BLACK);

}

void loop() {
  if (Serial.available() > 0) {
   if (line + 1 > 16) {
    tft.fillScreen(BLACK);
    line = 0;
    Cline = 0;
   }
   String str = Serial.readString();
   tft.setCursor(0, Cline);
   if (str != "") {
    tft.println(str);
   } else{
     tft.println(" ");
   }
   if (str.length() > 26) {
    int more = round(str.length() / 26.0);
    line += more;
    Cline += 15 * more;
   }
  Cline += 15;
  line += 1;
  }

}
