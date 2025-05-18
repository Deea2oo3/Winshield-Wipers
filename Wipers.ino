void setup() {
  Serial.begin(9600);
  delay(20);
}

void loop() {
  
  int rain = analogRead(A0);
  int light = analogRead(A1);

  Serial.println(rain);
  Serial.println(light)
  delay(2000);

}

