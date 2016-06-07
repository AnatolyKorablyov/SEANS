#include "MelleeStatesment.h"



CMelleeStatesment::CMelleeStatesment()
{
}


CMelleeStatesment::~CMelleeStatesment()
{
}

std::shared_ptr<CStateMelee> CMelleeStatesment::addState(const CStateMelee & stateNode)
{
	std::string nameNode = stateNode.m_name;
	if (m_stateData.find(nameNode) != m_stateData.end())
	{
		for (auto &it : stateNode.to)
		{
			m_stateData.at(nameNode)->to.emplace(it.first, it.second);
		}
		return m_stateData.at(nameNode);
	}
	m_stateData.emplace(nameNode, std::make_shared<CStateMelee>(stateNode));
	return m_stateData.at(nameNode);
}

std::shared_ptr<CStateMelee> CMelleeStatesment::operator[](const std::string & id)
{
	return m_stateData.at(id);
}
