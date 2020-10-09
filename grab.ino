void grab() {
  motor(-10 * spl, -10 * spr);
  delay(50);
  motor(0, 0);
  servo1.write(drop_position);
  delay(500);
  servo2.write(grab_position);
  delay(500);
  servo1.write(lift_position);
  delay(500);
  grabber = 1;
  counter = 0;
  sonarf = 0;
  
}
//
void release_hand(int a) {
//  delay(a);
  motor(-10 * spl, -10 * spr);
  delay(50);
  motor(-10 * spl, 10 * spr);
  delay(200);
  motor(10 * spl, -10 * spr);
  delay(10);
  motor(10 * spl, 10 * spr);
  delay(a);
  motor(-10 * spl, -10 * spr);
  delay(20);
  motor(0, 0);
  servo1.write(drop_position);
  delay(500);
  servo2.write(release_position);
  delay(500);
  servo1.write(lift_position);
  delay(500);
  motor(-10 * spl, -10 * spr);
  delay(a);
  motor(10 * spl, -10 * spr);
  check();
  while (s[2] == 0 && s[3] == 0)check();
  grabber = 0;
  counter = 0;
  object_number++;
}




//
//void special_release(int a) {
//  delay(a);
//  motor(-10 * spl, -10 * spr);
//  delay(50);
//  motor(0, 0);
//  servo1.write(drop_position);
//  delay(500);
//  servo2.write(release_position);
//  delay(500);
//  servo1.write(lift_position);
//  delay(500);
//
//  motor(-10 * spl, -10 * spr);
//  delay(350);
//  motor(10 * spl, 10 * spr);
//  delay(20);
//  grabber = 0;
//  counter = 0;
//  object_number++;
//}
