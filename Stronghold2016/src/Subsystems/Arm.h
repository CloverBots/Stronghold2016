#ifndef Arm_H
#define Arm_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Arm: public Subsystem
{
private:

	const float m_P = 1.0f;
	const float m_I = 0.0f;
	const float m_D = 0.0f;

	const float m_SPEED_MAG = 0.25f;

	const double m_DISTANCE_PER_PULSE = 0.001;

	std::unique_ptr<Encoder> m_pLiftEncoder;

	std::unique_ptr<Talon> m_pLiftTalon;
	std::unique_ptr<Talon> m_pCollectTalon;

	std::unique_ptr<PIDController> m_pPIDController;

public:

	Arm();
	void InitDefaultCommand();

	void SetEnabled(bool enabled);
	void SetLiftSpeed(float speed);
	void SetCollectSpeed(float speed);

};

#endif
