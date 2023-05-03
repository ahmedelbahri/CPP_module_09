#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	std::ifstream	file("./database/data.csv");
	if (file.fail())
		error("failed to open file.");
	std::string		content;
	std::getline(file, content);
	while (std::getline(file, content))
	{
		std::string	date, rate;
		split(date, rate, content, ',');
		this->data[date] = std::stof(rate);
	}
	file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange	&BitcoinExchange::operator = (BitcoinExchange const &bitcoinExchange)
{
	this->data = bitcoinExchange.data;
	return (*this);
}

void	BitcoinExchange::trim(std::string &str)
{
	size_t start = str.find_last_not_of(" \t");
	if (start != std::string::npos)
		str = str.substr(0, start + 1);
	start = str.find_first_not_of(" \t");
	if (start != std::string::npos)
		str = str.substr(start, str.length() - start + 1);
}

bool	BitcoinExchange::split(std::string &date, std::string &value, std::string content, char delim)
{
	size_t pos = content.find(delim);
	if (pos == std::string::npos)
		return (error(std::string("bad input => ") + content, false));
	date = content.substr(0, pos), trim(date);
	value = content.substr(pos + 1), trim(value);
	return (true);
}

bool	BitcoinExchange::checkdate(std::string date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (error(std::string("bad date input => ") + date, false));
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return (error(std::string("bad date input => ") + date, false));
	}
	int	year = atoi(date.substr(0, 4).c_str());
	int	month = atoi(date.substr(5, 2).c_str());
	int	day = atoi(date.substr(8, 2).c_str());
	if ((year < 0)
		|| (month < 1 || month > 12)
		|| (month % 2 == 0 && day > 30)
		|| (month % 2 && day > 31)
		|| (day < 1 || day > 31)
		|| (month == 2 && year % 4 && day > 28)
		|| (month == 2 && year % 4 == 0 && day > 29))
		return (error(std::string("bad date input => ") + date, false));
	return (true);
}

bool	BitcoinExchange::checkvalue(std::string	value)
{
	bool	decimal = true;
	if (value.length() == 0)
		return (error("no value input.", false));
	if (value[0] == '-')
		return (error("not a positive number.", false));
	for (size_t i = 0; i < value.length(); i++)
	{
		if (value[i] == '.')
		{
			if (decimal)
				decimal = false;
			else
				return (error(std::string("bad value input => ") + value, false));
		}
		else if (!isdigit(value[i]))
			return (error(std::string("bad value input => ") + value, false));
	}
	if (atol(value.c_str()) > 2147483647)
		return (error("too large a number.", false));
	return (true);
}

float	BitcoinExchange::checkdatabase(std::string date, std::string value)
{
	std::map<std::string, float>::iterator	it = this->data.find(date);
	if (it == this->data.end())
	{
		if (atoi((date.substr(0, 4)).c_str()) < 2009
			|| ((!(date.substr(0, 4)).compare("2009")) && atoi((date.substr(8, 2)).c_str()) <= 1))
			return (0);
		for (it = this->data.begin(); it != this->data.end(); ++it)
		{
			if (atoi(((it->first).substr(0, 4)).c_str()) >= atoi((date.substr(0, 4)).c_str()))
				if (atoi(((it->first).substr(5, 2)).c_str()) >= atoi((date.substr(5, 2)).c_str()))
					if (atoi(((it->first).substr(8, 2)).c_str()) >= atoi((date.substr(8, 2)).c_str()))
						return ((--it)->second * atof(value.c_str()));
		}
		return ((--data.end())->second * atof(value.c_str()));
	}
	return (it->second * atof(value.c_str()));
}

void	BitcoinExchange::get_rates(std::string file)
{
	std::ifstream	infile(file);
	if (infile.fail())
		error("Failed to open file.");
	std::string		content;
	int i = 0;
	while (getline(infile, content))
	{
		if ( i++ == 0 && (!content.compare("date | value")))
			continue;
		std::string	date;
		std::string	value;
		if (split(date, value, content, '|') && checkdate(date) && checkvalue(value))
			std::cout << date << " => " << value << " = " << checkdatabase(date, value) << std::endl;
	}
	infile.close();
}

BitcoinExchange::~BitcoinExchange(void)
{
	return;
}
