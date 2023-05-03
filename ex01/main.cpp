#include "RPN.hpp"

void	error_stdout(std::string str)
{
	std::cout << "Error: " << str << std::endl;
	exit(1);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (error_stdout("usage: ./rpn <expression>"), 1);
	RPN	rpn;
	rpn.evaluate_expresssion(av[1]);
	return (0);
}