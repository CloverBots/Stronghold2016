#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:

	const int m_CAMERA_X_RES = 320;
	const int m_CAMERA_Y_RES = 240;

	std::shared_ptr<NetworkTable> m_pContoursTable;

	std::shared_ptr<USBCamera> m_pUSBCamera;

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

	int GetCameraXRes() const;
	int GetCameraYRes() const;
};

#endif
