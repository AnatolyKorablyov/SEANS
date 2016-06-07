#include "Parser.h"

CParser::CParser(const std::string & commandFileName, const std::string & inputFileName, const std::string & outputFileName):
	m_commands({
		{ "translate-mil-to-mur", std::bind(&CParser::TranslateMilToMur, this, std::placeholders::_1) },
		{ "translate-mur-to-mil", std::bind(&CParser::TranslateMurToMil, this, std::placeholders::_1) }
	})
{
	ParseCommand(commandFileName);
}

void CParser::ParseData(const std::string & fileName)
{
	std::ifstream file(fileName);
	if (!file.is_open())
	{
		throw std::invalid_argument("can not open the file " + fileName);
	}
	auto j = json::parse(file);
	auto stateMachine = j.at("state machine");
	for (auto & machine : stateMachine)
	{
		auto machineId = machine.at("id");
		auto machineType = machine.at("type");
		auto machineStates = machine.at("states");
		auto machineTransitions = machine.at("transitions");
		if (machineType == "meale")
		{
			m_melleeMachines[machineId] = {};

			for (const auto & state : machineStates)
			{
				m_melleeMachines[machineId].addState({ state });
			}

			for (const auto & it : machineTransitions)
			{
				auto from = it.at("from");
				auto to = it.at("to");
				auto input = it.at("input");
				auto output = it.at("output");

				m_melleeMachines[machineId][from]->SetPath(input, to, output);
			}
		}
		else if (machineType == "moore")
		{
			m_mooraMachines[machineId] = {};

			for (const auto & state : machineStates)
			{
				m_mooraMachines[machineId].addState({ state.at("id"), state.at("output") });
			}

			for (const auto & it : machineTransitions)
			{
				auto from = it.at("from");
				auto to = it.at("to");
				auto input = it.at("input");

				m_mooraMachines[machineId][from]->SetPath(input, to);
			}
		}
		else
		{
			throw std::invalid_argument("invalid machine type");
		}
	}
}

void CParser::ParseCommand(const std::string & fileName)
{
	std::ifstream file(fileName);
	if (!file.is_open())
	{
		throw std::invalid_argument("can not open the file " + fileName);
	}
	auto j = json::parse(file);
	auto commandsArr = j.at("commands");
	for (auto & command : commandsArr)
	{
		std::vector<std::string> args = command.at("arguments");
		m_commands.at(command.at("type"))(args);
	}
}

void CParser::TranslateMilToMur(std::vector<std::string> & args)
{
	std::string arg;
	//args >> arg;
	std::copy(args.begin(), args.end(), std::ostream_iterator<std::string>(std::cout, " "));
}

void CParser::TranslateMurToMil(std::vector<std::string> & args)
{
	std::string arg;
	std::copy(args.begin(), args.end(), std::ostream_iterator<std::string>(std::cout, " "));

	//args >> arg;
}
