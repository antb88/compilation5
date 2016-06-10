
all: 
	bison -d source.ypp && lex source.lex  && g++ -o ex5.exe lex.yy.c SymbolTable.cpp output.cpp Var.cpp bp.cpp source.tab.cpp -std=c++11

install : all
	cp ex5.exe /home/ant/Workspace/compilation/hw4/test  

