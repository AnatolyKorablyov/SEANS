#include "StateNotDeterm.h"

CStateNotDeterm::CStateNotDeterm(std::string name)
	: m_name(name)
{
}

void CStateNotDeterm::SetPath(std::string inpState, std::string toName)
{
	if (to.find(inpState) != to.end())
	{
		to.at(inpState).insert(toName);
	}
	else
	{
		std::set<std::string> as = {toName};
		to.emplace(inpState, as);

	}
	
}
