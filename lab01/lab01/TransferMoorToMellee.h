#pragma once
#include "MelleeStatesment.h"
#include "MooraStatesment.h"
#include <vector>

class CTransferMoorToMellee
{
public:
	CTransferMoorToMellee(CMooraStatesment & moorData);
	CMelleeStatesment m_resultMellee;
	std::vector<CStateMelee> vectorStates;
};

