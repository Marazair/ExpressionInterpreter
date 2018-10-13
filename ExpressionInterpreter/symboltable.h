class SymbolTable
{
public:
	SymbolTable() {}
	void insert(string variable, double value);
	double lookUp(string variable) const;
	void reset();
private:
	struct Symbol
	{
		Symbol(string variable, double value)
		{
			this->variable = variable;
			this->value = value;
		}
		string variable;
		double value;
	};
	vector <Symbol> elements;
};