#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	std::shared_ptr<NetworkTable> m_pContoursTable;
public:
	OI();
	std::vector<double> getContourValue(std::string value);
};

#endif
