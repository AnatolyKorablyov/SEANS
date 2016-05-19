#pragma once
#include "stdafx.h"
#include "ReadFromFile.h"

void MooreInMealy(ofstream & fileOutput, vector<vector<string>> const &Q,
	vector<string> const &Y, int const &numberHits);