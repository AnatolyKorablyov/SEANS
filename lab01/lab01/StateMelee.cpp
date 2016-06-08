#include "StateMelee.h"

CStateMelee::CStateMelee(const std::string & name)
	: m_name(name)
{
}
void CStateMelee::SetPath(std::string inpSym, std::string toName, std::string out)
{
	if (to.find(inpSym) != to.end())
	{
		toNoDeterm[inpSym].insert(toName);
		noDeterm = true;
	}
	else
	{
		to.emplace(inpSym, std::make_pair(toName, out));
		toNoDeterm.emplace(inpSym, std::set<std::string>({ toName }));
	}
}

