#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <map>

class BitcoinExchange
{
private:
	std::map<std::string, float>	data;
public:
					BitcoinExchange(void);
					BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange	&operator = (const BitcoinExchange &bitcoinexchange);
					~BitcoinExchange(void);

	void			trim(std::string &str);
	void			get_rates(std::string file);
	bool			checkdate(std::string date);
	bool			checkvalue(std::string value);
	float			checkdatabase(std::string date, std::string value);
	bool			split(std::string &date, std::string &value, std::string content, char delim);
};

bool	error(std::string str, bool Exit = true);

#endif
