#include "TransferMoorToMellee.h"

CTransferMoorToMellee::CTransferMoorToMellee(CMooraStatesment & moorData)
{
	for (auto &it : moorData.m_stateData)
	{
		CStateMelee mellee(it.second->m_name);
		for (auto &jd : it.second->to)
		{
			mellee.SetPath(jd.first, jd.second, moorData.m_stateData.at(jd.second)->m_output);
		}
		vectorStates.push_back(mellee);
	}
	for (auto &sa : vectorStates)
	{
		m_resultMellee.addState(sa);
	}
}