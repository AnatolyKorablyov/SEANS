#include "Minimizate.h"


CMinimizate::CMinimizate(std::map<std::string, CStateMelee*> &originalMachine)
	: m_originalMachine(originalMachine)
	, m_minimizateMachineCopy(originalMachine)
{
	m_check.resize(m_originalMachine.size());
}


CMinimizate::~CMinimizate()
{
}

void CMinimizate::SearchEquivalence(std::string state, std::string name, std::vector<std::pair<std::string,std::string>> second )
{
	unsigned i = 0;
	std::string stateOther;
	MyStruct classes;
	for (auto &it : m_originalMachine)
	{
		for (auto &it : it.second->to)
		{
			stateOther += it.second.second;
		}
		if (state == stateOther && m_check[i] != true)
		{
			classes.word.emplace(it.first,second);
			m_check[i] = true;
		}
		stateOther = "";
		++i;
	}
	bool wasFalse = false;
	for(auto checker :m_check)
	{
		if(!checker)
		{
			wasFalse = true;
		}
	}
	if(!wasFalse)
	{
		m_wasFalse = true;
	}
	m_parts.push_back(classes);
}


void CMinimizate::SearchEquivalence1(std::string state, std::string name, std::vector<std::pair<std::string, std::string>> second)
{
	unsigned i = 0;
	std::string stateOther;
	MyStruct classes;
	for (auto &it : m_originalMachine)
	{
		for (auto &it : it.second->to)
		{
			stateOther += it.second.second;
		}
		if (state == stateOther && m_check[i] != true)
		{
			classes.word.emplace(it.first, second);
			m_check[i] = true;
		}
		stateOther = "";
		++i;
	}
	bool wasFalse = false;
	for (auto checker : m_check)
	{
		if (!checker)
		{
			wasFalse = true;
		}
	}
	if (!wasFalse)
	{
		m_wasFalse = true;
	}
	m_parts.push_back(classes);
}


std::map<std::string, CStateMelee*> CMinimizate::GetMinimizateMachine()
{
	std::map<std::string, CStateMelee*> minimizateMachine;
	std::string state;
	for(auto &iter : m_originalMachine)
	{
		std::vector<std::pair<std::string, std::string>> second;
		for (auto &it : iter.second->to)
		{
			state += it.second.second;
			second.push_back(std::make_pair(it.first,it.second.second));
		}
		if(!m_wasFalse)
		{
			SearchEquivalence(state, iter.first, second);
		}
		state = "";
	}
	int i = 1;
	for (auto &iter : m_parts)
	{
		for (auto &iterWord : iter.word)
		{
			int j = 1;
			for (auto &it : m_originalMachine.find(iterWord.first)->second->to)
			{
				SeachEqual(it.second.first, j, iterWord.first);
				j++;
			}
		}
		++i;
	}

	m_wasFalse = false;
	state = "";
	m_check.clear();
	m_check.resize(m_originalMachine.size());
	for (auto &classes : m_parts)
	{
		for (auto &states : classes.word)
		{
			for (auto &ite : states.second)
			{
				state += ite.second;
			}
			SearchEquivalence1(state, states.first, states.second);
		}
	}
	return minimizateMachine;
}

void CMinimizate::SeachEqual(std::string qOriginal,int count, std::string q)
{
	int i = 1;
	int countParts = 1;
	std::string result;
	for (auto &iter : m_parts)
	{
		if(iter.word.find(qOriginal)!= iter.word.end())
		{
			for(auto &iterState : iter.word.find(qOriginal)->second)
			{
				if(count == i)
				{
					result = std::to_string(countParts);//
					break;
				}		
				++i;
			}
		}
		++countParts;
	}
	i = 1;
	countParts = 1;
	for(auto &iter : m_parts)
	{
		if (iter.word.find(q) != iter.word.end())
		{
			for (auto &iterState : iter.word.find(q)->second)
			{
				if (count == i)
				{
					iterState.second = result;//
					return;
				}
				++i;
			}
		}
	}
}