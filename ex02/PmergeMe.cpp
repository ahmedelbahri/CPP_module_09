#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	return;
}

PmergeMe::PmergeMe(PmergeMe const &pmergeme)
{
	*this = pmergeme;
	return;
}

PmergeMe	&PmergeMe::operator = (PmergeMe const &pmergeme)
{
	this->vec = pmergeme.vec;
	this->list = pmergeme.list;
	return (*this);
}

void	PmergeMe::print_vec(void)
{
	for (std::vector<int>::iterator it = this->vec.begin(); it != this->vec.end(); it++)
	{
		std::cout << *it;
		if (it + 1 != vec.end())
			std::cout << " ";
		else
			std::cout << std::endl;
	}
}

void	PmergeMe::print_deque(void)
{
	for (std::deque<int>::iterator it = this->list.begin(); it != this->list.end(); it++)
	{
		std::cout << *it;
		if (it + 1 != this->list.end())
			std::cout << " ";
		else
			std::cout << std::endl;
	}
}

void	PmergeMe::merge_sort_vec(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	std::vector<int>::iterator begin1 = begin;
	std::vector<int>::iterator end1 = (begin + (end - begin) / 2);
	std::vector<int>::iterator begin2 = (begin + (end - begin) / 2);
	std::vector<int>::iterator end2 = end;
	if (end - begin > MERGE_SIZE)
	{
		this->merge_sort_vec(begin1, end1);
		this->merge_sort_vec(begin2, end2);
	}
	std::vector<int>	res;
	for (std::vector<int>::iterator i1 = begin1, i2 = begin2; i1 != end1 || i2 != end2;)
	{
		if (i2 == end2 || (i1 != end1 && *i1 < *i2))
			res.push_back(*i1++);
		else
			res.push_back(*i2++);
	}
	for (std::vector<int>::iterator i1 = res.begin(); i1 != res.end(); i1++, begin++)
		*begin = *i1;
}

void	PmergeMe::merge_sort_deque(std::deque<int>::iterator begin, std::deque<int>::iterator end)
{
	std::deque<int>::iterator begin1 = begin;
	std::deque<int>::iterator end1 = (begin + (end - begin) / 2);
	std::deque<int>::iterator begin2 = (begin + (end - begin) / 2);
	std::deque<int>::iterator end2 = end;
	if (end - begin > MERGE_SIZE)
	{
		this->merge_sort_deque(begin1, end1);
		this->merge_sort_deque(begin2, end2);
	}
	std::deque<int>	res;
	for (std::deque<int>::iterator i1 = begin1, i2 = begin2; i1 != end1 || i2 != end2;)
	{
		if (i2 == end2 || (i1 != end1 && *i1 < *i2))
			res.push_back(*i1++);
		else
			res.push_back(*i2++);
	}
	for (std::deque<int>::iterator i1 = res.begin(); i1 != res.end(); i1++, begin++)
		*begin = *i1;
}

void	PmergeMe::initiate(char **content)
{
	for (int i = 0; content[i]; i++)
	{
		int len = strlen(content[i]);
		for (int j = 0; content[i][j]; j++)
			if (!isdigit(content[i][j]) || len > 10)
				error_stdout("invalid input.");
		if (long res = atol(content[i]))
		{
			if (res > INT_MAX)
				error_stdout("invalid input.");
			this->vec.push_back(res);
			this->list.push_back(res);
		}
	}
	std::cout << "Before: ";
	this->print_vec();
	clock_t	start = clock(), end;
	this->merge_sort_vec(this->vec.begin(), this->vec.end());
	end = clock();
	double time = (double)(end - start) / 1000;
	start = clock();
	this->merge_sort_deque(this->list.begin(), this->list.end());
	end = clock();
	double time2 = (double)(end - start) / 1000;
	std::cout << "After: ";
	this->print_vec();
	std::cout << std::fixed << 	std::setprecision(5) << "Time to process a range of 5 elements with std::vector " << time << " us" << std::endl;
	std::cout << std::fixed << 	std::setprecision(5) << "Time to process a range of 5 elements with std::deque " << time2 << " us" << std::endl;
	return;
}

PmergeMe::~PmergeMe(void)
{
	return;
}
