#include <Commands/SetTapeSpeed.h>
#include "LiftMechanism.h"
#include "../RobotMap.h"
#include "../Commands/OperateLiftFromInput.h"

LiftMechanism::LiftMechanism() :
	Subsystem("ExampleSubsystem")
{
	m_pTapeTalon.reset(new CANTalon(RobotMap::LIFT_TAPE_MOTOR));
	m_pTapeTalon->SetPID(m_TAPE_P, m_TAPE_I, m_TAPE_D);
	m_pTapeTalon->SetSafetyEnabled(false);

	m_pRopeTalon.reset(new CANTalon(RobotMap::LIFT_ROPE_MOTOR));
	m_pRopeTalon->SetPID(m_ROPE_P, m_ROPE_I, m_ROPE_D);
	m_pRopeTalon->SetSafetyEnabled(false);
}

void LiftMechanism::InitDefaultCommand()
{
	SetDefaultCommand(new OperateLiftFromInput());
}

void LiftMechanism::SetTapeSpeed(double speed)
{
	double setPoint = speed;
	m_pTapeTalon->SetSetpoint(setPoint);
	SmartDashboard::PutNumber("Tape SetPoint", setPoint);
}

void LiftMechanism::SetRopeSpeed(double speed)
{
	double setPoint = speed;
	m_pRopeTalon->SetSetpoint(setPoint);
	SmartDashboard::PutNumber("Rope SetPoint", setPoint);
}
