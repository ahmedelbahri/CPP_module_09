#include "BitcoinExchange.hpp"

bool	error(std::string str, bool Exit)
{
	std::cerr << "Error: " << str << std::endl;
	if (Exit == true)
		exit(1);
	return (false);
}

int main(int ac, char **av)
{
	if (ac != 2)
		error("could not open file.");
	BitcoinExchange	btc;
	btc.get_rates(av[1]);
	return (0);
}
