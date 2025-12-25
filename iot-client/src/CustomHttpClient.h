#pragma once
#include "SensorService.h"

void sendSensorData(const SensorReading& reading);
void sendExecutedCommand(int commandType, int status);
String fetchCommands();