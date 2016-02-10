#include "PIDWesternDrive.h"
#include "../RobotMap.h"
#include "../Commands/DriveFromInput.h"

PIDWesternDrive::PIDWesternDrive() :
		Subsystem("ExampleSubsystem")
{
	m_pLeftEncoder.reset(new Encoder(RobotMap::DRIVE_LEFT_ENCODER_A, RobotMap::DRIVE_LEFT_ENCODER_B,
			false, Encoder::EncodingType::k4X));
	m_pLeftEncoder->SetPIDSourceType(PIDSourceType::kRate);
	m_pLeftEncoder->SetDistancePerPulse(m_DISTANCE_PER_PULSE);

	m_pRightEncoder.reset(new Encoder(RobotMap::DRIVE_RIGHT_ENCODER_A, RobotMap::DRIVE_RIGHT_ENCODER_B,
			false, Encoder::EncodingType::k4X));
	m_pRightEncoder->SetPIDSourceType(PIDSourceType::kRate);
	m_pRightEncoder->SetDistancePerPulse(m_DISTANCE_PER_PULSE);

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

void PIDWesternDrive::SetSpeed(float speed, float rotation)
{
	if (m_pLeftEncoder->GetPIDSourceType() == PIDSourceType::kDisplacement)
		m_pLeftEncoder->SetPIDSourceType(PIDSourceType::kRate);

	if (m_pRightEncoder->GetPIDSourceType() == PIDSourceType::kDisplacement)
		m_pRightEncoder->SetPIDSourceType(PIDSourceType::kRate);

	m_pRightController->SetSetpoint(speed + rotation);
	m_pLeftController->SetSetpoint(speed - rotation);
}

void PIDWesternDrive::DriveForDistance(float distanceInFeet)
{
	if (m_pLeftEncoder->GetPIDSourceType() == PIDSourceType::kRate)
		m_pLeftEncoder->SetPIDSourceType(PIDSourceType::kDisplacement);

	if (m_pRightEncoder->GetPIDSourceType() == PIDSourceType::kRate)
		m_pRightEncoder->SetPIDSourceType(PIDSourceType::kDisplacement);

	float setpoint = m_WHEEL_CIRCUMFERENCE * (distanceInFeet / 12.0f);

	m_pLeftController->SetSetpoint(setpoint);
	m_pRightController->SetSetpoint(setpoint);
}

void PIDWesternDrive::TurnAngle(float angle)
{
	if (m_pLeftEncoder->GetPIDSourceType() == PIDSourceType::kRate)
		m_pLeftEncoder->SetPIDSourceType(PIDSourceType::kDisplacement);

	if (m_pRightEncoder->GetPIDSourceType() == PIDSourceType::kRate)
		m_pRightEncoder->SetPIDSourceType(PIDSourceType::kDisplacement);

	float setpoint = (m_ROBOT_CIRCUMFERENCE / m_WHEEL_CIRCUMFERENCE) * (angle / 360.0f);

	m_pLeftController->SetSetpoint(setpoint);
	m_pRightController->SetSetpoint(-setpoint);
}
