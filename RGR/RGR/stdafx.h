// stdafx.h: ���������� ���� ��� ����������� ��������� ���������� ������
// ��� ���������� ������ ��� ����������� �������, ������� ����� ������������, ��
// �� ����� ����������
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <string>



// TODO: ���������� ����� ������ �� �������������� ���������, ����������� ��� ���������

enum typeToken
{
	tResWord,
	tOperator,    //�������� 1 
	tStrConstant, //��������� ��������� 1
	tIntConstant, //�������� ���������  1
	tVariable,    //���������� 1
	tDevider,     //�����������
	tSpecific,
	tDualOperator,
	tFloatConst,
	tUnknown      //��� �� ���������, ���� �� ��������
};

struct MyStruct
{
	typeToken type;
	int position;
	std::string name;
};