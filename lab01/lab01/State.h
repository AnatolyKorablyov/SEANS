#pragma once
#include <string>
#include <map>

class CState
{
public:
	std::string m_name = "";
	std::map<std::string, std::string> to;
	std::string m_statusX = "";
	std::string m_statusY = "";
	CState(const std::string & name);
	void SetPath(std::string toName, std::string out);
	~CState();
};

