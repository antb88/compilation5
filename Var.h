//
// Created by ant on 5/14/16.
//

#ifndef HW4_VAR_H
#define HW4_VAR_H

#include <string>

using std::string;
enum VarType {TYPE_BOOL, TYPE_DECIMAL, TYPE_BINARY, TYPE_HEXIDECIMAL};

class Var {

public:
    Var(const string name, VarType varType, string place);
    const string &getName() const;
    string getType() const;
    const string& getPlace() const;
    VarType getVarType() const;
    bool operator==(const Var& rhs);
    void print(unsigned varOffset);
    static string getStringOfType(VarType type);

private:
    const string name;
    const string place;
    VarType type;


};




#endif //HW4_VAR_H
