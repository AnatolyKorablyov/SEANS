// stdafx.h: включаемый файл дл€ стандартных системных включаемых файлов
// или включаемых файлов дл€ конкретного проекта, которые часто используютс€, но
// не часто измен€ютс€
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <string>



// TODO: ”становите здесь ссылки на дополнительные заголовки, требующиес€ дл€ программы

enum typeToken
{
	tResWord,
	tOperator,    //оператор 1 
	tStrConstant, //строкова€ константа 1
	tIntConstant, //числова€ константа  1
	tVariable,    //переменна€ 1
	tDevider,     //разделитель
	tSpecific,
	tDualOperator,
	tFloatConst,
	tUnknown      //тип не определен, либо не известен
};

struct MyStruct
{
	typeToken type;
	int position;
	std::string name;
};