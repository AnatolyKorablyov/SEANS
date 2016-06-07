#include "Parser.h"

CParser::CParser(const std::string & commandFileName, const std::string & inputFileName, const std::string & outputFileName):
	m_outputFile(outputFileName),
	m_commands({
		{ "translate-mil-to-mur", std::bind(&CParser::TranslateMilToMur, this, std::placeholders::_1) },
		{ "translate-mur-to-mil", std::bind(&CParser::TranslateMurToMil, this, std::placeholders::_1) }
	})
{
	ParseData(inputFileName);
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
	//choose state machine array
	auto stateMachine = j.at("state machine");

	for (auto & machine : stateMachine)
	{
		auto machineId = machine.at("id");
		auto machineType = machine.at("type");
		auto machineStates = machine.at("states");
		auto machineTransitions = machine.at("transitions");
		//parse states array data
		if (machineType == "meale")
		{
			m_melleeMachines[machineId] = {};//add machine into array

			for (const auto & state : machineStates)
			{//add machine states
				m_melleeMachines[machineId].addState({ state.at("id") });
			}

			for (const auto & it : machineTransitions)
			{//Machine transitions
				auto from = it.at("from");
				auto to = it.at("to");
				auto input = it.at("input");
				auto output = it.at("output");

				m_melleeMachines[machineId][from]->SetPath(input, to, output);
			}
		}
		else if (machineType == "moore")
		{
			m_mooraMachines[machineId] = {};//add machine into array

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
		for (auto arg : args)
		{
			m_commands.at(command.at("type"))(arg);
		}
	}

	Save();
}

void CParser::TranslateMilToMur(const std::string & arg)
{
	CTransferMelleToMoora machine(m_melleeMachines.at(arg));
	//m_melleeMachines.erase(remove(m_melleeMachines.begin(), m_melleeMachines.end(), m_melleeMachines.at(arg)), m_melleeMachines.end());
	m_mooraMachines[arg] = machine.m_resultMoora;

}

void CParser::TranslateMurToMil(const std::string & arg)
{
	CTransferMoorToMellee machine(m_mooraMachines.at(arg));
	//m_mooraMachines.erase(remove(m_mooraMachines.begin(), m_mooraMachines.end(), m_mooraMachines.at(arg)), m_mooraMachines.end());
	m_melleeMachines[arg] = machine.m_resultMellee;
}

void CParser::Save()
{
	std::ofstream file(m_outputFile);
	if (!file.is_open())
	{
		throw std::invalid_argument("can not open the file " + m_outputFile);
	}

	json jResultMachines;
	if (!m_melleeMachines.empty())
	{
		json jmeale;
		for (auto meale : m_melleeMachines)
		{
			//states block
			json jstates;
			for (auto it : meale.second.m_stateData)
			{
				jstates.push_back(it.first);
			}

			//transitions block
			json jtransitions;
			for (auto it : meale.second.m_stateData)
			{
				auto from = it.first;
				for (auto stateMelee : it.second->to)
				{
					auto input = stateMelee.first;
					auto to = stateMelee.second.first;
					auto output = stateMelee.second.second;
					json jtransition = {
						{"input", input},
						{"output", output},
						{"from", from},
						{"to", to}
					};
					jtransitions.push_back(jtransition);
				}
			}

			json j = {
				{"id", meale.first},
				{"type", "meale"},
				{"states", jstates },
				{"transitions", jtransitions}
			};
			jResultMachines.push_back(j);
		}
	}

	if (!m_mooraMachines.empty())
	{
		json jmoora;
		for (auto moora : m_mooraMachines)
		{
			//states block
			json jstates;
			for (auto it : moora.second.m_stateData)
			{
				jstates.push_back({ it.first, it.second->m_output });
			}

			//transitions block
			json jtransitions;
			for (auto it : moora.second.m_stateData)
			{
				json jtransition;
				auto from = it.second->m_name;//
				for (auto itTo : it.second->to)
				{
					auto to = itTo.second;
					auto input = itTo.first;
					jtransition = {
						{ "input", input },
						{ "from", from },
						{ "to", to }
					};
				}
				if (!jtransition.empty())
				{
					jtransitions.push_back(jtransition);
				}
			}
			json j = {
				{ "id", moora.first },
				{ "type", "moore" },
				{ "states", jstates },
				{ "transitions", jtransitions }
			};
			jResultMachines.push_back(j);
		}
	}

	json j = {
		{"state machine",jResultMachines}
	};
	file << j.dump(4);
}