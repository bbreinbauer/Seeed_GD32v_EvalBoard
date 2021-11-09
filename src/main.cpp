
//#include <SPI.h>
#include <TFT_eSPI.h> // Hardware-specific library
#include "tft_test.h"

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
  tft.setCursor(8, 20);
  tft.print("Jipieieh!");
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

  if (loopCnt % 5 == 0) {
    tftTest(tft);
    delay(30*1000);
  }
}