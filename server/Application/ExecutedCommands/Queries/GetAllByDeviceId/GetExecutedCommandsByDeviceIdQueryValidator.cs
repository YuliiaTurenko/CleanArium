using Application.Abstractions;
using Application.ScheduledCommands.Queries.GetAllByDeviceId;
using FluentValidation;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Application.ExecutedCommands.Queries.GetAllByDeviceId;

public class GetExecutedCommandsByDeviceIdQueryValidator : AbstractValidator<GetExecutedCommandsByDeviceIdQuery>
{
    private readonly IDeviceRepository _deviceRepo;

    public GetExecutedCommandsByDeviceIdQueryValidator(IDeviceRepository deviceRepo)
    {
        _deviceRepo = deviceRepo;

        RuleFor(x => x.DeviceId).NotEmpty().GreaterThan(0)
            .WithMessage("Device id is required to get executed commands.");

        RuleFor(x => x)
            .MustAsync(DeviceExists).WithMessage("Device not found.")
            .MustAsync(UserOwnsDevice).WithMessage("User doesn't own this device.");
    }

    private async Task<bool> DeviceExists(GetExecutedCommandsByDeviceIdQuery cmd, CancellationToken ct)
    {
        return await _deviceRepo.ExistsByIdAsync(cmd.DeviceId, ct);
    }

    private async Task<bool> UserOwnsDevice(GetExecutedCommandsByDeviceIdQuery cmd, CancellationToken ct)
    {
        return await _deviceRepo.UserOwnsDeviceAsync(cmd.UserId, cmd.DeviceId, ct);
    }
}