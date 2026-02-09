// Smart Night Lamp
// Arduino Uno + LDR Module (DO) + Transistor + LED

const int ldrDO = 2;     // Digital output from LDR module
const int transistorPin = 9;  // Controls transistor base

void setup() {
  pinMode(ldrDO, INPUT);
  pinMode(transistorPin, OUTPUT);
}

void loop() {
  int lightState = digitalRead(ldrDO);

  // Most LDR modules output LOW when it's dark
  if (lightState == LOW) {
    digitalWrite(transistorPin, LOW);   // Dark -> LED ON
  } else {
    digitalWrite(transistorPin, HIGH);    // Bright -> LED OFF
  }

  delay(50); // Small delay for stability
}
