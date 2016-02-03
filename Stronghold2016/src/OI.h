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

public:
	OI();
	std::vector<double> GetContourValue(std::string value);
	std::shared_ptr<Joystick> GetStickyDrive();
};

#endif
