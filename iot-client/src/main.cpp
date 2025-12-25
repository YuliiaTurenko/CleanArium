#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "config.h"
#include "WiFiManager.h"
#include "SensorService.h"
#include "CustomHttpClient.h"
#include "CommandProcessor.h"

#define LAMP_PIN 2

void initLamp() {
  pinMode(LAMP_PIN, OUTPUT);
  digitalWrite(LAMP_PIN, LOW);
}

void lampOn() {
  digitalWrite(LAMP_PIN, HIGH);
}

void lampOff() {
  digitalWrite(LAMP_PIN, LOW);
}

void lampBlink(int durationMs = 2500) {
  lampOn();
  delay(durationMs);
  lampOff();
}

unsigned long lastSensor = 0;
unsigned long lastCommands = 0;

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("ESP32 started");

  initLamp();
  connectWiFi();
}

void loop() {
  Serial.println("Loop running...");

  unsigned long now = millis();

  if (now - lastSensor > SENSOR_INTERVAL_MS) {
    sendSensorData(readTemperature());
    // sendSensorData(readPh());
    // sendSensorData(readWaterLevel());
    lastSensor = now;
  }

  if (now - lastCommands > COMMAND_INTERVAL_MS) {
    String cmds = fetchCommands();
    lampBlink();
    processCommands(cmds);
    lastCommands = now;
  }

  delay(5000);
}