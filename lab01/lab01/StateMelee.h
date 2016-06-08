#pragma once
#include "stdafx.h"
#include <memory>
#include <set>
class CStateMelee
{
public:
	bool noDeterm = false;
	std::string m_name = "";
	std::map<std::string, std::pair<std::string, std::string>> to; // map<������� ������(x1, x2 ..), <��� ����, �������� ������(y1, y2 ..)>>
	CStateMelee(const std::string & name);
	void SetPath(std::string inpSym, std::string toName, std::string out); // inpSym = x1, x2..; toName = ��� ����; out = y1, y2 ..
	std::map<std::string, std::set<std::string>> toNoDeterm; // map<������� ������(x1, x2 ..), <��� ����, �������� ������(y1, y2 ..)>>
};

