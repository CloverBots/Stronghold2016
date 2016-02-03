#include "OI.h"
#include "Commands/SetLiftSpeed.h"

OI::OI()
{
	m_pContoursTable = NetworkTable::GetTable("GRIP/myContoursReport");

	m_pStickyDrive.reset(new Joystick(0));
	m_pStickyShoot.reset(new Joystick(1));

	m_pStartButton.reset(new JoystickButton(m_pStickyShoot.get(), 8));
	m_pBackButton.reset(new JoystickButton(m_pStickyShoot.get(), 7));

	m_pStartButton->WhenPressed(new SetLiftSpeed(-1.0f));
	m_pStartButton->WhenReleased(new SetLiftSpeed(0.0f));

	m_pBackButton->WhenPressed(new SetLiftSpeed(1.0f));
	m_pBackButton->WhenReleased(new SetLiftSpeed(0.0f));
}

std::vector<double> OI::GetContourValue(std::string value)
{
	return m_pContoursTable->GetNumberArray(value, llvm::ArrayRef<double>());
}

std::shared_ptr<Joystick> OI::GetStickyDrive()
{
	return m_pStickyDrive;
}
