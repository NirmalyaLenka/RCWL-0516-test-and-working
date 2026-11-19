/*
  RCWL-0516 + ESP32 digital motion test
  Wiring:
    RCWL-0516 VIN -> 5V (or suitable regulated supply)
    RCWL-0516 GND -> ESP32 GND
    RCWL-0516 OUT -> ESP32 GPIO 27
    RCWL-0516 CDS -> leave unconnected for the basic test

  Serial Monitor: 115200 baud

  The sensor's OUT pin is a digital trigger, not a serial data interface.
*/

constexpr uint8_t RADAR_PIN = 27;
constexpr unsigned long REPORT_INTERVAL_MS = 100;
constexpr unsigned long EVENT_GUARD_MS = 250;

int previousState = LOW;
unsigned long lastReportMs = 0;
unsigned long lastEventMs = 0;
unsigned long eventCount = 0;

void setup() {
  Serial.begin(115200);
  pinMode(RADAR_PIN, INPUT);
  delay(300);

  Serial.println();
  Serial.println(F("RCWL-0516 ESP32 test"));
  Serial.println(F("Waiting for motion; move across the sensing area."));
  Serial.println(F("Expected OUT: LOW idle, HIGH during a trigger."));
}

void loop() {
  const unsigned long now = millis();
  const int state = digitalRead(RADAR_PIN);

  if (state != previousState) {
    if (state == HIGH && (now - lastEventMs >= EVENT_GUARD_MS)) {
      ++eventCount;
      lastEventMs = now;
      Serial.print(F("MOTION TRIGGER | event #"));
      Serial.println(eventCount);
    }

    Serial.print(F("OUT changed to "));
    Serial.println(state == HIGH ? F("HIGH") : F("LOW"));
    previousState = state;
  }

  if (now - lastReportMs >= REPORT_INTERVAL_MS) {
    lastReportMs = now;
    Serial.print(F("OUT="));
    Serial.print(state == HIGH ? F("HIGH") : F("LOW"));
    Serial.print(F(" | events="));
    Serial.println(eventCount);
  }
}