#include <USB.h>
#include <USBHIDKeyboard.h>
#include "src/cmd_open.h"
#include "src/command.h"

USBHIDKeyboard Keyboard;

void setup() {
  Serial.begin(115200);
  
  USB.begin();
  Keyboard.begin(KeyboardLayout_fr_FR);

  openCmd();
  printCmd();
}

void loop() {
}