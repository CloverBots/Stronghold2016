#include <Commands/SetLiftSpeed.h>
#include "LiftMechanism.h"
#include "../RobotMap.h"

LiftMechanism::LiftMechanism() :
		Subsystem("ExampleSubsystem")
{
	m_pTalon.reset(new Talon(RobotMap::LIFT_MOTOR));
}

void LiftMechanism::InitDefaultCommand()
{
}

void LiftMechanism::SetSpeed(float speed)
{
	m_pTalon->Set(speed);
}
