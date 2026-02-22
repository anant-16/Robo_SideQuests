#define trigPin 9
#define echoPin 10
#define buzzerPin 7

int leds[] = {2, 3, 4, 5, 6};
long duration;
int distance;

void setup() {
  // Set LED pins as output
  for(int i = 0; i < 5; i++){
    pinMode(leds[i], OUTPUT);
  }

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

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

  // Convert to distance (cm)
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  // Turn off all LEDs first
  for(int i = 0; i < 5; i++){
    digitalWrite(leds[i], LOW);
  }

  digitalWrite(buzzerPin, LOW); // default OFF

  // Distance conditions
  if(distance > 20){
    digitalWrite(leds[0], HIGH);
  }
  else if(distance > 15){
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[1], HIGH);
    digitalWrite(buzzerPin, 200);
    delay(1000);
    digitalWrite(buzzerPin, LOW);
  }
  else if(distance > 10){
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[1], HIGH);
    digitalWrite(leds[2], HIGH);
    digitalWrite(buzzerPin, 200);
    delay(500);
    digitalWrite(buzzerPin, LOW);
  }
  else if(distance > 5){
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[1], HIGH);
    digitalWrite(leds[2], HIGH);
    digitalWrite(leds[3], HIGH);
    digitalWrite(buzzerPin, 200);
    delay(200);
    digitalWrite(buzzerPin, LOW);
  }
  else{
    for(int i = 0; i < 5; i++){
      digitalWrite(leds[i], HIGH);
    }
    digitalWrite(buzzerPin, 200);
    delay(50);
    digitalWrite(buzzerPin, LOW);
  }

  delay(200);
}