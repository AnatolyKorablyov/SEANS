#pragma once
#include "StateDeterm.h"
#include "memory"
class CDeterStatesment
{
public:
	std::shared_ptr<CStateDeterm> addState(const CStateDeterm & stateNode);

	std::map<std::string, std::shared_ptr<CStateDeterm>> m_stateData;

	std::string id;

	std::shared_ptr<CStateDeterm> operator[](const std::string & id);
};

