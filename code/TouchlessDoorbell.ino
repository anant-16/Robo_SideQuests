#define trigPin 9
#define echoPin 10
#define buzzer 6

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo time
  duration = pulseIn(echoPin, HIGH);

  // Convert to distance in cm
  distance = duration * 0.034 / 2;

  Serial.println(distance);

  // Trigger buzzer if hand is close
  if (distance > 0 && distance < 8) {
    tone(buzzer, 1000);  // 1kHz tone
  } else {
    noTone(buzzer);
  }

  delay(100);
}
