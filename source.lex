%{
/*Declarations section*/

#include <iostream>
#include <cstdlib>
#include "source.hpp"
#include "source.tab.hpp"
using namespace output;
%}

%option yylineno
%option noyywrap
whiteSpace	([\t\n\r ])
%%
(\()	return LP;
(\))	return RP;
(\{)	return LC;
(\})	return RC;
(\;)	return SC;
(\:)	return COL;
(\=)	return ASSIGN;
(\+)	return PLUS;
(\-)	return MINUS;
(\*)	return MULT;
(\/)	return DIV;
(<=)	return EVEN_LT;
(>=)	return EVEN_GT;
(==)	return EVEN;
(!=)	return NOT_EVEN;
(>)	return GT;
(<)	return LT;				
and	return AND;
or	return OR;
D 	return DECIMAL; 
B	return BINARY;												
H	return HEXIDECIMAL;													
int	return INT;													
print	return PRINT;
input	return INPUT;
\"[^"]*\" {
	yylval.lexema = yytext;
	return STRING;
}	
true	return TRUE;
false	return FALSE;
if		return IF;
else	return ELSE;
while  return WHILE;
break	return BREAK;
not     return NOT;
bool	{
	yylval.lexema = yytext;
	return BOOL;
}
([1-9][0-9]*|0|0x[1-9A-F][0-9A-F]*)	{
	yylval.lexema = yytext;
	yylval.type = VarType::TYPE_DECIMAL;
	return NUM;
}
switch	return SWITCH;
case	return CASE;
([a-zA-Z]+) {
	yylval.lexema = yytext;
	return ID;
}
"//"[^\n]*\n	{}
{whiteSpace}	{}
.				{errorLex(yylineno);exit(0);}

%%

