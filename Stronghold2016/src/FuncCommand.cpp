#include "FuncCommand.h"

//template<typename T>
//FuncCommand<T>::FuncCommand(std::function<void(T)> func, T param)
//	: m_func(func), m_param(param)
//{
//}

//template<typename T>
//FuncCommand<T>::FuncCommand(std::function<void(T)> func, T param, std::shared_ptr<Subsystem> subsystems...)
//	: FuncCommand<T>(func, param)
//{
//	for (std::shared_ptr<Subsystem> pSubsystem : subsystems)
//		Requires(pSubsystem.get());
//}

// Called just before this Command runs the first time
template<typename T>
void FuncCommand<T>::Initialize()
{
	m_func(m_param);
}

// Called repeatedly when this Command is scheduled to run
template<typename T>
void FuncCommand<T>::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
template<typename T>
bool FuncCommand<T>::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
template<typename T>
void FuncCommand<T>::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
template<typename T>
void FuncCommand<T>::Interrupted()
{
}
