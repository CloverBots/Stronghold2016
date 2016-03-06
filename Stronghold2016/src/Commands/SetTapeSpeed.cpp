#include <Commands/SetTapeSpeed.h>

SetTapeSpeed::SetTapeSpeed(float speed) : m_speed(speed)
{
	Requires(CommandBase::pLiftMechanism.get());
}

// Called just before this Command runs the first time
void SetTapeSpeed::Initialize()
{
	CommandBase::pLiftMechanism->SetTapeSpeed(m_speed);
	std::cout << "Set Tape speed: " << m_speed << std::endl;
}

// Called repeatedly when this Command is scheduled to run
void SetTapeSpeed::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool SetTapeSpeed::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetTapeSpeed::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetTapeSpeed::Interrupted()
{
}
