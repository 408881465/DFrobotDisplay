//#ifndef __MPYTHON_H
//#define __MPYTHON_H

//#if ARDUINO >= 100
//#include "Arduino.h"
//#else
//#include "WProgram.h"
//#endif

#include <Wire.h>
#include <MPython_Display_I2C.h>
MPython_Display_I2C mydisplay;

void setup() {
  Wire.begin(23, 22);
  mydisplay.begin();
  //  mydisplay.fillScreen(1);
  mydisplay.lineWidth(1);
  mydisplay.rect(0, 0, 127, 64, false);
  mydisplay.setCursor(40, 24);
  mydisplay.print("你好世界");
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
