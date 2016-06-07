#pragma once
#include "StateMoora.h"

class CMooraStatesment
{
public:
	CMooraStatesment();
	~CMooraStatesment();


	bool addState(CStateMoora & stateNode);

	std::map<std::string, CStateMoora*> m_stateData;
};

