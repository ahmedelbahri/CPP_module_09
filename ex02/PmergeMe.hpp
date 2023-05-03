#ifndef PMERGEME_H
#define PMERGEME_H

#define MERGE_SIZE 2

#include <deque>
#include <vector>
#include <iostream>
#include <ctime>
#include <iomanip>

class PmergeMe
{
private:
	std::vector<int>	vec;
	std::deque<int>		list;
public:
						PmergeMe(void);
						PmergeMe(PmergeMe const &pmergeme);
	PmergeMe			&operator = (PmergeMe const &pmergeme);
	void				initiate(char **av);
	void				print_vec(void);
	void				print_deque(void);
	void				merge_sort_vec(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	void				merge_sort_deque(std::deque<int>::iterator begin, std::deque<int>::iterator end);
						~PmergeMe(void);
};

void	error_stdout(std::string str);

#endif
