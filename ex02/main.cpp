#include "PmergeMe.hpp"

void	error_stdout(std::string str)
{
	std::cout << "Error: " << str << std::endl;
	exit(1);
}

int main(int ac, char **av)
{
	if (ac < 2)
		error_stdout("invalid input.");
	PmergeMe pmergeMe;
	av++;
	pmergeMe.initiate(av);
	return (0);
}
