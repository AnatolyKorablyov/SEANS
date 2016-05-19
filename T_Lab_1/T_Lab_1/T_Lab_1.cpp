// T_Lab_1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "MealyInMoore.h"
#include "MooreInMealy.h"
#include "ReadFromFile.h"


int _tmain(int argc, _TCHAR* argv[])
{

	ifstream fin("input.txt");
	ofstream fout("output.txt");


	string typeOfMachine;
	vector<vector<string>> Q;
	vector<string> Y;
	vector<vector<sy>> SY;
	const string MOORE = "<MR>";
	int numInput, numberOutput, numberHit;

	ReadFromFile(fin, typeOfMachine, Q, Y, SY,
		numInput, numberOutput, numberHit);

	if (typeOfMachine == MOORE)
	{
		MooreInMealy(fout, Q, Y, numberHit);
	}
	else
	{
		MealyInMoore(fout, SY);
	}
	
	fin.close();
	fout.close();
	return 0;
}

