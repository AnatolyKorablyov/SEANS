#include <iostream>
#include "MelleeStatesment.h"
#include "MooraStatesment.h"
#include "TransferMelleToMoora.h"
#include "TransferMoorToMellee.h"
#include "DeterminateAutomates.h"
#include "Equivalence—hecking.h"

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




	CStateMoora nodeQ1Mor("q1", "y1");
	nodeQ1Mor.SetPath("x1", "q2");
	nodeQ1Mor.SetPath("x2", "q3");
	CMooraStatesment dataStatesMor;
	dataStatesMor.addState(nodeQ1Mor);


	CStateMoora nodeQ2Mor("q2", "y1");
	nodeQ2Mor.SetPath("x1", "q2");
	nodeQ2Mor.SetPath("x2", "q4");
	dataStatesMor.addState(nodeQ2Mor);


	CStateMoora nodeQ3Mor("q3", "y2");
	nodeQ3Mor.SetPath("x1", "q1");
	nodeQ3Mor.SetPath("x2", "q2");
	dataStatesMor.addState(nodeQ3Mor);

	CStateMoora nodeQ4Mor("q4", "y1");
	nodeQ4Mor.SetPath("x1", "q2");
	nodeQ4Mor.SetPath("x2", "q5");
	dataStatesMor.addState(nodeQ4Mor);

	CStateMoora nodeQ5Mor("q5", "y2");
	nodeQ5Mor.SetPath("x1", "q4");
	nodeQ5Mor.SetPath("x2", "q2");
	dataStatesMor.addState(nodeQ5Mor);

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
	std::cout << "Transfer " << std::endl;
	CTransferMoorToMellee MorToMel(dataStatesMor);
	for (auto &it : MorToMel.m_resultMellee.m_stateData)
	{
		auto state = it.second;
		std::cout << "name " << state->m_name << std::endl;
		for (auto &kj : state->to)
		{
			std::cout << '\t' << kj.first << "->" << kj.second.first << "/" << kj.second.second << std::endl;
		}
		std::cout << '\n' << std::endl;
	}

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

	std::cout << std::endl << "NOT DETERMINATE: " << std::endl;
	for (auto &it : notDeterData.m_stateData)
	{
		std::cout << "name " << it.second->m_name << std::endl;
		for (auto &jf : it.second->to)
		{
			std::cout << jf.first << "->" ;
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
		std::cout << "name " << it.second->m_name << std::endl;
		for (auto &jf : it.second->to)
		{
			std::cout << jf.first << "->" << jf.second << std::endl;
		}
	}


	std::cout << std::endl << "EQUIVALENCE: " << std::endl;
	CEquivalence—hecking checkEqual;
	if (checkEqual.equivalenceMoora(melToMor.m_resultMoora, dataStatesMor))
	{
		std::cout << "equivalence Moora" << std::endl;
	}
	else
	{
		std::cout << "not equivalence" << std::endl;
	}

	CStateMoora nodeMorq1("q1", "y1");
	nodeMorq1.SetPath("x1", "q2");
	nodeMorq1.SetPath("x2", "q3");
	CMooraStatesment dataStatesMorSecond;
	dataStatesMorSecond.addState(nodeMorq1);


	CStateMoora nodeMorq2("q2", "y1");
	nodeMorq2.SetPath("x1", "q2");
	nodeMorq2.SetPath("x2", "q4");
	dataStatesMorSecond.addState(nodeMorq2);


	CStateMoora nodeMorq3("q3", "y2");
	nodeMorq3.SetPath("x1", "q1");
	nodeMorq3.SetPath("x2", "q2");
	dataStatesMorSecond.addState(nodeMorq3);

	CStateMoora nodeMorq4("q4", "y1");
	nodeMorq4.SetPath("x1", "q2");
	nodeMorq4.SetPath("x2", "q5");
	dataStatesMorSecond.addState(nodeMorq4);

	CStateMoora nodeMorq5("q5", "y2");
	nodeMorq5.SetPath("x1", "q4");
	nodeMorq5.SetPath("x2", "q2");
	dataStatesMorSecond.addState(nodeMorq5);

	if (checkEqual.equivalenceMoora(dataStatesMorSecond, dataStatesMor))
	{
		std::cout << "equivalence Moora" << std::endl;
	}
	else
	{
		std::cout << "not equivalence" << std::endl;
	}

	if (checkEqual.equivalenceMellee(dataStates, MorToMel.m_resultMellee))
	{
		std::cout << "equivalence Mellee" << std::endl;
	}
	else
	{
		std::cout << "not equivalence" << std::endl;
	}

	CStateMelee nodeQ1Mel("q0");
	nodeQ1Mel.SetPath("x1", "q2", "y1");
	nodeQ1Mel.SetPath("x2", "q0", "y1");

	CMelleeStatesment dataStatesMel;
	dataStatesMel.addState(nodeQ1Mel);

	CStateMelee nodeQ2Mel("q1");
	nodeQ2Mel.SetPath("x1", "q0", "y1");
	nodeQ2Mel.SetPath("x2", "q2", "y2");
	dataStatesMel.addState(nodeQ2Mel);


	CStateMelee nodeQ3Mel("q2");
	nodeQ3Mel.SetPath("x1", "q0", "y2");
	nodeQ3Mel.SetPath("x2", "q1", "y1");
	dataStatesMel.addState(nodeQ3Mel);


	if (checkEqual.equivalenceMellee(dataStatesMel, dataStates))
	{
		std::cout << "equivalence Mellee" << std::endl;
	}
	else
	{
		std::cout << "not equivalence" << std::endl;
	}




	return 0;
}