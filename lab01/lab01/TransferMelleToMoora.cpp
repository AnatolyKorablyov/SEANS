#include "TransferMelleToMoora.h"
#include <iostream>
CTransferMelleToMoora::CTransferMelleToMoora(CMelleeStatesment &melleeData)
{
	for (auto &it : melleeData.m_stateData)
	{
		for (auto & kj : it.second->to)
		{
			if (unicalState.find(kj.second) == unicalState.end())
			{
				std::string nameNode = "b" + std::to_string(unicalState.size());
				unicalState.emplace(kj.second, nameNode);
				unicalId.emplace(nameNode, kj.second);
			}
		}
	}
	for (auto &ids : unicalId)
	{
		std::cout << "1 ini node "<< ids.first << " " << ids.second.second << std::endl;
		CStateMoora moora(ids.first, ids.second.second);
		std::cout << "2 ini node " << moora.m_name << " " << moora.m_output << std::endl;

		for (auto &res : melleeData.m_stateData.at(ids.second.first)->to)
		{
			std::cout << "1 path " << res.first << "->" << unicalState.at(res.second) << std::endl;
			moora.SetPath(res.first, unicalState.at(res.second));
			for (auto &sadas : moora.to)
			{
				std::cout << "2 path " << sadas.first << "->" << sadas.second << std::endl;
			}
		}
		vectorStates.push_back(moora);
	}
	for (auto &as : vectorStates)
	{
		m_resultMoora.addState(as);
	}
}