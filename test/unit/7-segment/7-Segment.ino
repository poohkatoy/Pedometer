#include "TM1637.h"

const int CLK = 2;
const int DIO = 3;

TM1637 sevenSegment(CLK, DIO);

void setup() {
  sevenSegment.init();
  sevenSegment.set(5); // BRIGHT 0-7;

  sevenSegment.displayStr("0000");
  delay(2000);
}

int number = 0;

void loop() {
  sevenSegment.displayNum(number++);
  delay(100);
}