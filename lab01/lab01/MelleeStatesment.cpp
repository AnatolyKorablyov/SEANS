#include "MelleeStatesment.h"



CMelleeStatesment::CMelleeStatesment()
{
}


CMelleeStatesment::~CMelleeStatesment()
{
}

bool CMelleeStatesment::addState(CStateMelee & stateNode)
{
	std::string nameNode = stateNode.m_name;
	if (m_stateData.find(nameNode) != m_stateData.end())
	{
		for (auto &it : stateNode.to)
		{
			m_stateData.at(nameNode)->to.emplace(it.first, it.second);
		}
	}
	else
	{
		m_stateData.emplace(nameNode, &stateNode);
	}
	return false;
}
