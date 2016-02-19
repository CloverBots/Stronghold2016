#include <Commands/SetLiftSpeed.h>
#include "LiftMechanism.h"
#include "../RobotMap.h"

LiftMechanism::LiftMechanism() :
		Subsystem("ExampleSubsystem")
{
	m_pTapeTalon.reset(new CANTalon(RobotMap::LIFT_TAPE_MOTOR));
	m_pTapeTalon->SetControlMode(CANTalon::ControlMode::kSpeed);
	m_pTapeTalon->SetPID(m_TAPE_P, m_TAPE_I, m_TAPE_D);

	m_pRopeTalon.reset(new CANTalon(RobotMap::LIFT_ROPE_MOTOR));
	m_pRopeTalon->SetControlMode(CANTalon::ControlMode::kSpeed);
	m_pRopeTalon->SetPID(m_ROPE_P, m_ROPE_I, m_ROPE_D);
}

void LiftMechanism::InitDefaultCommand()
{
}

void LiftMechanism::SetTapeSpeed(double speed)
{
	m_pTapeTalon->Set(speed);
}

void LiftMechanism::SetRopeSpeed(double speed)
{
	m_pRopeTalon->Set(speed);
}
