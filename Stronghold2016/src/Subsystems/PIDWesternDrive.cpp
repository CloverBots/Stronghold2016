#include "PIDWesternDrive.h"
#include "../RobotMap.h"
#include "../Commands/DriveFromInput.h"

PIDWesternDrive::PIDWesternDrive() :
		Subsystem("ExampleSubsystem")
{
	m_pLeftEncoder.reset(new Encoder(RobotMap::DRIVE_LEFT_ENCODER_A, RobotMap::DRIVE_LEFT_ENCODER_B, false, Encoder::EncodingType::k4X));
	m_pLeftEncoder->SetPIDSourceType(PIDSourceType::kRate);

	m_pRightEncoder.reset(new Encoder(RobotMap::DRIVE_RIGHT_ENCODER_A, RobotMap::DRIVE_RIGHT_ENCODER_B, false, Encoder::EncodingType::k4X));
	m_pRightEncoder->SetPIDSourceType(PIDSourceType::kRate);

	m_pLeftPIDOutput.reset(new MultiPIDOutput());
	m_pLeftPIDOutput->AddTalon(RobotMap::DRIVE_FRONT_LEFT_MOTOR);
	m_pLeftPIDOutput->AddTalon(RobotMap::DRIVE_REAR_LEFT_MOTOR);

	m_pRightPIDOutput.reset(new MultiPIDOutput());
	m_pRightPIDOutput->AddTalon(RobotMap::DRIVE_FRONT_RIGHT_MOTOR);
	m_pRightPIDOutput->AddTalon(RobotMap::DRIVE_REAR_RIGHT_MOTOR);

	m_pLeftController.reset(new PIDController(m_P, m_I, m_D, m_pLeftEncoder.get(), m_pLeftPIDOutput.get()));
	m_pRightController.reset(new PIDController(m_P, m_I, m_D, m_pRightEncoder.get(), m_pRightPIDOutput.get()));
}

void PIDWesternDrive::InitDefaultCommand()
{
	SetDefaultCommand(new DriveFromInput());
}

void PIDWesternDrive::SetEnabled(bool enabled)
{
	if (enabled)
	{
		m_pLeftEncoder->Reset();
		m_pRightEncoder->Reset();

		m_pLeftController->Enable();
		m_pLeftController->SetSetpoint(0.0f);

		m_pRightController->Enable();
		m_pRightController->SetSetpoint(0.0f);
	}
	else
	{
		m_pLeftController->Reset();
		m_pRightController->Reset();
	}
}

void PIDWesternDrive::SetSpeed(float speed, float angle)
{
	m_pRightController->SetSetpoint(speed + angle);
	m_pLeftController->SetSetpoint(speed - angle);
}
