#include "PIDWesternDrive.h"
#include "../RobotMap.h"
#include "../Commands/DriveFromInput.h"

PIDWesternDrive::PIDWesternDrive() :
		Subsystem("PIDWesternDrive")
{
	m_pFrontLeftTalon.reset(new Talon(RobotMap::DRIVE_FRONT_LEFT_MOTOR));
	m_pRearLeftTalon.reset(new Talon(RobotMap::DRIVE_REAR_LEFT_MOTOR));
	m_pFrontRightTalon.reset(new Talon(RobotMap::DRIVE_FRONT_RIGHT_MOTOR));
	m_pRearRightTalon.reset(new Talon(RobotMap::DRIVE_REAR_RIGHT_MOTOR));

	m_pLeftEncoder.reset(new Encoder(RobotMap::DRIVE_LEFT_ENCODER_A, RobotMap::DRIVE_LEFT_ENCODER_B,
			false, Encoder::EncodingType::k4X));
	m_pLeftEncoder->SetDistancePerPulse(m_DISTANCE_PER_PULSE);

	m_pRightEncoder.reset(new Encoder(RobotMap::DRIVE_RIGHT_ENCODER_A, RobotMap::DRIVE_RIGHT_ENCODER_B,
			false, Encoder::EncodingType::k4X));
	m_pRightEncoder->SetDistancePerPulse(m_DISTANCE_PER_PULSE);

	m_pLeftPIDOutput.reset(new MultiPIDOutput());
	m_pLeftPIDOutput->AddTalon(m_pFrontLeftTalon.get());
	m_pLeftPIDOutput->AddTalon(m_pRearLeftTalon.get());

	m_pRightPIDOutput.reset(new MultiPIDOutput());
	m_pRightPIDOutput->AddTalon(m_pFrontRightTalon.get());
	m_pRightPIDOutput->AddTalon(m_pRearRightTalon.get());

	m_pLeftController.reset(new PIDController(m_P, m_I, m_D, m_pLeftEncoder.get(), m_pLeftPIDOutput.get()));
	m_pLeftController->SetContinuous(false);

	m_pRightController.reset(new PIDController(m_P, m_I, m_D, m_pRightEncoder.get(), m_pRightPIDOutput.get()));
	m_pRightController->SetContinuous(false);

	ChangeDriveState(NO_PID);
}

void PIDWesternDrive::InitDefaultCommand()
{
	SetDefaultCommand(new DriveFromInput());
}

void PIDWesternDrive::ChangeDriveState(DriveState driveState)
{
	if (m_currentState == driveState)
		return;

	switch (driveState)
	{
	case UNINITIALIZED:
		std::cout << "Cannot change DriveState to default \"UNINITIALIZED\"\n";
		break;
	case NO_PID:
		m_pLeftEncoder->Reset();
		m_pRightEncoder->Reset();

		m_pLeftController->Disable();
		m_pRightController->Disable();
		break;
	case PID_RATE:
		m_pLeftEncoder->SetPIDSourceType(PIDSourceType::kRate);
		m_pRightEncoder->SetPIDSourceType(PIDSourceType::kRate);

		m_pLeftEncoder->Reset();
		m_pRightEncoder->Reset();

		m_pLeftController->Enable();
		m_pRightController->Enable();

		m_pLeftController->SetSetpoint(0.0f);
		m_pRightController->SetSetpoint(0.0f);
		break;
	case PID_DISPLACEMENT:
		m_pLeftEncoder->SetPIDSourceType(PIDSourceType::kDisplacement);
		m_pRightEncoder->SetPIDSourceType(PIDSourceType::kDisplacement);

		m_pLeftEncoder->Reset();
		m_pRightEncoder->Reset();

		m_pLeftController->Enable();
		m_pRightController->Enable();

		m_pLeftController->SetSetpoint(0.0f);
		m_pRightController->SetSetpoint(0.0f);
		break;
	}

	m_currentState = driveState;
}

void PIDWesternDrive::DisablePID()
{
	ChangeDriveState(NO_PID);
}

void PIDWesternDrive::SetSpeed(float speed, float rotation)
{
	ChangeDriveState(NO_PID);

	m_pFrontLeftTalon->Set(-speed + rotation);
	m_pRearLeftTalon->Set(-speed + rotation);

	m_pFrontRightTalon->Set(speed + rotation);
	m_pRearRightTalon->Set(speed + rotation);

	SmartDashboard::PutNumber("Right Encoder", m_pRightEncoder->Get());
	SmartDashboard::PutNumber("Left Encoder", m_pLeftEncoder->Get());

	SmartDashboard::PutNumber("Speed", speed);
	SmartDashboard::PutNumber("Rotation", rotation);
}

void PIDWesternDrive::DriveForDistance(float distanceInFeet)
{
	ChangeDriveState(PID_DISPLACEMENT);

	float setpoint = m_WHEEL_CIRCUMFERENCE * (distanceInFeet / 12.0f);

	m_pLeftController->SetSetpoint(setpoint);
	m_pRightController->SetSetpoint(-setpoint);
}

void PIDWesternDrive::TurnAngle(float angle)
{
	ChangeDriveState(PID_DISPLACEMENT);

	float setpoint = (m_ROBOT_CIRCUMFERENCE / m_WHEEL_CIRCUMFERENCE) * (angle / m_ENCODER_RATE);

	m_pLeftController->SetSetpoint(setpoint);
	m_pRightController->SetSetpoint(-setpoint);
}
