class Not : public SubExpression
{
public:
	Not(Expression* left) :
		SubExpression(left)
	{
	}
	double evaluate()
	{
		if (left->evaluate() > 0)
			return 0;
		else
			return 1;
	}
};