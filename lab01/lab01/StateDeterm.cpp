#include "StateDeterm.h"


CStateDeterm::CStateDeterm(const std::string & name)
	: m_name(name)
{
}

void CStateDeterm::SetPath(std::string toName, std::string inpState)
{
	to.emplace(toName, inpState);
}