#ifndef SetRopeSpeed_H
#define SetRopeSpeed_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetRopeSpeed: public CommandBase
{
private:

	float m_speed;

public:

	SetRopeSpeed(float speed);

	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
