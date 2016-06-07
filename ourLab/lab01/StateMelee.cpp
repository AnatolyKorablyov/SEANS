#include "StateMelee.h"

CStateMelee::CStateMelee(const std::string & name)
	: m_name(name)
{
}
void CStateMelee::SetPath(std::string inpSym, std::string toName, std::string out)
{
	to.emplace(inpSym, std::make_pair(toName, out));
}

