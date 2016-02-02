#include "OI.h"

OI::OI()
{
	m_pContoursTable = NetworkTable::GetTable("GRIP/myContoursReport");
	m_pStickyDrive = std::make_shared<Joystick>(0);
}

std::vector<double> OI::GetContourValue(std::string value)
{
	return m_pContoursTable->GetNumberArray(value, llvm::ArrayRef<double>());
}

std::shared_ptr<Joystick> OI::GetStickyDrive()
{
	return m_pStickyDrive;
}
