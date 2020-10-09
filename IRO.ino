#include<EEPROM.h>
#include <Servo.h>
#include <NewPing.h>
#include <LiquidCrystal.h>
int menu = 1;



int a[]= {1,3};                                                  //.........Are...........



int s[6];
int binary[] = {1, 2, 4, 8, 16, 32};
int data, sum;
int th[6] = {300, 300, 300, 300, 300, 300};
int dt = 30;
int lcd_cursor1[6] = {0, 5, 10, 0, 5, 10};
int lcd_cursor2[6] = {0, 0, 0, 1, 1, 1};
int lmf = 5, lmb = 6, lme = 7, rme = 2, rmf = 3, rmb = 4;
int spl = 25, spr = 21;
int turn = 0, cross = 0, k = 0 , m = 0;
long int mi1, mi2, mi3, mi4, mi5, mi6;
int rli = 23;
int mli = 22;
int lli = 24;
int button = 25;
int button1 = 37;
int button2 = 49;
int timer = 0;
int maximum [] = {0, 0, 0, 0, 0, 0};
int minimum [] = {1024, 1024, 1024, 1024, 1024, 1024};
int r;
const int tri  = 26;
const int echo = 27;
int i;
int sonarf;
int grabber = 0;
int counter = 0;
int t_count = 0;
int object_number = 0;
int grab_position = 88;
int release_position = 150;
int lift_position = 37;
int drop_position = 58;


const float referenceVolts = 5.0;            // the default reference on a 5 volt board
const int batteryPin = 0;                   // +V from battery is connected to analog pin 0
float battv;

const int rs = 28, en = 30, d4 = 29, d5 = 31, d6 = 33, d7 = 35;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

long duration;
int distance;
Servo servo1;
Servo servo2;
NewPing sonar(tri, echo, 100);
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  servo1.attach(9);
  servo2.attach(10);
  pinMode(button, INPUT_PULLUP);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(lmf, OUTPUT);
  pinMode(lmb, OUTPUT);
  pinMode(lme, OUTPUT);
  pinMode(rme, OUTPUT);
  pinMode(rmf, OUTPUT);
  pinMode(rmb, OUTPUT);
  pinMode(rli, OUTPUT);
  pinMode(lli, OUTPUT);
  pinMode(mli, OUTPUT);

//  for (int i = 0; i < 6; i++) th[i] = EEPROM.read(i) * 5;
  counter = EEPROM.read(8);
  object_number = EEPROM.read(7);
  servo1.write(lift_position);
  servo2.write(release_position);

  lcd_check();
  lcd.setCursor(5, 0);
  lcd.print("**SPI**");
  lcd.setCursor(2, 1);
  lcd.print("#Frequnce#");

}

void loop() {
  check();
  debug();

  int r = switch1();
  if (r != 0) {
    if (r == 1) line_follow();
    else if (r == 2) cal();
    else if (r == 3) analog_read();
    else if (r == 4) {
      servo1.write(drop_position);
      delay(500);
      servo2.write(grab_position);
      delay(500);
      servo1.write(lift_position);
      delay(500);
    }
    else if (r == 5) {
      servo1.write(drop_position);
      delay(500);
      servo2.write(release_position);
      delay(500);
      servo1.write(lift_position);
      delay(500);
    }
    else if (r == 6) motor(10 * spl, 10 * spr);
    else if (r == 7) sonar_read();
    else if (r == 8) battery_check();
    lcd_check();
    lcd.setCursor(5, 0);
    lcd.print("**SPI**");
    lcd.setCursor(2, 1);
    lcd.print("#Frequnce#");
  }


  r = switch2();
  if (r != 0) {
    counter = r - 1;
    EEPROM.write(8, counter);
  }

  r = switch3();
  if (r != 0) {
    object_number = r - 1;
    EEPROM.write(7, object_number);
  }
  check();
  debug();
}
