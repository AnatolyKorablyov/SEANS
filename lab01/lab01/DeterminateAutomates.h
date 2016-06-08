#pragma once
#include "NotDeterStatesment.h"
#include "DeterStatesment.h"
#include <vector>

class CDeterminateAutomates
{
public:
	CDeterminateAutomates(CNotDeterStatesment & notDeterData);
	bool Recursion();
	CDeterStatesment m_deterAuto;
	std::map<std::set<std::string>, std::map<std::string, std::set<std::string>>> localSet;
	std::vector<CStateDeterm> determVector;
	std::set<std::string> fromSet;
	std::set<std::string> toSet;
	std::map<std::string, std::set<std::string>> localMap;

};

