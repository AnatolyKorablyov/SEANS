#include "stdafx.h"
#include "ReadFromFile.h"

enum info
{
	InputSigns,
	OutputSigns,
	Hits,
	typeMachine,
	table,
	assigns,
};

void ReadFromFile(ifstream  & file, string &typeOfMachine,
	vector<vector<string>> &Q, vector<string> &Y, vector<vector<sy>> &SY,
	int &numbertInput, int &numberOutput, int &numberHits)
{
	const string MOORE = "<MR>";
	char charSign;
	string strBuf;
	info infoFromFile = InputSigns;
	stringstream ss;
	sy ys;
	int numberStr = 0;
	bool IsFind;

	do{
		file.read(&charSign, sizeof(char));

		if ((charSign == ',') || charSign == '\n' ||
			charSign == ' ' || file.eof())
		{
			ss << strBuf;

			switch (infoFromFile)
			{
			case InputSigns:
				ss >> numbertInput;
				infoFromFile = OutputSigns;
				break;
			case OutputSigns:
				ss >> numberOutput;
				infoFromFile = Hits;
				break;
			case Hits:
				ss >> numberHits;
				infoFromFile = typeMachine;
				break;
			case typeMachine:
				typeOfMachine = strBuf;
				if (typeOfMachine == MOORE)
				{
					infoFromFile = assigns;
					Q.resize(numbertInput);
				}
				else
				{
					infoFromFile = table;
					SY.resize(numbertInput);
				}
				break;
			case assigns:
				Y.push_back(strBuf);
				if (charSign == '\n')
				{
					infoFromFile = table;
				}
				break;
			case table:
				if (typeOfMachine == MOORE)
				{
					Q.at(numberStr).push_back(strBuf);
				}
				else
				{
					if (charSign == ' ') ys.S = strBuf;
					else
					{
						ys.Y = strBuf;
						SY.at(numberStr).push_back(ys);
					}
				}
				if (charSign == '\n') ++numberStr;
			}
			strBuf.clear();
			ss.clear();
		}
		else
		{
			strBuf.push_back(charSign);
		}
	} while (!file.eof());
}

