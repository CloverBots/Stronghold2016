#ifndef LiftMechanism_H
#define LiftMechanism_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class LiftMechanism: public Subsystem
{
private:

	std::unique_ptr<Talon> m_pTalon;

public:
	LiftMechanism();
	void InitDefaultCommand();

	void SetSpeed(float speed);
};

#endif
