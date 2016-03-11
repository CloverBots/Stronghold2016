#ifndef DriveFromPresets_H
#define DriveFromPresets_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveStraightFromPresets: public CommandBase
{
private:

	float m_distanceInFeet;

public:
	DriveStraightFromPresets(float distanceInFeet);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
