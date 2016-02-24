#include "Shooter.h"
#include "../RobotMap.h"

Shooter::Shooter() :
		Subsystem("ExampleSubsystem")
{
	m_pLeftTalon.reset(new Talon(RobotMap::SHOOT_LEFT_MOTOR));
	m_pRightTalon.reset(new Talon(RobotMap::SHOOT_RIGHT_MOTOR));
}

void Shooter::InitDefaultCommand()
{
}

void Shooter::SetSpeed(float speed)
{
	m_pLeftTalon->Set(speed);
	m_pRightTalon->Set(-speed);
}
