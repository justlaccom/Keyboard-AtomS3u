#include <USB.h>
#include <USBHIDKeyboard.h>
#include <M5AtomS3.h>
#include "../src/cmd_open.h"
#include "../src/command.h"
#include "../src/led_manager.h"

USBHIDKeyboard Keyboard;
LedManager ledManager;
bool isRunning = false;

void setup() {
  Serial.begin(115200);
  
  AtomS3.begin(true);
  ledManager.init();
  
  USB.begin();
  Keyboard.begin(KeyboardLayout_fr_FR);
  
  ledManager.setRed();
}

void loop() {
  AtomS3.update();
  ledManager.update();
  
  if (AtomS3.BtnA.wasPressed() && !isRunning) {
    isRunning = true;
    
    ledManager.setBlue();
    
    openCmd();
    printCmd();
    
    ledManager.setGreenFor3Seconds();
    isRunning = false;
  }
}