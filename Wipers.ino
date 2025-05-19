#include <LiquidCrystal.h>

const int rs = 13, en = 11, d4= 12, d5= 3, d6= 2, d7= 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int red = 7;
int yellow = 8;
int green = 9;
int white = 10;

int servo1 = 5;
int servo2 = 6;

unsigned long totalWiperTime = 0;
unsigned long wiperStartTime = 0;
bool wiperActive = false;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(white, OUTPUT);

  pinMode(servo1, OUTPUT);
  pinMode(servo2, OUTPUT);
  delay(20);
}

void loop() {
  digitalWrite(white, HIGH);

  int rain = analogRead(A0);
  int light = analogRead(A1);

  // LED-uri
  if (rain > 950 && light < 250) {
    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
  } else if (rain < 950 && light < 250) {
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    digitalWrite(red, LOW);
  } else if (light > 250) {
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
  }

  // Daca ploua si parbrizul e curat:
  if (rain < 950 && light < 250) {
    if (!wiperActive) {
      wiperStartTime = millis();
      wiperActive = true;
    }

    int times;
    if (rain > 800) {
      times = 1200;
    } else if (rain > 500) {
      times = 600;
    } else {
      times = 200;
    }

    pwmServo(servo1, 600);
    pwmServo(servo2, 600);
    delay(300);

    pwmServo(servo1, 1200);
    pwmServo(servo2, 1200);
    delay(times);

  } else {
    
    if (wiperActive) {
      totalWiperTime += millis() - wiperStartTime;
      wiperActive = false;
    }

    pwmServo(servo1, 1200);
    pwmServo(servo2, 1200);
    delay(20);
  }

  lcd.clear();
  lcd.print(totalWiperTime/1000);
  delay(2000);

}


// Semnal PWM manual pentru servomotor
void pwmServo(int pin, int pulseWidthMicros) {
  digitalWrite(pin, HIGH);
  delayMicroseconds(pulseWidthMicros);
  digitalWrite(pin, LOW);
  delay(20 - (pulseWidthMicros / 1000));
}
