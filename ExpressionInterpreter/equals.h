class Equals : public SubExpression
{
public:
	Equals(Expression* left, Expression* right) :
		SubExpression(left, right)
	{
	}
	double evaluate()
	{
		if (left->evaluate() == right->evaluate())
			return 1;
		else
			return 0;
	}
};