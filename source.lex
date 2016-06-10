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
(\=)	{
	yylval.lexema = yytext;
	return ASSIGN;
}
(\+)	{
	yylval.lexema = yytext;
	return PLUS;
}
(\-)	{
	yylval.lexema = yytext;
	return MINUS;
}
(\*)	{
	yylval.lexema = yytext;
	return MULT;
}
(\/)	{
	yylval.lexema = yytext;
	return DIV;
}
(<=)	{
	yylval.lexema = yytext;
	return EVEN_LT;
}
(>=)	{
	yylval.lexema = yytext;
	return EVEN_GT;
}
(==)	{
	yylval.lexema = yytext;
	return EVEN;
}
(!=)	{
	yylval.lexema = yytext;
	return NOT_EVEN;
}
(>)	{
	yylval.lexema = yytext;
	return GT;
}
(<)	{
	yylval.lexema = yytext;	
	return LT;
}				
and	{
	yylval.lexema = yytext;
	return AND;
}
or	{
	yylval.lexema = yytext;
	return OR;
}
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

