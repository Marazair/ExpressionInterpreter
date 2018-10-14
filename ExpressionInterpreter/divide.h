class Divide : public SubExpression
{
public:
	Divide(Expression* left, Expression* right) :
		SubExpression(left, right)
	{
	}
	int evaluate()
	{
		int x = left->evaluate();
		int y = right->evaluate();
		if (y != 0)
			return x / y;
		else
			throw "Divide by zero.";
	}
};