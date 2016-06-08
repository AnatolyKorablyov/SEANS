#include "MelleeStatesment.h"
#include "StateMelee.h"
#include "vector"
#pragma once

struct MyStruct
{
	std::map<std::string, std::vector<std::pair<std::string, std::string>>> word;//первое имя q, потом пара х1,2,3 и А1,2,3
};


class CMinimizate
{
public:
	CMinimizate(std::map<std::string, CStateMelee*> &originalMachine);
	~CMinimizate();
	std::map<std::string, std::shared_ptr<CStateMelee>> GetMinimizateMachine();
	std::vector<bool> m_check;
private:
	void SearchEquivalence(std::string state, std::string name, std::vector<std::pair<std::string, std::string>> second);
	std::vector<MyStruct> m_parts;
	std::vector<MyStruct> m_partsCopy;
	std::map<std::string, CStateMelee*> m_originalMachine;
	std::vector<std::vector<std::pair<std::string, std::string>>> m_word;
	bool m_wasFalse = false;
	void SearchEquivalence1(std::string state, std::string name, std::vector<std::pair<std::string, std::string>> second);
	void SeachEqual(std::string qOriginal, int count, std::string q);
	void FillTheCell();
	std::map<std::string, std::shared_ptr<CStateMelee>> ConvertedIntoStandardView();
	std::vector<CStateMelee> m_nodes;
};


