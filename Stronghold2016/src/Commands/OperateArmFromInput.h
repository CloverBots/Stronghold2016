#ifndef OperateArmFromInput_H
#define OperateArmFromInput_H

#include "../CommandBase.h"
#include "WPILib.h"

class OperateArmFromInput: public CommandBase
{
public:
	OperateArmFromInput();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
