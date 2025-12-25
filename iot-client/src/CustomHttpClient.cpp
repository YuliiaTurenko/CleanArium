#include "CustomHttpClient.h"
#include "config.h"
#include <HTTPClient.h>
// #include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>

void sendSensorData(const SensorReading& reading) {
  HTTPClient http;
  // WiFiClient client;
  WiFiClientSecure client;
  client.setInsecure();

  String url = String(BASE_URL) + "/api/Device/" + DEVICE_ID + "/sensor-data";
  http.begin(client, url);
  http.addHeader("Content-Type", "application/json");

  StaticJsonDocument<128> doc;
  doc["value"] = reading.value;
  doc["unit"] = reading.unit;

  String body;
  serializeJson(doc, body);
  int code = http.POST(body);

  Serial.println("POST sensor data: " + String(code));

  http.end();
}

void sendExecutedCommand(int commandType, int status) {
  HTTPClient http;
  // WiFiClient client;
  WiFiClientSecure client;
  client.setInsecure();

  String url = String(BASE_URL) + "/api/Device/" + DEVICE_ID + "/executed-commands";
  http.begin(client, url);
  http.addHeader("Content-Type", "application/json");

  StaticJsonDocument<128> doc;
  doc["commandType"] = commandType;
  doc["commandStatus"] = status;

  String body;
  serializeJson(doc, body);
  int code = http.POST(body);

  Serial.println("POST executed command: " + String(code));

  http.end();
}

String fetchCommands() {
  HTTPClient http;
  // WiFiClient client;
  WiFiClientSecure client;
  client.setInsecure();

  String url = String(BASE_URL) + "/api/Device/executed-commands-by-device/" + DEVICE_ID;
  http.begin(client, url);
  int code = http.GET();
  Serial.println("GET commands code: " + String(code));

  String payload = "";
  if (code == 200) {
    payload = http.getString();
  }

  http.end();
  return payload;
}
