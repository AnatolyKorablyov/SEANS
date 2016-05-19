#pragma once
#include "stdafx.h"
#include "ReadFromFile.h"


bool FindSameCond(vector<vector<string>> const &Q,
	vector<vector<string>> const &resQ, int const &i, int const &j)
{
	bool SameVal = true;
	for (size_t e = 0; e != Q.size() && SameVal; ++e)
	{
		if (Q.at(e).at(i) != resQ.at(e).at(j))
		{
			SameVal = false;
		}
	}
	return SameVal;
}

void RemoveSameCond(vector<vector<string>> const &Q, vector<vector<string>> &resQ)
{
	bool IsFind;
	bool SameVal;

	for (size_t i = 0; i != Q.at(0).size(); ++i)
	{
		IsFind = false;
		for (size_t j = 0; j != resQ.at(0).size() && !IsFind; ++j)
		{
			SameVal = FindSameCond(Q, resQ, i, j);

			if (SameVal)
			{
				IsFind = true;
			}
		}
		if (!IsFind)
		{
			for (size_t d = 0; d != Q.size(); ++d)
			{
				resQ.at(d).push_back(Q.at(d).at(i));
			}
		}
	}
}

void WriteResult(ofstream & fout, vector<sy> const &SY,
	vector<vector<string>> const &resQ)
{
	string subStr;
	size_t num;

	for (auto line : resQ)
	{
		for (auto elem : line)
		{
			subStr = elem.substr(1, line.size());

			num = stoi(subStr);
			subStr.clear();

			fout << SY.at(num).S.c_str() << ' ' << SY.at(num).Y.c_str() << '|';
		}
		fout << endl;
	}
}

void AssignsYS(int const &numberHits,
	vector<sy> &SY, vector<string> const &Y)
{
	sy ys;
	for (size_t i = 0; i != numberHits; ++i)
	{
		ys.S.push_back('S');
		ys.S += to_string(i);
		ys.Y = Y.at(i);
		SY.push_back(ys);
		ys.S.clear();
	}
}

void MooreInMealy(ofstream & fout, vector<vector<string>> const &Q,
	vector<string> const &Y, int const &numberHits)
{
	vector<sy> SY;
	vector<vector<sy>> vQ;

	vector<vector<string>> resQ;
	resQ.resize(Q.size());

	AssignsYS(numberHits, SY, Y);

	RemoveSameCond(Q, resQ);
	WriteResult(fout, SY, resQ);
}