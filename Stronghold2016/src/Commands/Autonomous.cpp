#include "Autonomous.h"
#include "DriveStraightFromPresets.h"
#include "FuncCommand.h"

Autonomous::Autonomous()
{
	Requires(CommandBase::pPIDWesternDrive.get());

	AddSequential(new DriveStraightFromPresets(2.0f));
}
