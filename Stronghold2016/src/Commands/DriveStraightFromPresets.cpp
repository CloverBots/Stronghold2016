#include <Commands/DriveStraightFromPresets.h>

DriveStraightFromPresets::DriveStraightFromPresets(float distanceInFeet)
	: m_distanceInFeet(distanceInFeet)
{
	Requires(CommandBase::pPIDWesternDrive.get());
}

// Called just before this Command runs the first time
void DriveStraightFromPresets::Initialize()
{
	CommandBase::pPIDWesternDrive->DriveForDistance(m_distanceInFeet);
}

// Called repeatedly when this Command is scheduled to run
void DriveStraightFromPresets::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraightFromPresets::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void DriveStraightFromPresets::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraightFromPresets::Interrupted()
{

}
