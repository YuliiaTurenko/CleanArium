using MediatR;

namespace Application.SensorData.Commands.Create;

public record CreateSensorDataCommand(
    long UserId,
    long DeviceId,
    float Value,
    string Unit) : IRequest;
