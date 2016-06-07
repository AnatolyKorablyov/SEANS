#pragma once
#include <map>
#include <string>
#include "State.h"

class CStateData
{
public:
	CStateData();
	~CStateData();
	bool addState(CState & stateData);

	std::map<std::string, CState*> stateData;
};

