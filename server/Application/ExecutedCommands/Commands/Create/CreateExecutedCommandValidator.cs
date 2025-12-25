using FluentValidation;

namespace Application.ExecutedCommands.Commands.Create;

public class CreateExecutedCommandValidator : AbstractValidator<CreateExecutedCommand>
{
    public CreateExecutedCommandValidator()
    {
        RuleFor(x => x.DeviceId).GreaterThan(0);
        RuleFor(x => x.CommandType).IsInEnum();
        RuleFor(x => x.CommandStatus).IsInEnum();
    }
}