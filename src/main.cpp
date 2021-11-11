
//#include <SPI.h>
#include <TFT_eSPI.h> // Hardware-specific library
#include "tft_test.h"
#include "test_dial.h"

TFT_eSPI tft = TFT_eSPI(); // Invoke custom library

void setup()
{
  // put your setup code here, to run once:
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PB1, OUTPUT);

  tft.init();
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_YELLOW);
  tft.setTextSize(2);
  tft.setCursor(8, 200);
  tft.print("Jipieieh!");

  // reading info registers, but content does not make any sense
  int misa = 0, mvendorid = 0, marchid = 0;
  asm volatile("csrr x0, misa" : "=r"(misa));
  asm volatile("csrr x0, mvendorid" : "=r"(mvendorid));
  asm volatile("csrr x0, marchid" : "=r"(marchid));
  tft.setCursor(0, 9);
  tft.print(misa, HEX);
  tft.setCursor(0, 30);
  tft.print(mvendorid, HEX);
  tft.setCursor(0, 60);
  tft.print(marchid, HEX);

  // LCD functions(240 x 320)
  // tft.fillCircle(50, 50, 20, TFT_DARKGREEN);
  // tft.drawCircle(100, 50, 20, TFT_DARKGREEN);

  // tft.fillRect(50, 100, 40, 20, TFT_DARKGREY);
  // tft.drawRect(100, 100, 40, 20, TFT_DARKGREY);
  // tft.fillRoundRect(150, 100, 40, 20, 5, TFT_DARKGREY);

  // tft.fillTriangle(50, 200, 20, 240, 80, 240, TFT_ORANGE);
  // tft.drawTriangle(100, 200, 70, 240, 130, 240, TFT_ORANGE);
}

void loop()
{
  // put your main code here, to run repeatedly:
  static int loopCnt = 0;

  loopCnt++;
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(PB1, HIGH);
  // wait for a second
  delay(1000);
  // turn the LED off by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(PB1, LOW);
  // wait for a second
  delay(1000);

  if (loopCnt % 3 == 0) {
    // testDial(tft);
    // delay(10*1000);
  }
  if (loopCnt % 5 == 0) {
  //   tftTest(tft);
  //   delay(30*1000);
   }
}