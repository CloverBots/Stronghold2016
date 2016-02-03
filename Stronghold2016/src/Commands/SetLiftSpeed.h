#ifndef LiftFromInput_H
#define LiftFromInput_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetLiftSpeed: public CommandBase
{
private:

	float m_speed;

public:

	SetLiftSpeed(float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
