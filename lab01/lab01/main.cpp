#include <iostream>
#include "MelleeStatesment.h"
#include "MooraStatesment.h"
#include "Parser.h"

#include "TransferMelleToMoora.h"
#include "TransferMoorToMellee.h"
#include "TransferMelleeToNoDeterm.h"
#include "DeterminateAutomates.h"

int main(int argc, char* argv[])
{/*
	CStateNotDeterm notDetermQ1("S0");
	notDetermQ1.SetPath("1", "S0");
	notDetermQ1.SetPath("0", "S1");

	CNotDeterStatesment notDeterData;
	notDeterData.addState(notDetermQ1);

	CStateNotDeterm notDetermQ2("S1");
	notDetermQ2.SetPath("1", "S0");
	notDetermQ2.SetPath("0", "S2");
	notDeterData.addState(notDetermQ2);

	CStateNotDeterm notDetermQ3("S2");
	notDetermQ3.SetPath("0", "S2");
	notDetermQ3.SetPath("0", "S0");
	notDeterData.addState(notDetermQ3);

	CStateNotDeterm notDetermQ5("S5");
	notDeterData.addState(notDetermQ5);*/
	/*
	std::cout << std::endl << "NOT DETERMINATE: " << std::endl;
	for (auto &it : notDeterData.m_stateData)
	{
		std::cout << "name " << it.second->m_name << std::endl;
		for (auto &jf : it.second->to)
		{
			std::cout << jf.first << "->";
			for (auto &as : jf.second)
			{
				std::cout << as << " ";
			}
			std::cout << std::endl;
		}
	}

	std::cout << std::endl << "Determinate: " << std::endl;
	CDeterminateAutomates determinate(notDeterData);

	for (auto &it : determinate.m_deterAuto.m_stateData)
	{
		if (it.second->to.size() != 0)
		{
			std::cout << "name " << it.second->m_name << std::endl;
			for (auto &jf : it.second->to)
			{
				std::cout << jf.first << "->" << jf.second << std::endl;
			}
		}
	}*/

	//<название ррограммы> <путь до файл команд> <путь до файла ввода> <путь до файла вывода>
	std::string commandFileName;
	std::string inputFileName;
	std::string outputFileName;
	std::cout << "<path to command file> <path to input file> <path to output file>" << std::endl;
	if (argc == 4)
	{
		commandFileName = argv[1];
		inputFileName = argv[2];
		outputFileName = argv[3];
	}
	else
	{
		std::cin >> commandFileName >> inputFileName >> outputFileName;
	}
	CParser(commandFileName, inputFileName, outputFileName);
	system("pause");
	

	
	CStateMelee nodeQ1("S0");
	nodeQ1.SetPath("0", "S1", "y1");
	nodeQ1.SetPath("1", "S0", "y1");

	CMelleeStatesment dataStates;
	dataStates.addState(nodeQ1);

	CStateMelee nodeQ2("S1");
	nodeQ2.SetPath("0", "S2", "y1");
	nodeQ2.SetPath("1", "S0", "y2");
	dataStates.addState(nodeQ2);

	CStateMelee nodeQ3("S2");
	nodeQ3.SetPath("0", "S2", "y2");
	nodeQ3.SetPath("0", "S0", "y1");
	dataStates.addState(nodeQ3);
	std::cout << "MELLEEE :" << std::endl;
	for (auto &it : dataStates.m_stateData)
	{
		auto state = it.second;
		std::cout << "name " << state->m_name << std::endl;
		for (auto &kj : state->to)
		{
			std::cout << '\t' << kj.first << "->" << kj.second.first << "/" << kj.second.second << std::endl;
		}
		std::cout << '\n' << std::endl;
	}

	CTransferMelleeToNoDeterm as(dataStates);
	CDeterminateAutomates deter(as.m_deterData);
	std::cout << std::endl << "Determinate: " << std::endl;
	for (auto &it : deter.m_deterAuto.m_stateData)
	{
		if (it.second->to.size() != 0)
		{
			std::cout << "name " << it.second->m_name << std::endl;
			for (auto &jf : it.second->to)
			{
				std::cout << jf.first << "->" << jf.second << std::endl;
			}
		}
	}
	//
//	std::cout << "Transfer " << std::endl;
//	CTransferMelleToMoora melToMor(dataStates);
//
//	for (auto &it : melToMor.m_resultMoora.m_stateData)
//	{
//		auto state = it.second;
//		std::cout << "name " << state->m_name << "  output " << state->m_output << std::endl;
//		for (auto &kj : state->to)
//		{
//			std::cout << '\t' << kj.first << "->" << kj.second << std::endl;
//		}
//		std::cout << '\n' << std::endl;
//	}
//
//
//
//
//	CStateMoora nodeQ1Mor("q1", "y1");
//	nodeQ1Mor.SetPath("x1", "q2");
//	nodeQ1Mor.SetPath("x2", "q3");
//	CMooraStatesment dataStatesMor;
//	dataStatesMor.addState(nodeQ1Mor);
//
//
//	CStateMoora nodeQ2Mor("q2", "y1");
//	nodeQ2Mor.SetPath("x1", "q2");
//	nodeQ2Mor.SetPath("x2", "q4");
//	dataStatesMor.addState(nodeQ2Mor);
//
//
//	CStateMoora nodeQ3Mor("q3", "y2");
//	nodeQ3Mor.SetPath("x1", "q1");
//	nodeQ3Mor.SetPath("x2", "q2");
//	dataStatesMor.addState(nodeQ3Mor);
//
//	CStateMoora nodeQ4Mor("q4", "y1");
//	nodeQ4Mor.SetPath("x1", "q2");
//	nodeQ4Mor.SetPath("x2", "q5");
//	dataStatesMor.addState(nodeQ4Mor);
//
//	CStateMoora nodeQ5Mor("q5", "y2");
//	nodeQ5Mor.SetPath("x1", "q4");
//	nodeQ5Mor.SetPath("x2", "q2");
//	dataStatesMor.addState(nodeQ5Mor);
//
//	std::cout << "MOORA :" << std::endl;
//	for (auto &it : dataStatesMor.m_stateData)
//	{
//		auto state = it.second;
//		std::cout << "name " << state->m_name << "  output " << state->m_output << std::endl;
//		for (auto &kj : state->to)
//		{
//			std::cout << '\t' << kj.first << "->" << kj.second << std::endl;
//		}
//		std::cout << '\n' << std::endl;
//	}
//	std::cout << "Transfer " << std::endl;
//	CTransferMoorToMellee MorToMel(dataStatesMor);
//	for (auto &it : MorToMel.m_resultMellee.m_stateData)
//	{
//		auto state = it.second;
//		std::cout << "name " << state->m_name << std::endl;
//		for (auto &kj : state->to)
//		{
//			std::cout << '\t' << kj.first << "->" << kj.second.first << "/" << kj.second.second << std::endl;
//		}
//		std::cout << '\n' << std::endl;
//	}
//
//
//	/*
//	CState nodeq1("q1");
//	nodeq1.SetPath("q1", "x1");
//	*/
//	/*CStateData dataStates;
//	dataStates.addState(nodeq1);
///*
//	*//*
//	nodeq1.SetPath("q2", "x2");
//	dataStates.addState(nodeq1);*/
//
///*
//	CState nodeq2("q2");
//	nodeq2.SetPath("q3", "x1");
//	dataStates.addState(nodeq2);
//	*/
//	/*for (auto &it : dataStates.stateData)
//	{
//		auto state = it.second;
//		std::cout << "name " << state->m_name << std::endl;
//		for (auto &kj : state->to)
//		{
//			std::cout << '\t' << kj.first << "->" << kj.second << " " << std::endl;
//		}
//		std::cout << '\n' << std::endl;
//	}*/
	return 0;
}