//
// Created by ant on 5/14/16.
//
#include "Var.h"
#include "output.hpp"
#include "SymbolTable.hpp"

Var::Var(const string name, VarType varType, string place)
        : name(name), type(varType), place(place) { }


string Var::getType() const  {
    return getStringOfType(type);
}

VarType Var::getVarType() const  {
    return type;
}

const string &Var::getName() const {
    return name;
}

const string &Var::getPlace() const {
    return place;
}


bool Var::operator==(const Var &var) {
    return type == var.type && name == var.name;
}

void Var::print(unsigned varOffset) {
    output::printVar(name.c_str(),varOffset, getStringOfType(type).c_str());
}

string Var::getStringOfType(VarType type) {
    if (type == VarType::TYPE_BINARY) return "BINARY";
    else if (type == VarType::TYPE_BOOL) return "BOOL";
    else if (type == VarType::TYPE_DECIMAL) return "DECIMAL";
    else if (type == VarType::TYPE_HEXIDECIMAL) return "HEXIDECIMAL";
    else return "UNKNOWN";
}
















