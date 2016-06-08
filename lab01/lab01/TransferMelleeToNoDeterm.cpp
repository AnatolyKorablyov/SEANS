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
		m_deterData.addState(notDeterm);
	}
}