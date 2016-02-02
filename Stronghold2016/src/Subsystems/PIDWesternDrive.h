#ifndef PIDWesternDrive_H
#define PIDWesternDrive_H

#include "Commands/Subsystem.h"
#include "../MultiPIDOutput.h"
#include "WPILib.h"

class PIDWesternDrive: public Subsystem
{
private:

	const float m_P = 0.5f;
	const float m_I = 0.5f;
	const float m_D = 0.0f;

	std::unique_ptr<Encoder> m_pLeftEncoder;
	std::unique_ptr<Encoder> m_pRightEncoder;

	std::unique_ptr<MultiPIDOutput> m_pLeftPIDOutput;
	std::unique_ptr<MultiPIDOutput> m_pRightPIDOutput;

	std::unique_ptr<PIDController> m_pLeftController;
	std::unique_ptr<PIDController> m_pRightController;

public:

	PIDWesternDrive();
	void InitDefaultCommand();

	void SetEnabled(bool enabled);
	void SetSpeed(float speed, float angle);

};

#endif