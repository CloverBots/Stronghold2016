#include <Commands/SetLiftSpeed.h>

SetLiftSpeed::SetLiftSpeed(float speed) : m_speed(speed)
{
	Requires(CommandBase::pLiftMechanism.get());
}

// Called just before this Command runs the first time
void SetLiftSpeed::Initialize()
{
	CommandBase::pLiftMechanism->SetSpeed(m_speed);
}

// Called repeatedly when this Command is scheduled to run
void SetLiftSpeed::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool SetLiftSpeed::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetLiftSpeed::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetLiftSpeed::Interrupted()
{
}
