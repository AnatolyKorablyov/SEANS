#include "Minimizate.h"


CMinimizate::CMinimizate(std::map<std::string, CStateMelee*> &originalMachine)
	: m_originalMachine(originalMachine)
	, m_minimizateMachineCopy(originalMachine)
{
	m_check.resize(m_originalMachine.size());
	m_check[0] = true;
}


CMinimizate::~CMinimizate()
{
}

void CMinimizate::SearchEquivalence(std::string state)
{
	unsigned i = 0;
	std::string stateOther;
	for (auto &it : m_minimizateMachineCopy)
	{
		for (auto it : it.second->to)
		{
			stateOther += it.second.second;
		}
		if (state == stateOther && m_check[i] != true)
		{

		}
		stateOther = "";
		++i;
	}
}

std::map<std::string, CStateMelee*> CMinimizate::GetMinimizateMachine()
{
	std::map<std::string, CStateMelee*> minimizateMachine;
	std::string state;
	for(auto it : m_minimizateMachineCopy)
	{
		for (auto it : it.second->to)
		{
			state += it.second.second;
		}
		SearchEquivalence(state);
	}
	/*for(auto &it : m_originalMachine)
	{
		auto  beginState = it.second->to;
	}*/
	return minimizateMachine;
}