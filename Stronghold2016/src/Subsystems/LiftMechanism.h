#ifndef LiftMechanism_H
#define LiftMechanism_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class LiftMechanism: public Subsystem
{
private:

	const double m_TAPE_P = 1.0;
	const double m_TAPE_I = 0.0;
	const double m_TAPE_D = 0.0;

	const double m_ROPE_P = 1.0;
	const double m_ROPE_I = 0.0;
	const double m_ROPE_D = 0.0;

	std::unique_ptr<CANTalon> m_pTapeTalon;
	std::unique_ptr<CANTalon> m_pRopeTalon;

public:
	LiftMechanism();
	void InitDefaultCommand();

	void SetTapeSpeed(double speed);
	void SetRopeSpeed(double speed);
};

#endif
