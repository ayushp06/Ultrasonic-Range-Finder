const int TRIGGER_PIN = 10;
const int ECHO_PIN = 11;
const int LED1_PIN = 6;
const int LED2_PIN = 5;
const int LED3_PIN = 4;
const int LED4_PIN = 3;

void setup() {
  
  Serial.begin(9600);

  pinMode(TRIGGER_PIN, OUTPUT);

  pinMode(ECHO_PIN, INPUT);

  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(LED4_PIN, OUTPUT);
}

void loop() {

  long duration;
  long distanceCm;

  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);

  distanceCm = microsecondsToCentimeters(duration);

  updateLEDs(distanceCm);

  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");

  delay(100);
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}

void updateLEDs(long distance) {

  if (distance <= 20) {
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, HIGH);
    digitalWrite(LED3_PIN, HIGH);
    digitalWrite(LED4_PIN, HIGH);
  }
  
  else if (distance <= 40) {
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, HIGH);
    digitalWrite(LED3_PIN, HIGH);
    digitalWrite(LED4_PIN, LOW);
  }

  else if (distance <= 60) {
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, HIGH);
    digitalWrite(LED3_PIN, LOW);
    digitalWrite(LED4_PIN, LOW);
  }

  else if (distance <= 80) {
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, LOW);
    digitalWrite(LED3_PIN, LOW);
    digitalWrite(LED4_PIN, LOW);
  }

  else {
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
    digitalWrite(LED3_PIN, LOW);
    digitalWrite(LED4_PIN, LOW);
  }
}