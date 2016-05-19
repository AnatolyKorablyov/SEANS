#pragma once
#include "stdafx.h"
#include "vector"
#include "iostream"
#include "algorithm"
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

struct sy
{
	string S;
	string Y;
};


void ReadFromFile(ifstream  & file, string &typeOfMachine,
	vector<vector<string>> &Q, vector<string> &Y, vector<vector<sy>> &SY,
	int &numbertInput, int &numberOutput, int &numberHits);

