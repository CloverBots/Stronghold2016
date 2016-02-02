#include "DriveFromInput.h"
#include "CommandBase.h"

DriveFromInput::DriveFromInput()
{
	Requires(CommandBase::pPIDWesternDrive.get());
}

// Called just before this Command runs the first time
void DriveFromInput::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void DriveFromInput::Execute()
{
	CommandBase::pPIDWesternDrive->SetSpeed(CommandBase::oi->GetStickyDrive()->GetRawAxis(1),
			CommandBase::oi->GetStickyDrive()->GetRawAxis(4));
}

// Make this return true when this Command no longer needs to run execute()
bool DriveFromInput::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveFromInput::End()
{
	CommandBase::pPIDWesternDrive->SetSpeed(0.0f, 0.0f);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveFromInput::Interrupted()
{
}
