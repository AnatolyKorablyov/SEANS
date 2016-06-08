#include "TransferMelleeToNoDeterm.h"

CTransferMelleeToNoDeterm::CTransferMelleeToNoDeterm(CMelleeStatesment & notDeterData)
{
	for (auto &it : notDeterData.m_stateData)
	{
		CStateNotDeterm notDeterm(it.first);
		for (auto &jd : it.second->to)
		{
			notDeterm.SetPath(jd.first, jd.second.first);
		}
		if (it.second->noDeterm)
		{
			for (auto &jd : it.second->toNoDeterm)
			{
				for (auto &gh : jd.second)
				{
					notDeterm.SetPath(jd.first, gh);
				}
			}
		}
		vectorNodes.push_back(notDeterm);
	}
	for (auto &jd : vectorNodes)
	{
		m_deterData.addState(jd);
	}
}