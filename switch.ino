int switch1 () {
  int t = 0, cl = 0, list = 8;
a:  while (digitalRead(button) == LOW) {
    delay(1);
    digitalWrite(mli, HIGH);
    t++;
  }
  digitalWrite(mli, LOW);

  while (t > 15) {
    if (cl != menu) {
      cl = menu;
      if (cl == 1) {
        lcd_check();
        lcd.setCursor(2, 0);
        lcd.print("Line Follwer");
        lcd.setCursor(0, 1);
        lcd.print("C:");
        lcd.setCursor(4, 1);
        lcd.print(counter);
        lcd.setCursor(10, 1);
        lcd.print("O:");
        lcd.setCursor(14, 1);
        lcd.print(object_number);
      }
      else if (cl == 2)  {
        lcd_check();
        lcd.setCursor(2, 0);
        lcd.print("Calibration");
      }
      else if (cl == 3) {
        lcd.setCursor(2, 0);
        lcd.print("Analog Read");
      }
      else if (cl == 4) {
        lcd_check();
        lcd.setCursor(6, 0);
        lcd.print("Grab");
      }
      else if (cl == 5) {
        lcd_check();
        lcd.setCursor(5, 0);
        lcd.print("Release");
      }
      else if (cl == 6) {
        lcd_check();
        lcd.setCursor(1, 0);
        lcd.print("Robot Position");
      }
      else if (cl == 7) {
        lcd_check();
        lcd.setCursor(5, 0);
        lcd.print("SONAR");
      }
      else if (cl == 8) {
        lcd_check();
        lcd.setCursor(1, 0);
        lcd.print("BATTERY CHECK");
      }
    }
    if (digitalRead(button2) == LOW) {
      if (menu < list) menu++;
      while (digitalRead(button2) == LOW);

    }
    else if (digitalRead(button1) == LOW) {
      if (menu > 1) menu--;
      while (digitalRead(button1) == LOW);
    }

    else if (digitalRead(button) == LOW) {
      t = 0;
      while (digitalRead(button) == LOW) {
        delay(1);
        t++;
        if (t > 500) {
          digitalWrite(mli, 1);
          digitalWrite(lli, 1);
          while (digitalRead(button) == LOW);
          digitalWrite(mli, 0);
          digitalWrite(lli, 0);
          return list+1;
        }
      }
      return cl;

    }
  }


  return cl;
}

int switch2 () {
  int t = 0, cl = 0;
a:  while (digitalRead(button1) == LOW) {
    delay(1);
    digitalWrite(rli, HIGH);
    t++;
  }
  digitalWrite(rli, LOW);

  if (t > 15) {
    cl ++;
    t = 0;
    while (digitalRead(button1) == HIGH) {
      delay(1);
      t++;
      if (t > 500) {
        digitalWrite(mli, 1);
        digitalWrite(lli, 1);
        delay(250);
        digitalWrite(mli, 0);
        digitalWrite(lli, 0);
        return cl ;
      }
    }
    goto a;
  }

  return cl;
}

int switch3 () {
  int t = 0, cl = 0;
a:  while (digitalRead(button2) == LOW) {
    delay(1);
    digitalWrite(lli, HIGH);
    t++;
  }
  digitalWrite(lli, LOW);

  if (t > 15) {
    cl ++;
    t = 0;
    while (digitalRead(button2) == HIGH) {
      delay(1);
      t++;
      if (t > 500) {
        digitalWrite(mli, 1);
        digitalWrite(lli, 1);
        delay(250);
        digitalWrite(mli, 0);
        digitalWrite(lli, 0);
        return cl ;
      }
    }
    goto a;
  }

  return cl;
}
