#pragma once
#include "stdafx.h"
#include <vector>

class CStateDeterm
{
public:
	CStateDeterm(const std::string & name);
	void SetPath(std::string nameTo, std::string inpState); // std::map<����, ������� ������>

	std::string m_name = "";
	std::vector<std::string> NamesNode;
	std::map<std::string, std::string> to; // std::map<������� ������, ����>
};

