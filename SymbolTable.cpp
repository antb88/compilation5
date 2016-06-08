//
// Created by ant on 5/14/16.
//
#include "SymbolTable.hpp"
#include <iostream>
#include "output.hpp"

SymbolTable::SymbolTable() {

}

bool SymbolTable::newScope() {
    Scope s(currentOffset());
    mStack.push_back(s);
}

void SymbolTable::deleteScope() {
    mStack.pop_back();
}

void SymbolTable::deleteAndPrintScope() {
    Scope& s = mStack.back();
    output::endScope();
    s.print();
    mStack.pop_back();
}

void SymbolTable::printScope() {
    if (mStack.empty())
        return;
    Scope& current = mStack.back();
    current.print();
}

bool SymbolTable::addVar(const string& name, VarType type, string place) {
    if (mStack.empty()) {
        newScope();
    }
    Scope &currentScope = mStack.back();
    Var v(name, type, place);
    if (currentScope.contains(v)) {
        return false;
    }
    return currentScope.addVar(v);
}

bool SymbolTable::isDefinedInScope(const string& varName) {
    if (mStack.empty())
        return false;
    return mStack.back().contains(varName);
}

unsigned long SymbolTable::currentOffset() {
    return mStack.empty() ? 0 : mStack.back().offset() + mStack.back().size();
}

bool SymbolTable::isDefined(const string &varName, VarType type) {
    Var v(varName,type, "");
    for (auto& scopes : mStack) {
        if (scopes.contains(v))
            return true;
    }
    return false;
}
bool SymbolTable::isDefined(const string &varName) {
    for (auto& scope : mStack) {
        if (scope.contains(varName)) {
            return true;
        }
    }
    return false;
}

VarType SymbolTable::getTypeOf(const string &varName) {
    for (auto scope = mStack.rbegin(); scope != mStack.rend(); ++scope) {
        if ((*scope).contains(varName)) {
            return (*scope).getTypeOf(varName);
        }
    }
    return VarType::TYPE_DECIMAL;
}

string SymbolTable::getPlaceOf(const string &varName) {
    for (auto scope = mStack.rbegin(); scope != mStack.rend(); ++scope) {
        if ((*scope).contains(varName)) {
            return (*scope).getPlaceOf(varName);
        }
    }
    return " ";
}


SymbolTable::Scope SymbolTable::currentScope() {
    return mStack.back();
}


SymbolTable::Scope::Scope(unsigned offset) : mVars(), mOffset(offset) {

}

unsigned int SymbolTable::Scope::offset() const {
    return mOffset;
}

bool SymbolTable::Scope::addVar(Var &var) {
    if (contains(var)) return false;
    mVars.push_back(var);
    return true;
}

bool SymbolTable::Scope::contains(Var &var) {
    for (Var &v : mVars) {
        if (v == var) return true;
    }
    return false;
}

void SymbolTable::Scope::print() {
    unsigned scopeOffset = offset();
    unsigned varOffset = 0;
    for (Var& v : mVars) {
        v.print(scopeOffset + varOffset);
        varOffset++;
    }
}

unsigned long SymbolTable::Scope::size() {
    return mVars.size();
}

bool SymbolTable::Scope::contains( const string &varName) {
    for (Var &v : mVars) {
        if (v.getName() == varName) {
            return true;
        }
    }
    return false;
}

VarType SymbolTable::Scope::getTypeOf(const string &varName) {

    for (Var &v : mVars) {
        if (v.getName() == varName) {
            return v.getVarType();
        }
    }
    return TYPE_DECIMAL;
}

string SymbolTable::Scope::getPlaceOf(const string &varName) {
    for (Var &v : mVars) {
        if (v.getName() == varName) {
            return v.getPlace();
        }
    }
    return " ";
}


















