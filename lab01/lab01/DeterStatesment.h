#pragma once
#include "StateDeterm.h"

class CDeterStatesment
{
public:
	bool addState(CStateDeterm & stateNode);

	std::map<std::string, CStateDeterm*> m_stateData;
};

