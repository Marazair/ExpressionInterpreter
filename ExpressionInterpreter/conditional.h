class Conditional : public SubExpression
{
public:
	Conditional(Expression* left, Expression* middle, Expression* right) :
		SubExpression(left, middle, right)
	{
	}
	double evaluate()
	{
		if (right->evaluate() > 0)
			return left->evaluate();
		else
			return middle->evaluate();
	}
};