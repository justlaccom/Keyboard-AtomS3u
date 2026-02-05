#ifndef LED_MANAGER_H
#define LED_MANAGER_H

#include <M5AtomS3.h>

class LedManager {
private:
  unsigned long ledEndTime = 0;
  bool isLedActive = false;

public:
  void init() {
    AtomS3.dis.setBrightness(100);
  }

  void setColor(uint32_t color) {
    AtomS3.dis.drawpix(color);
    AtomS3.update();
  }

  void setRed() {
    setColor(0xff0000);
  }

  void setBlue() {
    setColor(0x0000ff);
  }

  void setGreen() {
    setColor(0x00ff00);
  }

  void setOff() {
    setColor(0x000000);
  }

  void setGreenFor3Seconds() {
    setGreen();
    ledEndTime = millis() + 3000;
    isLedActive = true;
  }

  void update() {
    if (isLedActive && millis() > ledEndTime) {
      setOff();
      isLedActive = false;
    }
  }

  bool isActive() {
    return isLedActive;
  }
};

#endif
