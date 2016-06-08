#include "EquivalenceÑhecking.h"

bool CEquivalenceÑhecking::equivalenceMoora(CMooraStatesment & first, CMooraStatesment & second)
{
	for (auto &it : first.m_stateData)
	{
		if (second.m_stateData.find(it.first) != second.m_stateData.end())
		{
			if (second.m_stateData.at(it.first)->m_output != it.second->m_output)
			{
				return false;
			}
			for (auto &jd : it.second->to)
			{
				if (second.m_stateData.at(it.first)->to.find(jd.first) == second.m_stateData.at(it.first)->to.end())
				{
					return false;
				}
				else
				{
					if (first.m_stateData.at(it.first)->to.at(jd.first) != jd.second)
					{
						return false;
					}
				}
			}
		}
		else
		{
			return false;
		}
	}

	for (auto &it : second.m_stateData)
	{
		if (first.m_stateData.find(it.first) != first.m_stateData.end())
		{
			if (first.m_stateData.at(it.first)->m_output != it.second->m_output)
			{
				return false;
			}
			for (auto &jd : it.second->to)
			{
				if (first.m_stateData.at(it.first)->to.find(jd.first) == first.m_stateData.at(it.first)->to.end())
				{
					return false;
				}
				else
				{
					if (first.m_stateData.at(it.first)->to.at(jd.first) != jd.second)
					{
						return false;
					}
				}
			}
		}
		else
		{
			return false;
		}
	}
	return true;
}

bool CEquivalenceÑhecking::equivalenceMellee(CMelleeStatesment & first, CMelleeStatesment & second)
{
	for (auto &it : first.m_stateData)
	{
		if (second.m_stateData.find(it.first) != second.m_stateData.end())
		{
			for (auto &jd : it.second->to)
			{
				if (second.m_stateData.at(it.first)->to.find(jd.first) == second.m_stateData.at(it.first)->to.end())
				{
					return false;
				}
				else
				{
					if (first.m_stateData.at(it.first)->to.at(jd.first).first != jd.second.first)
					{
						return false;
					}
					if (first.m_stateData.at(it.first)->to.at(jd.first).second != jd.second.second)
					{
						return false;
					}
				}
			}
		}
		else
		{
			return false;
		}
	}

	for (auto &it : second.m_stateData)
	{
		if (first.m_stateData.find(it.first) != first.m_stateData.end())
		{
			for (auto &jd : it.second->to)
			{
				if (first.m_stateData.at(it.first)->to.find(jd.first) == first.m_stateData.at(it.first)->to.end())
				{
					return false;
				}
				else
				{
					if (first.m_stateData.at(it.first)->to.at(jd.first).first != jd.second.first)
					{
						return false;
					}
					if (first.m_stateData.at(it.first)->to.at(jd.first).second != jd.second.second)
					{
						return false;
					}
				}
			}
		}
		else
		{
			return false;
		}
	}
	return true;
}
