#include "Shooter.h"
#include "../RobotMap.h"

Shooter::Shooter() :
		Subsystem("ExampleSubsystem")
{
	m_pTalon.reset(new Talon(RobotMap::SHOOT_MOTOR));
}

void Shooter::InitDefaultCommand()
{
}

void Shooter::SetSpeed(float speed)
{
	m_pTalon->Set(speed);
}
