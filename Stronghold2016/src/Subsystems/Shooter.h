#ifndef Shooter_H
#define Shooter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Shooter: public Subsystem
{
private:

	std::unique_ptr<Talon> m_pTalon;

public:
	Shooter();
	void InitDefaultCommand();

	void SetSpeed(float speed);
};

#endif
