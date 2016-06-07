#pragma once
#include "stdafx.h"
#include <memory>

class CStateMelee
{
public:
	std::string m_name = "";
	std::map<std::string, std::pair<std::string, std::string>> to; // map<Входной символ(x1, x2 ..), <имя куда, выходной символ(y1, y2 ..)>>
	CStateMelee(const std::string & name);
	void SetPath(std::string inpSym, std::string toName, std::string out); // inpSym = x1, x2..; toName = имя узла; out = y1, y2 ..
};

