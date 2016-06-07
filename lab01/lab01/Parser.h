#pragma once
#include "json.hpp"
#include <string>
#include <fstream>
#include <string>
#include <functional>
#include <vector>

#include "MooraStatesment.h"
#include "MelleeStatesment.h"

using json = nlohmann::json;

class CParser
{
public:
	CParser() = delete;
	CParser(const std::string & commandFileName, const std::string & inputFileName, const std::string & outputFileName);
	~CParser() = default;
private:
	void ParseData(const std::string & fileName);
	void ParseCommand(const std::string & fileName);
	void TranslateMilToMur(std::vector<std::string> & args);
	void TranslateMurToMil(std::vector<std::string> & args);

	std::map < std::string, std::function<void(std::vector<std::string> & args)> > m_commands;
	CMooraStatesment m_moora;
	CMelleeStatesment m_meale;
	std::map < std::string, CMelleeStatesment> m_melleeMachines;
	std::map < std::string, CMooraStatesment> m_mooraMachines;

};
