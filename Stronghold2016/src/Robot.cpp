#include "WPILib.h"
#include "FuncCommand.h"
#include "Commands/Command.h"
#include "CommandBase.h"

class Robot : public IterativeRobot
{
private:

	std::unique_ptr<Command> autonomousCommand;
	std::unique_ptr<SendableChooser> chooser;

	void RobotInit()
	{
		CommandBase::init();
		chooser = std::make_unique<SendableChooser>();
		SmartDashboard::PutData("Autonomous Modes", chooser.get());
	}

	void DisabledInit()
	{
		CommandBase::pPIDWesternDrive->DisablePID();
		//CommandBase::pPIDWesternDrive->SetEnabled(false);
		CommandBase::pArm->SetEnabled(false);
	}

	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		//CommandBase::pPIDWesternDrive->SetEnabled(true);
		CommandBase::pArm->SetEnabled(true);
		/* std::string autoSelected = SmartDashboard::GetString("Auto Selector", "Default");
		if(autoSelected == "My Auto") {
			autonomousCommand.reset(new MyAutoCommand());
		} else {
			autonomousCommand.reset(new ExampleCommand());
		} */

		autonomousCommand.reset((Command *)chooser->GetSelected());

		if (autonomousCommand)
			autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		//CommandBase::pPIDWesternDrive->SetEnabled(true);
		CommandBase::pArm->SetEnabled(true);

		if (autonomousCommand)
			autonomousCommand->Cancel();
	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TestPeriodic()
	{
		LiveWindow::GetInstance()->Run();
	}
};

START_ROBOT_CLASS(Robot)

