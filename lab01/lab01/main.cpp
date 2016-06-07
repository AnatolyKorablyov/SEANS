#include <iostream>
#include "MelleeStatesment.h"
#include "MooraStatesment.h"
#include "TransferMelleToMoora.h"

int main()
{
	CStateMelee nodeQ1("q0");
	nodeQ1.SetPath("x1", "q2", "y1");
	nodeQ1.SetPath("x2", "q0", "y1");

	CMelleeStatesment dataStates;
	dataStates.addState(nodeQ1);

	CStateMelee nodeQ2("q1");
	nodeQ2.SetPath("x1", "q0", "y1");
	nodeQ2.SetPath("x2", "q2", "y2");
	dataStates.addState(nodeQ2);


	CStateMelee nodeQ3("q2");
	nodeQ3.SetPath("x1", "q0", "y2");
	nodeQ3.SetPath("x2", "q1", "y1");
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

	std::cout << "Transfer " << std::endl;
	CTransferMelleToMoora melToMor(dataStates);

	for (auto &it : melToMor.m_resultMoora.m_stateData)
	{
		auto state = it.second;
		std::cout << "name " << state->m_name << "  output " << state->m_output << std::endl;
		for (auto &kj : state->to)
		{
			std::cout << '\t' << kj.first << "->" << kj.second << std::endl;
		}
		std::cout << '\n' << std::endl;
	}
	/*
	CStateMoora nodeQ1Mor("q1", "y1");
	nodeQ1Mor.SetPath("x1", "q1");


	CMooraStatesment dataStatesMor;
	dataStatesMor.addState(nodeQ1Mor);

	nodeQ1Mor.SetPath("x2", "q2");
	dataStatesMor.addState(nodeQ1Mor);

	CStateMoora nodeQ2Mor("q2", "y3");
	nodeQ2Mor.SetPath("x1", "q3");
	dataStatesMor.addState(nodeQ2Mor);

	CStateMoora nodeQ3Mor("q3", "y2");
	dataStatesMor.addState(nodeQ3Mor);

	std::cout << "MOORA :" << std::endl;
	for (auto &it : dataStatesMor.m_stateData)
	{
		auto state = it.second;
		std::cout << "name " << state->m_name << "  output " << state->m_output << std::endl;
		for (auto &kj : state->to)
		{
			std::cout << '\t' << kj.first << "->" << kj.second << std::endl;
		}
		std::cout << '\n' << std::endl;
	}
*/
	/*
	CState nodeq1("q1");
	nodeq1.SetPath("q1", "x1");
	*/
	/*CStateData dataStates;
	dataStates.addState(nodeq1);
/*
	*//*
	nodeq1.SetPath("q2", "x2");
	dataStates.addState(nodeq1);*/

/*
	CState nodeq2("q2");
	nodeq2.SetPath("q3", "x1");
	dataStates.addState(nodeq2);
	*/
	/*for (auto &it : dataStates.stateData)
	{
		auto state = it.second;
		std::cout << "name " << state->m_name << std::endl;
		for (auto &kj : state->to)
		{
			std::cout << '\t' << kj.first << "->" << kj.second << " " << std::endl;
		}
		std::cout << '\n' << std::endl;
	}*/
	return 0;
}