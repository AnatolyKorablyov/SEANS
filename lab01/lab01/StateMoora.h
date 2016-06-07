#pragma once
#include "stdafx.h"

class CStateMoora
{
public:
	std::string m_name = "";
	std::string m_output = "";
	std::map<std::string, std::string> to;
	CStateMoora(const std::string & name, const std::string & output);
	void SetPath(std::string inp, std::string toName);
};