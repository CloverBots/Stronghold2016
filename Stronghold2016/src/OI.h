#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	std::shared_ptr<NetworkTable> m_pContoursTable;
	std::shared_ptr<Joystick> m_pStickyDrive;
public:
	OI();
	std::vector<double> GetContourValue(std::string value);
	std::shared_ptr<Joystick> GetStickyDrive();
};

#endif
