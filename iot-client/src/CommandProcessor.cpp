#include "CommandProcessor.h"
#include "CustomHttpClient.h"
#include <ArduinoJson.h>

bool lampState = false;

void processCommands(const String& json) {
  if (json.length() == 0) return;

  StaticJsonDocument<512> doc;
  deserializeJson(doc, json);

  for (JsonObject cmd : doc.as<JsonArray>()) {
    int commandType = cmd["commandType"];

    switch (commandType) {
      case 1:
        lampState = true;
        Serial.println("Turn ON");
        break;
      case 2:
        lampState = false;
        Serial.println("Turn OFF");
        break;
      case 3:
        Serial.println("SetValue executed");
        break;
      case 4:
        Serial.println("Calibration done");
        break;
    }

    sendExecutedCommand(commandType, 1); // Success
  }
}
