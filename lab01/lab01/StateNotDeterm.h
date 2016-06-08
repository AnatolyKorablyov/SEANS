#pragma once
#include "stdafx.h"
#include <set>
class CStateNotDeterm
{
public:
	CStateNotDeterm(const std::string & name);
	void SetPath(std::string nameTo, std::string inpState); // std::map<куда, входной символ>
	std::string m_name = "";
	std::map<std::string, std::set<std::string>> to; // std::map<входной символ, куда>
};

