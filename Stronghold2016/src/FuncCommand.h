#ifndef FuncCommand_H
#define FuncCommand_H

#include "CommandBase.h"
#include "WPILib.h"

template <typename T>
class FuncCommand: public CommandBase
{
private:

	std::function<void(T)> m_func;
	T m_param;

public:

	FuncCommand(std::function<void(T)> func, T param) : m_func(func), m_param(param) { }
	FuncCommand(std::function<void(T)> func, T param, std::initializer_list<std::shared_ptr<Subsystem>> subsystems)
		: FuncCommand(func, param)
	{
		for (std::shared_ptr<Subsystem> pSubsystem : subsystems)
				Requires(pSubsystem.get());
	}
	FuncCommand(std::function<void(T)> func, T param, std::shared_ptr<Subsystem> pSubsystem)
		: FuncCommand(func, param, {pSubsystem}) { }
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();


};

#endif
