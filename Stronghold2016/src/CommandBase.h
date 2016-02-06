#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <string>
#include "Commands/Command.h"
#include "Subsystems/PIDWesternDrive.h"
#include "Subsystems/LiftMechanism.h"
#include "Subsystems/Arm.h"
#include "OI.h"
#include "WPILib.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command
{
public:
	CommandBase(const std::string &name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static std::unique_ptr<PIDWesternDrive> pPIDWesternDrive;
	static std::unique_ptr<LiftMechanism> pLiftMechanism;
	static std::unique_ptr<Arm> pArm;

	static std::unique_ptr<OI> oi;
};

#endif
