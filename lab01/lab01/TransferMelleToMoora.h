#pragma once
#include "MelleeStatesment.h"
#include "MooraStatesment.h"
#include <vector>

class CTransferMelleToMoora
{
public:
	CTransferMelleToMoora(CMelleeStatesment &melleeData);
	std::map<std::pair<std::string, std::string>, std::string> unicalState;
	std::map<std::string, std::pair<std::string, std::string>> unicalId;
	CMooraStatesment m_resultMoora;
	std::vector<CStateMoora> vectorStates;
};

