#include "OperateArmFromInput.h"

OperateArmFromInput::OperateArmFromInput()
{
	Requires(CommandBase::pArm.get());
}

// Called just before this Command runs the first time
void OperateArmFromInput::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void OperateArmFromInput::Execute()
{
	CommandBase::pArm->SetLiftSpeed(CommandBase::oi->GetStickyShoot()->GetRawAxis(1));
	CommandBase::pArm->SetCollectSpeed(2.0f *
			(CommandBase::oi->GetStickyShoot()->GetRawAxis(3) -
			CommandBase::oi->GetStickyShoot()->GetRawAxis(2)));
}

// Make this return true when this Command no longer needs to run execute()
bool OperateArmFromInput::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void OperateArmFromInput::End()
{
	CommandBase::pArm->SetLiftSpeed(0.0f);
	CommandBase::pArm->SetCollectSpeed(0.0f);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OperateArmFromInput::Interrupted()
{

}
