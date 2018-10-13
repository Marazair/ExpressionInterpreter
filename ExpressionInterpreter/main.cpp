#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"

SymbolTable symbolTable;

void parseAssignments(ifstream &in);

int main()
{
	ifstream in("input.txt");
	Expression* expression;
	char paren, comma;

	while (!in.eof())
	{
		in >> paren;
		expression = SubExpression::parse(in);
		in >> comma;
		parseAssignments(in);
		cout << "Value = " << expression->evaluate() << endl;
	}

	in.close();
	return 0;
}

void parseAssignments(ifstream &in)
{
	char assignop, delimiter;
	string variable;
	double value;
	do
	{
		variable = parseName(in);
		in >> ws >> assignop >> value >> delimiter;
		symbolTable.insert(variable, value);
	} while (delimiter == ',');
}