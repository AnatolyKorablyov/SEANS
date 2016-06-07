#pragma once
#include "StateMelee.h"

class CMelleeStatesment
{
public:
	CMelleeStatesment();
	~CMelleeStatesment();

	bool addState(CStateMelee & stateNode);

	std::map<std::string, CStateMelee*> m_stateData;
};

