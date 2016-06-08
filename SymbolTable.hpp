//
// Created by ant on 5/14/16.
//

#ifndef HW4_SYMBOLTABLE_H
#define HW4_SYMBOLTABLE_H

#include <string>
#include <stack>
#include <vector>
#include "Var.h"


using std::string;
using std::vector;

class Scope;

class SymbolTable {

    class Scope {
    public:
        Scope(unsigned offset);

        bool addVar(Var &var);

        bool contains(Var &var);

        bool contains(const string &varName);

        unsigned  offset() const;

        void print();

        unsigned long size();

        VarType getTypeOf(const string &varName);

        string getPlaceOf(const string &varName);

    private:
        vector<Var> mVars;
        unsigned mOffset;
    };


public:
    friend class Scope;

    SymbolTable();

    bool addVar(const string &varName, VarType type, string place);

    bool newScope();

    void deleteAndPrintScope();

    void deleteScope();

    void printScope();

    bool isDefinedInScope(const string &varName);

    bool isDefined(const string &varName, VarType type);

    bool isDefined(const string &varName);

    VarType getTypeOf(const string &varName);

    string getPlaceOf(const string &varName);

    Scope currentScope();


private:
    vector<Scope> mStack;

    unsigned long currentOffset();


};


#endif //HW4_SYMBOLTABLE_H
