#include "OperateLiftFromInput.h"

OperateLiftFromInput::OperateLiftFromInput()
{
	Requires(CommandBase::pLiftMechanism.get());
}

// Called just before this Command runs the first time
void OperateLiftFromInput::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void OperateLiftFromInput::Execute()
{
	float speed = CommandBase::oi->GetStickyShoot()->GetRawAxis(5);
	CommandBase::pLiftMechanism->SetRopeSpeed(speed > 0 ? -speed : 0.0f);
	CommandBase::pLiftMechanism->SetTapeSpeed(speed < 0 ? speed : 0.0f);

//	if (speed > 0)
//	{
//		CommandBase::pLiftMechanism->SetRopeSpeed(-speed);
//	}
//	else if (speed < 0)
//	{
//		CommandBase::pLiftMechanism->SetTapeSpeed(speed);
//	}
//	else
//	{
//
//	}
}

// Make this return true when this Command no longer needs to run execute()
bool OperateLiftFromInput::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void OperateLiftFromInput::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OperateLiftFromInput::Interrupted()
{

}
