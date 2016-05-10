// RGR.cpp: определяет точку входа для консольного приложения.
//


#pragma warning(disable : 4996)

#include "stdafx.h"
#include "DefineType.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

vector<string>  ArrayResWords = { "ARRAY", "array", "absolute", "ABSOLUTE", "absolute", "assembler", "ASSEMBLER", "AND", "and", "ASM", "asm", "BEGIN",
"begin", "CASE", "case", "CONST", "const", "CONSTRUCTOR", "constructor", "DESTRUCTOR", "destructor", "DIV", "div", "DO", "do", "DOWNTO", "downto", "ELSE", "else",
"END", "end", "EXPORT", "export", "EXPORTS", "EXTERNAL", "FAR", "FOR", "for", "FORWARD", "FUNCTION", "function" "GOTO", "goto",
"IF", "if", "IN", "in", "IMPLEMENTATION", "implementation", "INDEX", "INHERITED", "INLINE", "INTERFACE", "interface",
"INTERRUPT", "LABEL", "LIBRARY", "MOD", "mod", "NAME", "name", "NIL", "nil", "NEAR", "near", "NOT", "OBJECT", "object",
"OF", "of", "OR", "PACKED", "PRIVATE", "private", "PROCEDURE", "procedure", "PROGRAM", "program", "RECORD", "record", "PUBLIC", "public",
"REPEAT", "repeat", "RESIDENT", "SET", "set", "SHL", "SHR", "STRING", "string", "THEN", "then", "TO", "to", "TYPE", "type",
"UNIT", "unit", "UNTIL", "until", "USES", "uses", "VAR", "var", "VIRTUAL", "virtual", "WHILE", "while", "WITH", "with", "XOR", "char", "integer", "INTEGER",
"real", "REAL", "LONGINT", "CHAR",
"text", "TEXT", "WRITE", "write", "WRITELN", "writeln", "read", "READ", "READLN", "readln", "longint",
"ASSIGN", "assign", "RESET", "reset", "NEW", "new", "CLOSE", "close" };  //зарезервированные слова

string Operators = "+-*/=><@"; // <>", "<=", ">=", ":=
string	Deviders = ".,'()[]{};:"; // "..", "(* *)", "(..)"        //разделители

string Specific = "^$#";

unsigned int g_IndexI,  Offset;



void DefineTypeToken(string & name, vector<MyStruct> & table)
{
	MyStruct token;
	token.name = name;
	token.position = g_IndexI;
	
	if (Deviders.find(token.name) != Deviders.npos)
	{
		token.type = tDevider;
	}
	
	else if (Operators.find(token.name) != Operators.npos)
	{
		token.type = tOperator;
	}
	else if (Specific.find(token.name) != Specific.npos)
	{
		token.type = tSpecific;
	}
	
	else if (find(ArrayResWords.begin(), ArrayResWords.end(), token.name) !=
		ArrayResWords.end())
	{
		token.type = tResWord;
	}

	else
	{
		unsigned i;
		bool bFloat = false;
		for (i = 0; i < token.name.length(); ++i)
		{	
			int nChar = token.name[i];
			if (token.name[i] == '.')
				bFloat = true;
			if (!isdigit(token.name[i]) && token.name[i] != '.' && nChar != 45 && nChar != 36)
				break;
		}

		if (i == token.name.length())
		{
			if (!bFloat)
			{
				token.type = tIntConstant;
			}
			else
			{
				token.type = tFloatConst;
			}
		}

		else
		{
			token.type = tVariable;
		};
	}
	table.push_back(token);
	name.clear();
}

string ReadFromFile(_TCHAR * file)
{
	ifstream ifs(file);
	string s;
	s.assign((istreambuf_iterator<char>(ifs.rdbuf())), istreambuf_iterator<char>());
	ifs.close();
	return s;
}

void Error(string & word, vector<MyStruct> & table, string & s)
{
	MyStruct token;
	token.name = word;
	token.position = g_IndexI;
	token.type = tUnknown;
	table.push_back(token);
	word.clear();
	Offset = s.size() - 1;
}

bool DualOperators(char cWord, string & s)
{
	if (Offset != s.size())
	{
		int pp = cWord;
		int pr = s[Offset + 1];
		if ((pp == 61 && pr == 61) || (pp == 62 && pr == 61) || (pp == 60 && pr == 61) || (pp == 58 && pr == 61) || (pp == 60 && pr == 62) || (pp == 46 && pr == 46))
		{
			return true;
		}
	}
	return false;
}

void Letters(string & s, string & word, vector<MyStruct> & table)
{
	/*s - строка где храниться весь код,
	word - слово куда мы добавляем символы после проверки
	table - вектор с токенами*/
	string strDev;
	bool circle = true;
	do{	
		Offset++;
		strDev += s[Offset];
		if ((s[Offset] >= 'a' && s[Offset] <= 'z') || (s[Offset] >= 'A' && s[Offset] <= 'Z'))
			/*если следующий символ буква, то продолжаем*/
		{
			word += s[Offset];
		}
		else if (s[Offset] >= '0' && s[Offset] <= '9')
			/*если следующий символ цифра, то продолжаем*/
		{
			word += s[Offset];
		}
		else if (s[Offset] == '\n')
			/*если следующий символ перенос строки, то определяем тип токена, который у нас был в слове
			увеличивем счетчик строк, прерываем цикл*/
		{
			if (word.size() != 0)
			{
				DefineTypeToken(word, table);
				word.clear();
			}
			g_IndexI++;
			circle = false;
		}
		else if ((Deviders.find(strDev) != Deviders.npos) || (Specific.find(strDev) != Specific.npos))
			/*если следующий символ относится к разделителям или операторам, то сначала определяем токен, который
			был в слове, затем проверяем на двойной оператор и далее определяем считанный символ*/
		{
			DefineTypeToken(word, table);
			word.clear();
			if (DualOperators(s[Offset], s))
			{
				word += s[Offset];
				Offset++;
				word += s[Offset];
				MyStruct token;
				token.name = word;
				token.position = g_IndexI;
				token.type = tDualOperator;
				table.push_back(token);
				word.clear();
				circle = false;
			}
			else
			{
				word += s[Offset];
				DefineTypeToken(word, table);
				circle = false;
				word.clear();
			}
		}
		else if (s[Offset] == ' ')
			/*если следующий символ пробел, то если слово не пустое, то
			определяем тип токена, инче просто продолжаем*/
		{
			if (word.size() != 0)
			{
				DefineTypeToken(word, table);
				word.clear();
				circle = false;
			}
			else
			{
				continue;
			}
		}
		else
			/*если следующий символ не прошел условия, то прерываем цикл*/
		{
			if (word.size() != 0)
			{
				DefineTypeToken(word, table);
				word.clear();
			}
			circle = false;
		}

		strDev.clear();
	} while (circle);


}

void Digits(string & s, string & word, vector<MyStruct> & table)
{
	/*s - строка где храниться весь код,  
	word - слово куда мы добавляем символы после проверки
	table - вектор с токенами*/
	bool circle = true;
	bool isFloat = false;
	string strDev;
	MyStruct token;
	do{
		Offset++;
		strDev += s[Offset];
		if ((s[Offset] >= 'a' && s[Offset] <= 'z') || (s[Offset] >= 'A' && s[Offset] <= 'Z'))
			/*если следующий символ буква, то ошибка*/
		{
			circle = false;
			word += s[Offset];
			Error(word, table, s);
		}
		else if (s[Offset] >= '0' && s[Offset] <= '9')
			/*если следующий символ цифра, то продолжаем*/
		{
			word += s[Offset];
		}
		else if (s[Offset] == '\n')
			/*если следующий символ перенос строки, то определяем тип токена, который у нас был в слове
			увеличивем счетчик строк, прерываем цикл*/
		{
			DefineTypeToken(word, table);
			word.clear();
			g_IndexI++;
			circle = false;
		}
		else if (s[Offset] == '.' && (s[Offset + 1] >= '0' && s[Offset + 1] <= '9') && !isFloat)
			/*если следующий символ точка, то проверяем может ли это быть float,
			также у нас есть флаг, который исключает повтора точек (12.1212.12)*/
		{	
			isFloat = true;
			word += s[Offset];
			continue;
		}
		else if ((Deviders.find(strDev) != Deviders.npos) || (Operators.find(strDev) != Operators.npos)) 
			/*если следующий символ относится к разделителям или операторам, то сначала определяем токен, который
			был в слове, затем проверяем на двойной оператор и далее определяем считанный символ*/
		{
			DefineTypeToken(word, table);
			word.clear();
			if (DualOperators(s[Offset], s))
			{
				word += s[Offset];
				Offset++;
				word += s[Offset];
				MyStruct token1;
				token1.name = word;
				token1.position = g_IndexI;
				token1.type = tDualOperator;
				table.push_back(token1);
				word.clear();
				circle = false;
			}
			else
			{
				word += s[Offset];
				DefineTypeToken(word, table);
				circle = false;
				word.clear();
			}
		}
		else if (s[Offset] == ' ')
			/*если следующий символ пробел, то если слово не пустое, то 
			определяем тип токена, инче просто продолжаем*/
		{
			if (word.size() != 0)
			{
				DefineTypeToken(word, table);
				word.clear();
				circle = false;
			}
			else
			{
				continue;
			}
		}
		else
			/*если следующий символ не прошел условия, то прерываем цикл*/
		{
			circle = false;
		}
		strDev.clear();
	} while (circle);
}

bool FindInVector(char cWord)
{
	int pp = cWord;
	if (pp == 43 || pp == 42 || pp == 45 || pp == 47 || (pp >= 60 && pp <= 62))
	{
		return true;
	}
	return false;
}


void SkipComment(string & s, char cSymbol)
{
	if (cSymbol == '{')
	{
		while (s[Offset] != '}')
		{
			Offset++;
		}
	}
	else if (cSymbol == '(')
	{
		for (unsigned int i = Offset + 1; i < s.size(); i++)
		{
			if (s[i - 1] == '*' && s[i] == ')')
			{
				Offset = i;
				break;
			}
		}
	}
	else
	{
		while (s[Offset] != '\n')
		{
			Offset++;
		}
		g_IndexI++;
	}
}

void DefineConstStr(string & s, string & word, vector<MyStruct> & table)
{
	MyStruct token;
	int nOffset = 0;
	do{
		Offset++;
		nOffset = s[Offset];
		word += s[Offset];
	} while (nOffset != 39);
	word.erase(word.begin() + (word.size()-1));
	token.name = word;
	token.position = g_IndexI;
	token.type = tStrConstant;
	table.push_back(token);
	word.clear();
	word += s[Offset];
	DefineTypeToken(word, table);
}

bool FindInVectorDev(char cWord)
{
	int pp = cWord;
	if(pp == 39 || pp == 46 || pp == 44 || pp == 58 || pp == 59 || pp == 91 || pp == 93 || pp == 123 || pp == 125 || pp == 40 || pp == 41)
	{
		return true;
	}
	return false;
}

void Parser(string & s, vector<MyStruct> & table)
{
	Offset = -1;
	g_IndexI = 1;
	MyStruct token;
	string sWord, strDev;
	while (Offset != s.size() - 1)
	{	
		Offset++;
		int nOffset = s[Offset];
		if ((s[Offset] >= 'a' && s[Offset] <= 'z') || (s[Offset] >= 'A' && s[Offset] <= 'Z') || s[Offset] == '_') //|| s[Offset] == '_'
		{
			sWord += s[Offset];
			Letters(s, sWord, table);
		}
		else if (s[Offset] >= '0' && s[Offset] <= '9' || s[Offset] == '$')
		{
			sWord += s[Offset];
			Digits(s, sWord, table);
		}
		else if (s[Offset] == '\n')
		{
			g_IndexI++;
			continue;
		}
		else if (s[Offset] == '\t')
		{
			if (sWord.size() != 0)
			{
				DefineTypeToken(sWord, table);
				sWord.clear();
			}
			continue;
		}
		else if (s[Offset] == '{' || ((s[Offset]) == '(' && s[Offset + 1] == '*') || ((s[Offset]) == '/' && s[Offset + 1] == '/'))
		{
			SkipComment(s, s[Offset]);
		}
		else if (nOffset == 45 && (s[Offset + 1] >= '0' && s[Offset + 1] <= '9'))
		{
			sWord += s[Offset];
			Digits(s, sWord, table);
		}
		else if (DualOperators(s[Offset], s))
		{
			sWord += s[Offset];
			Offset++;
			sWord += s[Offset];
			token.name = sWord;
			token.position = g_IndexI;
			token.type = tDualOperator;
			table.push_back(token);
			sWord.clear();
		}
		else if (FindInVector(s[Offset]))
		{
			sWord += s[Offset];
			DefineTypeToken(sWord, table);
		}
		else if (nOffset == 39)
		{
			sWord += s[Offset];
			DefineTypeToken(sWord, table);
			sWord.clear();
			DefineConstStr(s, sWord, table);
		}
		else if (FindInVectorDev(s[Offset]))
		{
			sWord += s[Offset];
			DefineTypeToken(sWord, table);
		}
		else if (s[Offset] == ' ')
		{
			continue;
		}
		else
		{
			Error(sWord, table, s);
		}
		strDev.clear();
	}
}


string sTypeToken(MyStruct & token)
{
	string result;
	switch (token.type)
	{
	case(tUnknown) :
		result = "ERROR";
		break;
	case(tDevider) :
		result = DefineTypeDeviders(token.name);
		break;
	case(tOperator) :
		result = DefineTypeOperator(token.name);
		break;
	case(tDualOperator) :
		result = DefineTypeDualOperator(token.name);
		break;
	case(tVariable) :
		result = "IDENTIFIER";
		break;
	case(tStrConstant) :
		result = "CONST_STRING";
		break;
	case(tIntConstant) :
		result = "CONST_INTEGER";
		break;
	case(tSpecific) :
		result = DefineSpecific(token.name);
		break;
	case(tFloatConst) :
		result = "CONST_FLOAT";
		break;
	case(tResWord) :
		result = DefineResWord(token.name);
		break;
	default :
		break;
	}

	return result;
}


void PrintResult(_TCHAR *file, vector<MyStruct> vector)
{
	ofstream fout(file);
	for (unsigned int i = 0; i < vector.size(); i++)
	{
		fout << vector[i].position << " " << sTypeToken(vector[i])  << " " << vector[i].name << endl;
	}

	fout.close();
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream fin(argv[1]);
	vector<MyStruct> trueCode;
	
	string s = ReadFromFile(argv[1]);
	Parser(s, trueCode);

	PrintResult(argv[2], trueCode);

	fin.close();

	return 0;
}

