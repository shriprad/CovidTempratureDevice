#include <Arduino.h>
#include <TM1637Display.h>


#define TEST_DELAY 2000

#define CLK 2
#define DIO 3




TM1637Display display(CLK,DIO);



void setup() {

}

void loop() {

  display.setBrightness(0x0f);

  uint8_t data[] = { 0x0, 0x0, 0x0, 0x0 };
  display.setSegments(data);
  display.showNumberDec(23, false, 3,1);
  delay(TEST_DELAY);
  int k=1234;

  display.setSegments(data);
  display.showNumberDec(k, false, 4, 0);
  delay(TEST_DELAY);

  

}
