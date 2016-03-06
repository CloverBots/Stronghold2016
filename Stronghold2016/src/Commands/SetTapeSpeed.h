#ifndef LiftFromInput_H
#define LiftFromInput_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetTapeSpeed: public CommandBase
{
private:

	float m_speed;

public:

	SetTapeSpeed(float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
