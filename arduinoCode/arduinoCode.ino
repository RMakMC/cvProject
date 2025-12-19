bool i;
bool on;
unsigned long m1;
unsigned long m2;
unsigned long m0;
void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    int rec = Serial.read();
    if (rec == 49) { // 1
      Serial.println("1p");
      i = 1;
      m0 = millis();
    }
    if (rec == 48) { // 0
      Serial.println("0p");
      i = 0;
      m1 = millis();
    }
  }
  if (i == 0 and millis() - m1 > 3000 and on == 1) {
    on = 0;
    Serial.println("off");
    digitalWrite(2, 0);
  }
  if (i == 1 and  millis() - m0 > 500 and on == 0) {
    on = 1;
    Serial.println("on");
    digitalWrite(2, 1);
  }
}
