#pragma once
#include "StateMoora.h"
#include <memory>


class CMooraStatesment
{
public:
	CMooraStatesment();
	~CMooraStatesment();


	bool addState(const CStateMoora & stateNode);
	std::shared_ptr<CStateMoora> operator[](const std::string & id);

	std::map<std::string, std::shared_ptr<CStateMoora>> m_stateData;
	std::string id;
};

