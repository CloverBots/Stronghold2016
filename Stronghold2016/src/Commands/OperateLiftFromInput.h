#ifndef OperateLiftFromInput_H
#define OperateLiftFromInput_H

#include "../CommandBase.h"
#include "WPILib.h"

class OperateLiftFromInput: public CommandBase
{
public:
	OperateLiftFromInput();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
