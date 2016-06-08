#pragma once
#include "StateNotDeterm.h"
#include <memory>
class CNotDeterStatesment
{
public:
	std::shared_ptr<CStateNotDeterm> addState(const CStateNotDeterm & stateNode);

	std::map<std::string, std::shared_ptr<CStateNotDeterm>> m_stateData;

	std::string id;

	std::shared_ptr<CStateNotDeterm> operator[](const std::string & id);
};

