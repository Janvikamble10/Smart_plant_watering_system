const int sensorPin = A0;
const int relayPin = 8;

const int DRY_THRESHOLD = 200;
const int WET_THRESHOLD = 450;

bool wateringNeeded = false;

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);   // pump OFF initially
  Serial.begin(9600);
}

void loop() {
  int moistureValue = analogRead(sensorPin);

  if (moistureValue < DRY_THRESHOLD) {
    wateringNeeded = true;
  } 
  else if (moistureValue > WET_THRESHOLD) {
    wateringNeeded = false;
  }

  if (wateringNeeded) {
    digitalWrite(relayPin, HIGH);  // pump ON
  } else {
    digitalWrite(relayPin, LOW);   // pump OFF
  }

  Serial.print("Moisture: ");
  Serial.print(moistureValue);
  Serial.print(" | Pump: ");
  Serial.println(wateringNeeded ? "ON" : "OFF");

  delay(2000);
}
