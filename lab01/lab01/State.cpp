#include "State.h"





CState::CState(const std::string & name)
	: m_name(name)
{
}

void CState::SetPath(std::string toName, std::string out)
{
	to.emplace(toName, out);
}

CState::~CState()
{
}
