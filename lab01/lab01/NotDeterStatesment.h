#pragma once
#include "StateNotDeterm.h"

class CNotDeterStatesment
{
public:
	bool addState(CStateNotDeterm & stateNode);

	std::map<std::string, CStateNotDeterm*> m_stateData;
};

