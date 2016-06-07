#pragma once
#include "StateMelee.h"

class CMelleeStatesment
{
public:
	CMelleeStatesment();
	~CMelleeStatesment();

	std::shared_ptr<CStateMelee> addState(const CStateMelee & stateNode);

	std::map<std::string, std::shared_ptr<CStateMelee>> m_stateData;
	std::string id;

	std::shared_ptr<CStateMelee> operator[](const std::string & id);
};
