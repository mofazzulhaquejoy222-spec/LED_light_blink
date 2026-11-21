
int waterSensor = A0;

int greenLED = 2;
int yellowLED = 3;
int redLED = 4;

int waterValue = 0;

void setup() {
  Serial.begin(9600);

  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
}

void loop() {

  waterValue = analogRead(waterSensor);

  Serial.print("Water Level: ");
  Serial.println(waterValue);

  if (waterValue < 300) {
    // Low water level
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
  }

  else if (waterValue < 600) {
    // Medium water level
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);
  }

  else {
    // High water level
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);
  }

  delay(500);
}
