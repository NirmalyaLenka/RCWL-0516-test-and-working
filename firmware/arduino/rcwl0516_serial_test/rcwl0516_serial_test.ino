/*
  RCWL-0516 + Arduino Uno digital motion test
  Wiring:
    RCWL-0516 VIN -> Arduino 5V
    RCWL-0516 GND -> Arduino GND
    RCWL-0516 OUT -> Arduino D2
    RCWL-0516 CDS -> leave unconnected for the basic test

  Serial Monitor: 115200 baud
*/

const byte RADAR_PIN = 2;
int previousState = LOW;
unsigned long eventCount = 0;

void setup() {
  Serial.begin(115200);
  pinMode(RADAR_PIN, INPUT);

  Serial.println();
  Serial.println(F("RCWL-0516 Arduino test"));
  Serial.println(F("Move across the sensor's field of view."));
}

void loop() {
  const int state = digitalRead(RADAR_PIN);

  if (state != previousState) {
    if (state == HIGH) {
      ++eventCount;
      Serial.print(F("MOTION DETECTED | event #"));
      Serial.println(eventCount);
    } else {
      Serial.println(F("Output returned LOW"));
    }

    previousState = state;
  }

  delay(10);
}