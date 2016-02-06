#include "CommandBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
std::unique_ptr<PIDWesternDrive> CommandBase::pPIDWesternDrive;
std::unique_ptr<LiftMechanism> CommandBase::pLiftMechanism;
std::unique_ptr<Arm> CommandBase::pArm;
std::unique_ptr<Shooter> CommandBase::pShooter;
std::unique_ptr<OI> CommandBase::oi;

CommandBase::CommandBase(const std::string &name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{
}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	pPIDWesternDrive.reset(new PIDWesternDrive());
	pLiftMechanism.reset(new LiftMechanism());
	pArm.reset(new Arm());
	pShooter.reset(new Shooter());

	oi.reset(new OI());
}
