int red = 7;
int yellow = 8;
int green = 9;
int white = 10;

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

  Serial.println(rain);
  Serial.println(light);
  delay(2000);

}
