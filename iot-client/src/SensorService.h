#pragma once
#include <Arduino.h>

struct SensorReading {
  float value;
  const char* unit;
};

SensorReading readTemperature();
SensorReading readPh();
SensorReading readWaterLevel();