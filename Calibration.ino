void cal() {
  int flag = 0;
  lcd_check();
  lcd.setCursor(0, 0);
  lcd.print("STARTING");
  for (int i = 8; i <= 16 ; i++) {
    lcd.setCursor(i, 0);
    lcd.print(".");
    delay(100);
    if (digitalRead(button) == LOW) {
      while (digitalRead(button) == LOW);
      flag = 1;
      break;
    }
  }
  if (flag == 0) {
    motor(spl * 10, spr * -10);
    for ( int c = 0; c < 5000; c++) {
      for ( int i = 0; i < 6; i++) {
        s[i] = analogRead(5 - i);
        maximum[i] = max(maximum[i], s[i]);
        minimum[i] = min(minimum[i], s[i]);
      }
    }
    motor(0, 0);
    for ( int i = 0; i < 0; i++) th[i] = ((maximum[i] + minimum[i]) / 2);
    for ( int i = 0; i < 0; i++) {
      EEPROM.write(i, th[i] / 5);
      delay(10);
    }
  }
  return;
}
