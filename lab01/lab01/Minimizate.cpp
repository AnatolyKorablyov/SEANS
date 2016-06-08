#include "Minimizate.h"


CMinimizate::CMinimizate(std::map<std::string, std::shared_ptr<CStateMelee>> &originalMachine)
	: m_originalMachine(originalMachine)
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
	if (!classes.word.empty())
	{
		m_parts.push_back(classes);		
	}
}


void CMinimizate::SearchEquivalence1(std::string state, std::string name, std::vector<std::pair<std::string, std::string>> second)
{
	unsigned i = 0;
	std::string stateOther;
	MyStruct classes;
	for (auto &it : m_parts)
	{
		for (auto &q : it.word) 
		{
			for (auto &states : q.second)
			{
				stateOther += states.second;
			}
			if (state == stateOther && m_check[i] != true)
			{
				classes.word.emplace(q.first, q.second);
				m_check[i] = true;
			}
			stateOther = "";
			++i;
		}
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
	if(!classes.word.empty())
	{
		m_partsCopy.push_back(classes);
	}
}


std::map<std::string, std::shared_ptr<CStateMelee>> CMinimizate::GetMinimizateMachine()
{
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
	FillTheCell();
	for (auto &classes : m_parts)
	{
		for (auto &states : classes.word)
		{
			for (auto &ite : states.second)
			{
				state += ite.second;
			}
			if (!m_wasFalse)
			{
				SearchEquivalence1(state, states.first, states.second);
			}
			state = "";
		}
	}
	while(m_parts.size() != m_partsCopy.size())
	{
		FillTheCell();
		m_partsCopy.clear();
		for (auto &classes : m_parts)
		{
			for (auto &states : classes.word)
			{
				for (auto &ite : states.second)
				{
					state += ite.second;
				}
				if (!m_wasFalse)
				{
					SearchEquivalence1(state, states.first, states.second);
				}
				state = "";
			}
		}
	}
	return ConvertedIntoStandardView();
}

std::map<std::string, std::shared_ptr<CStateMelee>> CMinimizate::ConvertedIntoStandardView()
{
	CMelleeStatesment minimizateMachine;
	
	for(auto &classes : m_parts)
	{
		auto firstState = classes.word.begin();
		CStateMelee node(firstState->first);
		auto x = m_originalMachine.at(firstState->first);
		for (auto &iter : x->to)
		{
			node.SetPath(iter.first, iter.second.first, iter.second.second);
		}
		m_nodes.push_back(node);
	}
	for(auto &it : m_nodes)
	{
		minimizateMachine.addState(it);
	}
	return minimizateMachine.m_stateData;
}

void CMinimizate::FillTheCell()
{
	std::string state;
	int i = 1;
	m_wasFalse = false;
	state = "";
	m_check.clear();
	m_check.resize(m_originalMachine.size());
	if (m_partsCopy.size() > m_parts.size()) 
	{
		std::swap(m_parts, m_partsCopy);
	}
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