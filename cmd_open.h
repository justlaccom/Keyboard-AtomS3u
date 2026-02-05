void openCmd() {
  delay(5000);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(500);
  
  Keyboard.print("cmd");
  delay(500);
  
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(3000);

  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('o'); 
  Keyboard.releaseAll();
  delay(2000); 
}