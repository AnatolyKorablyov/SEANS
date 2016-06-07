#include "StateData.h"
#include <iostream>


CStateData::CStateData()
{
}


CStateData::~CStateData()
{
}

bool CStateData::addState(CState & stateNode)
{
	std::string nameNode = stateNode.m_name;
	if (stateData.find(nameNode) != stateData.end())
	{
		std::cout << "helo";
		for (auto &it : stateNode.to)
		{
			stateData.at(nameNode)->to.emplace(it.first, it.second);
		}
		/*if (stateData.at(nameNode)->to.find(stateNode.name) != stateData.at(nameNode)->to.end())
		{
			std::cout << "ASS";
			stateData.at(nameNode)->to.emplace(stateNode.name, stateNode.m_statusX);
		}
		else
		{
			stateData.at(nameNode)->to.emplace(stateNode.name, stateNode.m_statusX);
		}*/
	}
	else
	{
		stateData.emplace(nameNode, &stateNode);
	}
	return false;
}	
