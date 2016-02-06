#include "Arm.h"
#include "../RobotMap.h"
#include "../Commands/OperateArmFromInput.h"

Arm::Arm() :
		Subsystem("ExampleSubsystem")
{
	m_pLiftEncoder.reset(new Encoder(RobotMap::ARM_ENCODER_A, RobotMap::ARM_ENCODER_B));
	m_pLiftEncoder->SetPIDSourceType(PIDSourceType::kRate);

	m_pLiftTalon.reset(new Talon(RobotMap::ARM_LIFT_MOTOR));
	m_pCollectTalon.reset(new Talon(RobotMap::ARM_COLLECT_MOTOR));

	m_pPIDController.reset(new PIDController(m_P, m_I, m_D, m_pLiftEncoder.get(), m_pLiftTalon.get()));
}

void Arm::InitDefaultCommand()
{
	SetDefaultCommand(new OperateArmFromInput());
}

void Arm::SetEnabled(bool enabled)
{
	if (enabled)
	{
		m_pLiftEncoder->Reset();

		m_pPIDController->Enable();
		m_pPIDController->SetSetpoint(0.0f);
	}
	else
	{
		m_pPIDController->Reset();
	}
}

void Arm::SetLiftSpeed(float speed)
{
	m_pPIDController->SetSetpoint(speed);
}

void Arm::SetCollectSpeed(float speed)
{
	m_pCollectTalon->Set(speed);
}
