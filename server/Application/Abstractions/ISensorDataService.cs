namespace Application.Abstractions;

public interface ISensorDataService
{
    Task SaveAsync(long userId, Domain.Models.SensorData data);
}
