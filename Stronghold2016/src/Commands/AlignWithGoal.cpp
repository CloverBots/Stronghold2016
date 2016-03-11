#include "AlignWithGoal.h"

AlignWithGoal::AlignWithGoal()
{
	Requires(CommandBase::pPIDWesternDrive.get());
}

// Called just before this Command runs the first time
void AlignWithGoal::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void AlignWithGoal::Execute()
{
	std::vector<double> centerXValues = CommandBase::oi->GetContourValue("centerX");

	if (centerXValues.size() == 0)
	{
		CommandBase::pPIDWesternDrive->SetSpeed(0.0f, 0.0f);
	}
	else
	{
		int apparentCenter = centerXValues.front();

		for (unsigned int i = 1; i < centerXValues.size(); i++)
		{
			int currentCenter = centerXValues[i];

			if (std::fabs(currentCenter) < std::fabs(apparentCenter))
				apparentCenter = currentCenter;
		}

		std::cout << "Apparent Center: " << apparentCenter << std::endl;

		double realCenter = CommandBase::oi->GetCameraXRes() / 2 - apparentCenter;
		std::cout << "Real Center: " << realCenter << std::endl;

		CommandBase::pPIDWesternDrive->SetSpeed(0.0f,
				std::fmin(m_SPEED_CAP,
				std::fmax(-m_SPEED_CAP,
				-realCenter / CommandBase::oi->GetCameraXRes() / 2 * m_MAGNIFICATION)));
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AlignWithGoal::IsFinished()
{
	return !CommandBase::oi->GetStickyShoot()->GetRawButton(3);
}

// Called once after isFinished returns true
void AlignWithGoal::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AlignWithGoal::Interrupted()
{

}
