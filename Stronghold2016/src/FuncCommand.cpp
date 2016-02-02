#include "FuncCommand.h"

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
