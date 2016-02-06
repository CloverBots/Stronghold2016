#ifndef SetShooterSpeed_H
#define SetShooterSpeed_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetShooterSpeed: public CommandBase
{
private:

	float m_speed;

public:

	SetShooterSpeed(float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

};

#endif
