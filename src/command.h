#ifndef COMMAND_H
#define COMMAND_H

extern USBHIDKeyboard Keyboard;

void printCmd() {
  Keyboard.println("color a");
  delay(500);
  Keyboard.println("curl ascii.live/rick");
}

#endif