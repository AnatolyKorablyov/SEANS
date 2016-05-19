#pragma once
#include "stdafx.h"
#include "ReadFromFile.h"

using namespace std;

bool FindSameCond(sy const &elem, vector<sy> const &Q)
{
	bool SameVal = true;
	for (size_t i = 0; i != Q.size(); ++i)
	{
		if (elem.S == Q.at(i).S && elem.Y == Q.at(i).Y)
		{
			return SameVal;
		}
	}
	return !SameVal;
}

void RemoveSameCond(vector<vector<sy>> const &SY, vector<sy> &Q)
{
	for (auto line : SY)
	{
		for (auto elem : line)
		{
			if (!FindSameCond(elem, Q))
			{
				Q.push_back(elem);
			}
		}
	}
}

size_t FindIndexQ(vector<sy> const &Q, sy const &q)
{
	bool IsFind = false;
	for (size_t i = 0; i != Q.size(); ++i)
	{
		if (Q.at(i).S == q.S &&
			Q.at(i).Y == q.Y)
		{
			return i;
		}
	}
}

void WriteResult(ofstream & fileOutput, vector<sy> const &Q,
	vector<vector<sy>> const &SY)
{
	string subStr;
	size_t index;

	for (auto line : SY)
	{
		for (auto elem : line)
		{
			index = FindIndexQ(Q, elem);

			fileOutput << 'Q' << to_string(index) << ' ';

		}
		fileOutput << endl;
	}
}


void MealyInMoore(ofstream & fileOutput, vector<vector<sy>> const &SY)
{
	vector<sy> Q;
	RemoveSameCond(SY, Q);
	WriteResult(fileOutput, Q, SY);
}