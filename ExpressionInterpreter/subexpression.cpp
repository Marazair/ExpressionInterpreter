#include <iostream>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "times.h"
#include "divide.h"
#include "lessthan.h"
#include "greaterthan.h"
#include "or.h"
#include "and.h"
#include "conditional.h"
#include "not.h"
#include "equals.h"

SubExpression::SubExpression(Expression * left)
{
	this->left = left;
}

SubExpression::SubExpression(Expression* left, Expression* right)
{
	this->left = left;
	this->right = right;
}

SubExpression::SubExpression(Expression* left, Expression* middle, Expression* right)
{
	this->left = left;
	this->middle = middle;
	this->right = right;
}
Expression* SubExpression::parse()
{
	Expression* left;
	Expression* middle;
	Expression* right;
	char operation, paren, query;

	left = Operand::parse();
	cin >> operation;
	switch (operation) 
	{
	case ':':
		middle = Operand::parse();
		cin >> query;
		right = Operand::parse();
		cin >> paren;
		return new Conditional(left, middle, right);
	case '!':
		cin >> paren;
		return new Not(left);
	}

	right = Operand::parse();
	cin >> paren;

	switch (operation)
	{
	case '+':
		return new Plus(left, right);
	case '-':
		return new Minus(left, right);
	case '*':
		return new Times(left, right);
	case '/':
		return new Divide(left, right);
	case '<':
		return new LessThan(left, right);
	case '>':
		return new GreaterThan(left, right);
	case '|':
		return new Or(left, right);
	case '&':
		return new And(left, right);
	case '=':
		return new Equals(left, right);
	}
	return 0;
}