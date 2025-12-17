int i;
int on;
unsigned long m1;
unsigned long m2;
void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    int rec = Serial.read();
    Serial.println(rec);
    if (rec == 49) {
      m2 = millis();
      Serial.println("1");
      i = 1;
    }
    if (rec == 48) {
      m2 = millis();
      Serial.println("0");
      i = 0;
    }
    if (m1 < 4000 or m2 - m1 >= 3000) {
      on = i;
      Serial.println(i);
      m1 = m2;
    }

  }
      if(millis() - m1 > 5000){
      on = i;
      m1 = m2;
      
    }
  digitalWrite(2, on);
  m1 = m2;
}
