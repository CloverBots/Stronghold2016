#ifndef PIDWesternDrive_H
#define PIDWesternDrive_H

#include "Commands/Subsystem.h"
#include "../MultiPIDOutput.h"
#include "WPILib.h"

class PIDWesternDrive: public Subsystem
{
private:

	enum DriveState
	{
		UNINITIALIZED = 0,
		NO_PID = 1,
		PID_RATE = 2,
		PID_DISPLACEMENT = 3
	} m_currentState = UNINITIALIZED;

	const float m_P = 1.0f;
	const float m_I = 0.0f;
	const float m_D = 1.5f;

	const double m_ENCODER_RATE = 3600;
	const double m_DISTANCE_PER_PULSE = 1.0 / m_ENCODER_RATE;
	const float m_WHEEL_CIRCUMFERENCE = M_PI * 7.75;
	const float m_ROBOT_CIRCUMFERENCE = M_PI * 20.8f;

	std::unique_ptr<Talon> m_pFrontLeftTalon;
	std::unique_ptr<Talon> m_pRearLeftTalon;
	std::unique_ptr<Talon> m_pFrontRightTalon;
	std::unique_ptr<Talon> m_pRearRightTalon;

	std::unique_ptr<Encoder> m_pLeftEncoder;
	std::unique_ptr<Encoder> m_pRightEncoder;

	std::unique_ptr<MultiPIDOutput> m_pLeftPIDOutput;
	std::unique_ptr<MultiPIDOutput> m_pRightPIDOutput;

	std::unique_ptr<PIDController> m_pLeftController;
	std::unique_ptr<PIDController> m_pRightController;

public:

	PIDWesternDrive();
	void InitDefaultCommand();

	void ChangeDriveState(DriveState driveState);

	void DisablePID();
	void SetSpeed(float speed, float rotation);
	void DriveForDistance(float distanceInFeet);
	void TurnAngle(float angle);

	//bool SetpointAqcuired();

};

#endif
