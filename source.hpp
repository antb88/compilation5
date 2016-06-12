#ifndef _SOURCE_HPP
#define _SOURCE_HPP
#include <string>
#include <iostream>
#include "SymbolTable.hpp"
#include "Var.h"
#include "output.hpp"
#include "bp.hpp"

using namespace output;
using namespace std;

class Attribute{
public:
	Attribute(){
		lexema = string();
		type = VarType::TYPE_DECIMAL;
	}
	string lexema;
	VarType type;
	string place;
	list<int> trueList, falseList, nextList, breakList;
	int next;
};

#define YYSTYPE Attribute
#endif


