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
	ifstream in;
	ofstream out;
	string inFileName;
	string outFileName;
	Expression* expression;
	char paren, comma;

	cout << "Input file name: ";
	cin >> inFileName;
	in = ifstream(inFileName);

	cout << "Output file name: ";
	cin >> outFileName;
	out = ofstream(outFileName);

	in >> paren;
	while (!in.eof())
	{
		try {
			expression = SubExpression::parse(in);
			in >> comma;
			parseAssignments(in);
			out << "Value = " << expression->evaluate() << endl;
		}
		catch (const char* message) {
			out << "Problem with line: " << message << endl;
		}

		symbolTable.reset();
		in >> paren;
	}

	cout << "Evaluation complete. Output written to file." << endl;
	system("pause");

	in.close();
	return 0;
}

void parseAssignments(ifstream &in)
{
	char assignop, delimiter;
	string variable;
	int value;
	do
	{
		variable = parseName(in);
		in >> ws >> assignop >> value >> delimiter;
		symbolTable.insert(variable, value);
	} while (delimiter == ',');
}