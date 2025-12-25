#include "SensorService.h"

SensorReading readTemperature() {
  return { random(200, 280) / 10.0f, "C" };
}

SensorReading readPh() {
  return { random(65, 75) / 10.0f, "pH" };
}

SensorReading readWaterLevel() {
  return { random(0, 100), "%" };
}