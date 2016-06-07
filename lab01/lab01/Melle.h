#pragma once
#include "stdafx.h"
#include <vector>
#include "State.h"

class CMelle
{
public:
	CMelle(std::map<std::string, std::string> & baseData);
	~CMelle();
private:
	std::vector<std::pair<std::string, std::vector<CState>>> dvumer;
};

