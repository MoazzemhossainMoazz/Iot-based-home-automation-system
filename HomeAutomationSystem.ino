#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Replace with your network credentials
char auth[] = "9PGEuxzC4Z12rbbe6kvybJzFyogJMvJe";
char ssid[] = "NotFound";
char pass[] = "sixarmy0123";

// Pin mapping
#define BUZZER_PIN D1
#define LIGHT_1_PIN D2
#define LIGHT_2_PIN D4

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LIGHT_1_PIN, OUTPUT);
  pinMode(LIGHT_2_PIN, OUTPUT);

  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(LIGHT_1_PIN, LOW);
  digitalWrite(LIGHT_2_PIN, LOW);
}

BLYNK_WRITE(V2) {
  int buzzerState = param.asInt();
  digitalWrite(BUZZER_PIN, buzzerState);
}

BLYNK_WRITE(V0) {
  int light1State = param.asInt();
  digitalWrite(LIGHT_1_PIN, light1State);
}

BLYNK_WRITE(V1) {
  int light2State = param.asInt();
  digitalWrite(LIGHT_2_PIN, light2State);
}

void loop() {
  Blynk.run();
}