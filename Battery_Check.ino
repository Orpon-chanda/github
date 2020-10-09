void battery_check() {
  while (digitalRead(button) == HIGH) {
    int val = 0;
    Serial.println(val);
    val = map(analogRead(15), 730, 1023, 0, 100);
    lcd.setCursor(2, 0);
    lcd.print("Battery Check");
    lcd.setCursor(7, 1);
    lcd.print(val);
    lcd.print("%");
    delay(200);
    lcd_check();   
  }
  while (digitalRead(button) == LOW);
}
