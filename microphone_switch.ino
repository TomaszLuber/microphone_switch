int status = 0;

void setup() {
  pinMode(7,INPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int read = digitalRead(7);
  Serial.println(read);
  int prev = status;
  if (read == HIGH) {
    if (status == 1) {
      status = 0;
    } else if (status == 0) {
      status = 1;
    }
  }
  if (prev != status) {
    updateLED();
  }
}

void updateLED() {
  if (status == 1) {
    digitalWrite(13,HIGH);
  } else if (status == 0) {
    digitalWrite(13, LOW);
  }
  delay(1000);
}
