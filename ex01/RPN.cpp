#include "RPN.hpp"

RPN::RPN(void)
{
	return;
}

RPN::RPN(const RPN &rpn)
{
	*this = rpn;
}

RPN	&RPN::operator = (RPN const &rpn)
{
	this->stack = rpn.stack;
	return (*this);
}

void	RPN::evaluate_expresssion(std::string exp)
{
	int		save;
	for (int i = 0; exp[i]; i++)
	{
		if (exp[i] == ' ')
			continue;
		if (isdigit(exp[i]))
			this->stack.push(exp[i] - 48);
		else
		{
			if (this->stack.size() < 2)
				std::cout << "Error" << std::endl, exit(1);
			save = this->stack.top(), this->stack.pop();
			switch (exp[i])
			{
				case '+':
					this->stack.top() += save;
					break;
				case '-':
					this->stack.top() -= save;
					break;
				case '*':
					this->stack.top() *= save;
					break;
				case '/':
					this->stack.top() /= save;
					break;
				default:
					error_stdout("invalid operator.");
			}
		}
	}
	std::cout << this->stack.top() << std::endl;
}

RPN::~RPN(void)
{
	return;
}