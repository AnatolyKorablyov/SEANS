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
		CStateMoora moora(ids.first, ids.second.second);
		
		for (auto &res : melleeData.m_stateData.at(ids.second.first)->to)
		{
			moora.SetPath(res.first, unicalState.at(res.second));
		}
		vectorStates.push_back(moora);
	}
	for (auto &as : vectorStates)
	{
		m_resultMoora.addState(as);
	}
}