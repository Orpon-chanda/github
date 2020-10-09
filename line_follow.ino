void line_follow() {
  while (digitalRead(button) == HIGH) {
    check();

    if (sum == 0) {
      if (turn == 1) {
        turn = 0;
        delay(200);                                                    //.........Turn == 1, Delay().............
        digitalWrite(13, 1);
        //        motor(0 * spl, 0 * spr);
        //        delay(10);
        motor(10 * spl, -10 * spr);
        delay(10);
        while (s[2] == 0 && s[3] == 0) check();
        motor(-10 * spl, +10 * spr);
        delay(20);
        motor(10 * spl, 10 * spr);
        digitalWrite(13, 0);
      }
      else if (turn == 2) {
        turn = 0;
        delay(200);                                                    //..........Turn == 2, Delay()......
        digitalWrite(13, 1);
        //        motor(0 * spl, 0 * spr);
        //        delay(10);
        motor(-10 * spl, 10 * spr);
        delay(10);
        while (s[2] == 0 && s[3] == 0) check();
        motor(10 * spl, -10 * spr);
        delay(20);
        motor(10 * spl, 10 * spr);
        digitalWrite(13, 0);
      }

      else if (turn == 0) {
        mi1 = mi2 = millis();
        motor(10 * spl, 10 * spr);
        while (sum == 0) {
          check();
          mi2 = millis();
          if (mi2 - mi1 >= 300) {                                              //.............  Sum == 0,  Millis(); ............
            //            if (grabber == 1 && object_number == 0) special_release(300);
            motor(-10 * spl, 10 * spr);
            while (s[2] == 0 && s[3] == 0) check();
            motor(10 * spl, -10 * spr);
            delay(20);
            break;
          }
        }
      }

    } //sum == 0

    else if (sum == 1 || sum == 2) {                                                 //..............Sonar part..................
      if (grabber == 0) sonarf = sonar.ping_cm();
      if (sonarf < 6 && sonarf > 0) grab();
      if (cross == 1) {
        digitalWrite(rli, 0);
        digitalWrite(lli, 1);
        digitalWrite(mli, 1);
        cross = 0;
        motor(10 * spl, -10 * spr);
        while (s[0] == 1) check();
        while (s[0] == 0) check();
        while (s[2] == 0 && s[3] == 0) check();
        //        motor(-10 * spl, 10 * spr);
        //        delay(80);
        motor(10 * spl, 10 * spr);
        digitalWrite(rli, 0);
        digitalWrite(mli, 0);
        digitalWrite(lli, 0);
      }
      else if (cross == 2) {
        digitalWrite(rli, 0);
        digitalWrite(lli, 1);
        digitalWrite(mli, 1);
        cross = 0;
        motor(-10 * spl, 10 * spr);
        while (s[5] == 1) check();
        while (s[5] == 0) check();
        while (s[2] == 0 && s[3] == 0) check();
        //        motor(10 * spl, -10 * spr);
        //        delay(80);
        motor(10 * spl, 10 * spr);
        digitalWrite(rli, 0);
        digitalWrite(mli, 0);
        digitalWrite(lli, 0);
      }
                                                            //.........................Telateli......................//
      else if (data == 0b001100) {
        if (k > 0) {
          k = 0;
          motor (-10 * spl, 10 * spr);
          delay(dt);
        }
        else if (k < 0) {
          k = 0;
          motor (10 * spl, -10 * spr);
          delay(dt);
        }
        motor(10 * spl, 10 * spr);
      }

      else if (data == 0b001000) motor(7 * spl, 10 * spr);
      else if (data == 0b000100)  motor(10 * spl, 7 * spr);

                                                         //............................Left side
      else if (data == 0b011000) {
        motor(5 * spl, 10 * spr);
        //        k = -1;
      }
      else if (data == 0b010000) {
        k = -1;
        motor(0 * spl, 10 * spr);
      }
      else if (data == 0b110000) {
        k = -1;
        motor(-3 * spl, 10 * spr);
      }
      else if (data == 0b100000) {
        k = -1;
        motor(-5 * spl, 10 * spr);
      }

                                                                      //................Right side...........
      else if (data == 0b000110) {
        //        k = 1;
        motor(10 * spl, 5 * spr);
      }
      else if (data == 0b000010) {
        k = 1;
        motor(10 * spl, 0 * spr);
      }
      else if (data == 0b000011) {
        k = 1;
        motor(10 * spl, -3 * spr);
      }
      else if (data == 0b000001) {
        k = 1;
        motor(10 * spl, -5 * spr);
      }
    }//sum == 1

    else if (sum == 3 || sum == 4 || sum == 5) {                               //.............Right hand rule......
      if (data == 0b001111 || data == 0b000111 || data == 0b011111) {
        digitalWrite(rli, 1);
        turn = 1;
        mi1 = mi2 = millis();
        while (sum == 1 || sum == 2 || sum == 3 || sum == 4 || sum == 5) {
          check();
          mi2 = millis();
          if (mi2 - mi1 >= 300) {                                           //........... RIGHT SPECIAL  CASE.........
            if (a[i] == 0) cross = 0;
            else if (a[i] == 1) cross = 1;
            else if (a[i] == 2) cross = 2;
            i++;
            break;
          }
        }
      }  //data

                                                                                //...................Left hand rule..........
      else if (data == 0b111100 || data == 0b111110 || data == 0b111000) {
        turn = 2;
        digitalWrite(rli, 1);
        mi1 = mi2 = millis();
        while (sum == 5 || sum == 4 || sum == 3 || sum == 2 || sum == 1) {
          check();
          mi2 = millis();
          if (mi2 - mi1 >= 300) {                                           // .........LEFT SPECIAL  CASE...................

            if (a[i] == 0) cross = 0;
            else if (a[i] == 1) cross = 1;
            else if (a[i] == 2) cross = 2;
            i++;
            break;
          }
        }
      } //data
      digitalWrite(rli, 0);
      mi3 = millis();
    }   //sum = 3 || 4 || 5


    else if (sum == 6) {                                                          //..........Sum == 6............
      turn = 0;
      mi3 = millis();
      mi1 = mi2 = millis();
      digitalWrite(lli, 1);
      digitalWrite(mli, 1);
      while (1) {
        check();
        mi2 = millis();
        if (mi2 - mi1 >= 300) {                                                  // ........Sum == 6, Millis();........
          if (sum == 6) {
            motor(-10 * spl, -10 * spr);
            delay(50);
            motor(0, 0);
            while (sum == 6 && digitalRead(button) == HIGH) check();
            if (digitalRead(button) == HIGH) delay(500);
            break;
          }
          else if (sum != 6 && sum != 0) {                                      // .................counter cross................
            if (a[i] == 0) cross = 0;
            else if (a[i] == 1) cross = 1;
            else if (a[i] == 2) cross = 2;
            i++;
            break;
          }
          else if (sum == 0) {
            if (a[i] == 0) turn = 0;
            else if (a[i] == 1) turn = 1;
            else if (a[i] == 2) turn  = 2;
            i++;
            break;
          }
        }
      }   // while (1)
      digitalWrite(lli, 0);
      digitalWrite(mli, 0);
      mi3 = millis();
    } //sum == 6
    mi4 = millis();
    if (mi4 - mi3 > 500) {
      turn = 0;
    }
  }  //digitalRead(button) == HIGH
  
  motor(0, 0);
  while (digitalRead(button) == LOW);
  return;
} //line_follow
