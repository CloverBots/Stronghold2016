#ifndef FuncCommand_H
#define FuncCommand_H

#include "CommandBase.h"
#include "WPILib.h"

class FuncCommand: public CommandBase
{
private:
	std::function<void(void*)> m_func;
	void* m_pParam;
public:
	FuncCommand(std::shared_ptr<Subsystem> pSubsystem, std::function<void(void*)> func, void* pParam);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
