#ifndef Arm_H
#define Arm_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Arm: public Subsystem
{
private:

	const float m_P = 0.5f;
	const float m_I = 0.5f;
	const float m_D = 0.0f;

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
