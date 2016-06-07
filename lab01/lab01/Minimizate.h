#include "MelleeStatesment.h"
#include "StateMelee.h"
#include "vector"


#pragma once
class CMinimizate
{
public:
	CMinimizate(std::map<std::string, CStateMelee*> &originalMachine);
	~CMinimizate();
	std::map<std::string, CStateMelee*> GetMinimizateMachine();
	void SearchEquivalence(std::string state);
	std::vector<bool> m_check;
private:
	std::map<std::string, CStateMelee*> m_originalMachine;
	std::map<std::string, CStateMelee*> m_minimizateMachineCopy;
	std::vector<std::string, std::vector<std::string, std::string>> word;
};


