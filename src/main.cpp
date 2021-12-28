#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include "../src/apps/App_atABC.h"


void setup() {
  // put your setup code here, to run once:
  atABC.Debug();
}

void loop() {
  // put your main code here, to run repeatedly:
  atABC.Run_Application();
  delay(1000);
}