class Operand : public Expression
{
public:
	static Expression* parse(istream &in);
};