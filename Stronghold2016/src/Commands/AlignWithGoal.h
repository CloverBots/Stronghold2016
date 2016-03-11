#ifndef AlignWithGoal_H
#define AlignWithGoal_H

#include "../CommandBase.h"
#include "WPILib.h"

class AlignWithGoal: public CommandBase
{
private:

	const float m_MAGNIFICATION = 75.0f;
	const float m_SPEED_CAP = 0.5f;

public:

	AlignWithGoal();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
