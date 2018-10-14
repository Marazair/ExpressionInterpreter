class And : public SubExpression
{
public:
	And(Expression* left, Expression* right) :
		SubExpression(left, right)
	{
	}
	int evaluate()
	{
		if ((left->evaluate() > 0) && (right->evaluate() > 0))
			return 1;
		else
			return 0;
	}
};