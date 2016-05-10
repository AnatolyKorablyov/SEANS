#include "stdafx.h"
#include "DefineType.h"
#include <string>

#pragma warning(disable : 4996)

using namespace std;

string DefineTypeOperator(string name)
{
	string result;
	char cstr = name[0];

	int nChar = cstr;
	switch (nChar)
	{
	case 43:
		result = "PLUS";
		break;
	case 45:
		result = "MINUS";
		break;
	case 47:
		result = "SLASH";
		break;
	case 42:
		result = "STAR";
		break;
	case 60:
		result = "CHEVRON_L";
		break;
	case 61:
		result = "EQ_OP";
		break;
	case 62:
		result = "CHEVRON_R";
		break;
	case 64:
		result = "DOG_SIGN";
		break;
	default:
		break;
	}

	
	return result;
}

string DefineTypeDualOperator(string name)
{
	string result;
	char cstr, cstrNext;
	cstr = name[0];
	cstrNext = name[1];
	int nChar = cstr;
	int nChNext = cstrNext;
	
	if (nChar == 60 && nChNext == 62)
		result = "NE_OP";
	if (nChar == 60 && nChNext == 61)
		result = "LE_OP";
	if (nChar == 62 && nChNext == 61)
		result = "GE_OP";
	if (nChar == 58 && nChNext == 61)
		result = "ASSIGN";
	if (nChar == 46 && nChNext == 46)
		result = "ELLIPSIS";

	return result;
}

string DefineTypeDeviders(string name)
{
	string result;
	char cstr = name[0];
	//strcpy(&cstr, name.c_str());
	int nChar = cstr;

	switch (nChar)
	{
	case 39:
		result = "HIGH_COMMA";
		break;
	case 46:
		result = "DOT";
		break;
	case 44:
		result = "COMMA";
		break;
	case 58:
		result = "COLON";
		break;
	case 59:
		result = "SEMICOLON";
		break;
	case 40:
		result = "PARENTHESIS_L";
		break;
	case 41:
		result = "PARENTHESIS_R";
		break;
	case 91:
		result = "BRACKET_L";
		break;
	case 93:
		result = "BRACKET_R";
		break;
	case 123:
		result = "BRACE_L";
		break;
	case 125:
		result = "BRACE_R";
		break;
	default:
		break;
	}

	return result;
}

string DefineResWord(string name)
{
	string result;

	if (name == "ARRAY" || name == "array")
		result = "ARRAY";
	else if (name == "AND" || name == "and")
		result = "AND_OP";
	else if (name == "BEGIN" || name == "begin")
		result = "BEGIN";
	else if (name == "CASE" || name == "case")
		result = "CASE";
	else if (name == "CONST" || name == "const")
		result = "CONST";
	else if (name == "DIV" || name == "div")
		result = "DIV";
	else if (name == "DO" || name == "do")
		result = "DO";
	else if (name == "DOWNTO" || name == "downto")
		result = "DOWNTO";
	else if (name == "ELSE" || name == "else")
		result = "ELSE";
	else if (name == "END" || name == "end")
		result = "END";
	else if (name == "EXPORT" || name == "export")
		result = "EXPORT";
	else if (name == "FUNCTION" || name == "function")
		result = "FUNCTION";
	else if (name == "GOTO" || name == "goto")
		result = "GOTO";
	else if (name == "IF" || name == "if")
		result = "IF";
	else if (name == "OR" || name == "or")
		result = "OR_OP";
	else if (name == "PRIVATE" || name == "private")
		result = "PRIVATE";
	else if (name == "PROCEDURE" || name == "procedure")
		result = "PROCEDURE";
	else if (name == "PROGRAM" || name == "program")
		result = "PROGRAM";
	else if (name == "IN" || name == "in")
		result = "IN";
	else if (name == "INTERFACE" || name == "interface")
		result = "INTERFACE";
	else if (name == "MOD" || name == "mod")
		result = "MOD";
	else if (name == "NAME" || name == "name")
		result = "NAME";
	else if (name == "NIL" || name == "nil")
		result = "NIL";
	else if (name == "NEAR" || name == "near")
		result = "NEAR";
	else if (name == "NOT" || name == "not")
		result = "NE_OP";
	else if (name == "OBJECT" || name == "object")
		result = "OBJECT";
	else if (name == "RECORD" || name == "record")
		result = "RECORD";
	else if (name == "PUBLIC" || name == "public")
		result = "PUBLIC";
	else if (name == "REPEAT" || name == "repeat")
		result = "REPEAT";
	else if (name == "FOR" || name == "for")
		result = "FOR";
	else if (name == "SET" || name == "set")
		result = "SET";
	else if (name == "STRING" || name == "string")
		result = "STRING";
	else if (name == "THEN" || name == "then")
		result = "THEN";
	else if (name == "TO" || name == "to")
		result = "TO";
	else if (name == "TYPE" || name == "type")
		result = "TYPE";
	else if (name == "UNIT" || name == "unit")
		result = "UNIT";
	else if (name == "UNTIL" || name == "until")
		result = "UNTIL";
	else if (name == "USES" || name == "uses")
		result = "USES";
	else if (name == "VAR" || name == "var")
		result = "VAR";
	else if (name == "VIRTUAL" || name == "virtual")
		result = "VIRTUAL";
	else if (name == "WHILE" || name == "while")
		result = "WHILE";
	else if (name == "WITH" || name == "with")
		result = "WITH";
	else if (name == "REAL" || name == "real")
		result = "REAL";
	else if (name == "LONGINT" || name == "longint")
		result = "LONGINT";
	else if (name == "XOR" || name == "xor")
		result = "XOR_OP";
	else if (name == "INTEGER" || name == "integer")
		result = "INTEGER";
	else if (name == "CHAR" || name == "char")
		result = "CHAR";
	else if (name == "TEXT" || name == "text")
		result = "TEXT";
	else if (name == "WRITE" || name == "write")
		result = "WRITE";
	else if (name == "WRITELN" || name == "writeln")
		result = "WRITELN";
	else if (name == "READ" || name == "read")
		result = "READ";
	else if (name == "READLN" || name == "readln")
		result = "READLN";
	else if (name == "RESET" || name == "reset")
		result = "RESET";
	else if (name == "ASSIGN" || name == "assign")
		result = "ASSIGN";
	else if (name == "CLOSE" || name == "close")
		result = "CLOSE";
	else if (name == "NEW" || name == "new")
		result = "NEW";
	else if (name == "OF" || name == "of")
		result = "OF";

	
	return result;
}

string DefineSpecific(string name)
{
	string result;
	char cstr;
	cstr = name[0];
	int nChar = cstr;

	switch (nChar)
	{
	case 35:
		result = "SHARP";
		break;
	case 36:
		result = "DL_SIGN";//$
		break;
	case 94:
		result = "CIRCUMFLEX";//^
		break;
	default:
		break;
	}
	return result;
}
