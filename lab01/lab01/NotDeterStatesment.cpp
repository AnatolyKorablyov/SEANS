#include "NotDeterStatesment.h"


std::shared_ptr<CStateNotDeterm> CNotDeterStatesment::addState(const CStateNotDeterm & stateNode)
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
	m_stateData.emplace(nameNode, std::make_shared<CStateNotDeterm>(stateNode));
	return m_stateData.at(nameNode);
}

std::shared_ptr<CStateNotDeterm> CNotDeterStatesment::operator[](const std::string & id)
{
	return m_stateData.at(id);
}