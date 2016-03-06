#include "SetRopeSpeed.h"

SetRopeSpeed::SetRopeSpeed(float speed)
	: m_speed(speed)
{
	Requires(CommandBase::pLiftMechanism.get());
}

// Called just before this Command runs the first time
void SetRopeSpeed::Initialize()
{
	CommandBase::pLiftMechanism->SetRopeSpeed(m_speed);
	std::cout << "Set Rope speed: " << m_speed << std::endl;
}

// Called repeatedly when this Command is scheduled to run
void SetRopeSpeed::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool SetRopeSpeed::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetRopeSpeed::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetRopeSpeed::Interrupted()
{

}
