#pragma once
#include "NotDeterStatesment.h"
#include "MelleeStatesment.h"
#include <vector>

class CTransferMelleeToNoDeterm
{
public:
	CTransferMelleeToNoDeterm(CMelleeStatesment &notDeterData);
	CNotDeterStatesment m_deterData;
private:
	std::vector<CStateNotDeterm> vectorNodes;
};