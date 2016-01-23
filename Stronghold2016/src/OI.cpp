#include "OI.h"

OI::OI()
{
	m_pContoursTable = NetworkTable::GetTable("GRIP/myContoursReport");
}

std::vector<double> OI::getContourValue(std::string value)
{
	return m_pContoursTable->GetNumberArray(value, llvm::ArrayRef<double>());
}
