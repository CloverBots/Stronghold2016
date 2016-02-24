#include "SetShooterSpeed.h"

SetShooterSpeed::SetShooterSpeed(float speed) : m_speed(speed)
{
	Requires(CommandBase::pShooter.get());
}

// Called just before this Command runs the first time
void SetShooterSpeed::Initialize()
{
	CommandBase::pShooter->SetSpeed(m_speed);
//	std::cout << "Speed: " << m_speed << std::endl;
}

// Called repeatedly when this Command is scheduled to run
void SetShooterSpeed::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool SetShooterSpeed::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetShooterSpeed::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetShooterSpeed::Interrupted()
{
}
