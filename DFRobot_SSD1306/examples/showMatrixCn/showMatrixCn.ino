#include <MPython.h>


// 主程序开始
void setup() {
  mPython.begin();
  Serial.begin(9600);
}
void loop() {
  Serial.println("hello");
  display.point(0, 0);
  delay(3000);
  display.fillScreen(0);
  delay(3000);
}
