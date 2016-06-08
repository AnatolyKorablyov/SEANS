#include "DeterminateAutomates.h"
#include <iostream>

CDeterminateAutomates::CDeterminateAutomates(CNotDeterStatesment & notDeterData)
{
	for (auto &it : notDeterData.m_stateData)
	{
		fromSet.clear();
		fromSet.insert(it.second->m_name);
		localMap.clear();
		for (auto &kj : it.second->to)
		{
			localMap.emplace(kj.first, kj.second);
		}
		localSet.emplace(fromSet, localMap);
	}
	while (Recursion())
	{
		std::cout << "do";
	}
	for (auto &ut : determVector)
	{
		m_deterAuto.addState(ut);
	}
}

bool CDeterminateAutomates::Recursion()
{
	bool result = false;
	for (auto it = localSet.begin(); it != localSet.end(); ++it)
	{
		std::string name = "";
		for (auto &nam : it->first)
		{
			name += nam;
		}
		CStateDeterm determ(name);
		for (auto &asd : it->second)
		{
			name = "";
			for (auto &names : asd.second)
			{
				name += names;
			}
			determ.SetPath(name, asd.first);
			if (localSet.find(asd.second) == localSet.end())
			{
				result = true;
				toSet.clear();
				localMap.clear();
				for (auto yui : asd.second)
				{
					toSet.clear();
					toSet.insert(yui);

					for (auto &lastsa : localSet.at(toSet))
					{
						if (localMap.find(lastsa.first) == localMap.end())
						{
							localMap.emplace(lastsa.first, lastsa.second);
						}
						else
						{
							for (auto &uh : lastsa.second)
							{
								localMap.at(lastsa.first).insert(uh);
							}
						}
					}
				}
				localSet.emplace(asd.second, localMap);
			}
		}
		determVector.push_back(determ);
	}
	return result;
}