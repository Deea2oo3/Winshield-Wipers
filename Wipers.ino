int red = 7;
int yellow = 8;
int green = 9;
int white = 10;

int servo1 = 5;
int servo2 = 6;

void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(white, OUTPUT);

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
    pwmServo(servo1, 1200);
    pwmServo(servo2, 1200);
    delay(20);
  }

  delay(2000);

}


// Semnal PWM manual pentru servomotor
void pwmServo(int pin, int pulseWidthMicros) {
  digitalWrite(pin, HIGH);
  delayMicroseconds(pulseWidthMicros);
  digitalWrite(pin, LOW);
  delay(20 - (pulseWidthMicros / 1000));
}
