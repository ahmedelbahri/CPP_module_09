#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>
#include <stack>

class RPN
{
private:
	std::stack<float>	stack;
public:
						RPN(void);
						RPN(RPN const &rpn);
	RPN					&operator = (RPN const &var);
						~RPN(void);

	void				evaluate_expresssion(std::string exp);
};

void	error_stdout(std::string str);

#endif
