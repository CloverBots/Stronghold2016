#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	std::shared_ptr<NetworkTable> m_pContoursTable;

	std::shared_ptr<Joystick> m_pStickyDrive;
	std::shared_ptr<Joystick> m_pStickyShoot;

	std::shared_ptr<JoystickButton> m_pBackButton;
	std::shared_ptr<JoystickButton> m_pStartButton;
	std::shared_ptr<JoystickButton> m_pAButton;
	std::shared_ptr<JoystickButton> m_pBButton;
	std::shared_ptr<JoystickButton> m_pXButton;
	std::shared_ptr<JoystickButton> m_pYButton;

public:
	OI();
	std::vector<double> GetContourValue(std::string value);
	std::shared_ptr<Joystick> GetStickyDrive();
	std::shared_ptr<Joystick> GetStickyShoot();
};

#endif
