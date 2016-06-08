//
// Created by ant on 5/14/16.
//
#include "simple_test.hpp"
#include "SymbolTable.hpp"
#include "SymbolTableTest.hpp"
#include "output.hpp"

using std::streambuf;
using std::cout;
using std::ostringstream;


void testAddVar();
void testNewScopeCreatesNewScope();
void testDeleteScopeDeletesCurrentScope();
void testPrintScope();
void testDefinedInScope();
void testDefinedAnywhere();
void testPrintInnerScope();
void testDeleteNonEmptyScopePrints();
void testGetTypeOf();


void symbol_table_test::run_tests() {
    RUN_TEST(testAddVar);
    RUN_TEST(testNewScopeCreatesNewScope);
    RUN_TEST(testDeleteScopeDeletesCurrentScope);
    RUN_TEST(testDeleteNonEmptyScopePrints);
    RUN_TEST(testPrintScope);
    RUN_TEST(testDefinedInScope);
    RUN_TEST(testDefinedAnywhere);
    RUN_TEST(testPrintInnerScope);
    RUN_TEST(testGetTypeOf);
    std::cerr << "SymbolTable_TEST [OK]" << std::endl;
    std::flush(std::cerr);

}


void testAddVar() {
    SymbolTable st;
    st.addVar("v", VarType::TYPE_BINARY);
    st.addVar("v1", VarType::TYPE_BOOL);
    st.addVar("v2", VarType::TYPE_DECIMAL);
    st.addVar("v3", VarType::TYPE_HEXIDECIMAL);
    ASSERT_EQUALS(true, st.isDefinedInScope("v", VarType::TYPE_BINARY));
    ASSERT_EQUALS(true, st.isDefinedInScope("v1", VarType::TYPE_BOOL));
    ASSERT_EQUALS(true, st.isDefinedInScope("v2", VarType::TYPE_DECIMAL));
    ASSERT_EQUALS(true, st.isDefinedInScope("v3", VarType::TYPE_HEXIDECIMAL));

}

void testNewScopeCreatesNewScope() {
    SymbolTable st;
    st.addVar("v", VarType::TYPE_BINARY);
    ASSERT_EQUALS(true, st.isDefinedInScope("v", VarType::TYPE_BINARY));
    st.newScope();
    ASSERT_EQUALS(false, st.isDefinedInScope("v", VarType::TYPE_BINARY));
    st.addVar("v", VarType::TYPE_BINARY);
    ASSERT_EQUALS(true, st.isDefinedInScope("v", VarType::TYPE_BINARY));

}

void testDeleteScopeDeletesCurrentScope() {
    SymbolTable st;
    st.addVar("v", VarType::TYPE_BINARY);
    ASSERT_EQUALS(true, st.isDefinedInScope("v", VarType::TYPE_BINARY));
    st.newScope();
    ASSERT_EQUALS(false, st.isDefinedInScope("v", VarType::TYPE_BINARY));
    st.deleteAndPrintScope();
    ASSERT_EQUALS(true, st.isDefinedInScope("v", VarType::TYPE_BINARY));
}

void testDeleteNonEmptyScopePrints() {
    SymbolTable st;
    st.addVar("v", VarType::TYPE_BINARY);
    streambuf *oldCoutStreamBuf = cout.rdbuf();
    ostringstream actual;
    cout.rdbuf(actual.rdbuf());
    st.deleteAndPrintScope();
    ostringstream expected;
    cout.rdbuf(expected.rdbuf());
    output::endScope();
    output::printVar("v",0, Var::getStringOfType(VarType::TYPE_BINARY).c_str());
    cout.rdbuf(oldCoutStreamBuf);
    ASSERT_EQUALS(actual.str(), expected.str());

}

void testPrintScope() {

    streambuf *oldCoutStreamBuf = cout.rdbuf();
    ostringstream actual;
    cout.rdbuf(actual.rdbuf());
    SymbolTable st;
    st.addVar("v1", VarType::TYPE_BINARY);
    st.addVar("v2", VarType::TYPE_DECIMAL);
    st.addVar("v3", VarType::TYPE_HEXIDECIMAL);

    st.printScope();
    ostringstream expected;
    cout.rdbuf(expected.rdbuf());

    output::printVar("v1", 0, Var::getStringOfType(VarType::TYPE_BINARY).c_str());
    output::printVar("v2", 1, Var::getStringOfType(VarType::TYPE_DECIMAL).c_str());
    output::printVar("v3", 2, Var::getStringOfType(VarType::TYPE_HEXIDECIMAL).c_str());
    cout.rdbuf(oldCoutStreamBuf);
    ASSERT_EQUALS(actual.str(), expected.str());


}

void testPrintInnerScope() {

    streambuf *oldCoutStreamBuf = cout.rdbuf();
    ostringstream actual;
    cout.rdbuf(actual.rdbuf());
    SymbolTable st;
    st.addVar("v1", VarType::TYPE_BINARY);
    st.addVar("v2", VarType::TYPE_DECIMAL);
    st.addVar("v3", VarType::TYPE_HEXIDECIMAL);
    st.newScope();
    st.addVar("v1", VarType::TYPE_BINARY);
    st.addVar("v2", VarType::TYPE_DECIMAL);
    st.addVar("v3", VarType::TYPE_HEXIDECIMAL);
    st.printScope();
    ostringstream expected;
    cout.rdbuf(expected.rdbuf());

    output::printVar("v1", 3, Var::getStringOfType(VarType::TYPE_BINARY).c_str());
    output::printVar("v2", 4, Var::getStringOfType(VarType::TYPE_DECIMAL).c_str());
    output::printVar("v3", 5, Var::getStringOfType(VarType::TYPE_HEXIDECIMAL).c_str());
    cout.rdbuf(oldCoutStreamBuf);
    ASSERT_EQUALS(actual.str(), expected.str());

}

void testDefinedInScope() {
    SymbolTable st;
    st.addVar("v", VarType::TYPE_BINARY);
    ASSERT_TRUE(st.isDefinedInScope("v", VarType::TYPE_BINARY));
    ASSERT_FALSE(st.isDefinedInScope("vv", VarType::TYPE_BINARY));
    ASSERT_FALSE(st.isDefinedInScope("v", VarType::TYPE_HEXIDECIMAL));

}

void testDefinedAnywhere() {
    SymbolTable st;
    st.addVar("v", VarType::TYPE_BINARY);
    ASSERT_TRUE(st.isDefinedInScope("v", VarType::TYPE_BINARY));
    st.newScope();
    ASSERT_FALSE(st.isDefinedInScope("v", VarType::TYPE_BINARY));
    ASSERT_TRUE(st.isDefined("v", VarType::TYPE_BINARY));
    ASSERT_TRUE(st.isDefined("v"));
}

void testGetTypeOf() {
    SymbolTable st;
    st.addVar("v", VarType::TYPE_BINARY);
    st.newScope();
    st.addVar("v", VarType::TYPE_HEXIDECIMAL);
    ASSERT_EQUALS(VarType::TYPE_HEXIDECIMAL, st.getTypeOf("v"));

}

