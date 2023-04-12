/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:39:14 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/04/12 19:32:11 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>

PmergeMe::PmergeMe(void) {

}

PmergeMe::PmergeMe(char **input) {
	this->_parseInput(input);
	_mergeInsertSortVector(0, _vector.size() - 1, CUTOFF);
}

PmergeMe::PmergeMe(PmergeMe const &rhs) {
	*this = rhs;
}

PmergeMe::~PmergeMe(void) {

}

PmergeMe&	PmergeMe::operator=(PmergeMe const &rhs) {
	if (this == &rhs)
		return (*this);
	this->_list = rhs._list;
	this->_vector = rhs._vector;
	return (*this);
}

void	PmergeMe::_parseInput(char **input) {
	std::string	number;
	long int	n;

	for (int i = 1; input[i]; i++) {
		number = input[i];
		if (number.find_first_not_of(DIGITS) != std::string::npos)
			throw std::runtime_error("invalid number format");
		n = std::atol(number.c_str());
		if (n > __INT_MAX__)
			throw std::runtime_error("integer overflow");
		this->_list.push_back(static_cast<int>(n));
		this->_vector.push_back(static_cast<int>(n));
	}
}

void	PmergeMe::_mergeVector(int start, int middle, int end) {
	std::vector<int>	aux1;
	std::vector<int>	aux2;
	std::vector<int>::iterator	vecIt = this->_vector.begin() + start;
	std::vector<int>::iterator	vecItm = vecIt + middle - start + 1;
	std::vector<int>::iterator	aux1It;
	std::vector<int>::iterator	aux2It;

	aux1.insert(aux1.begin(), vecIt, vecItm);
	aux2.insert(aux2.begin(), vecItm, vecItm + end - middle);
	aux1It = aux1.begin();
	aux2It = aux2.begin();
	while (aux1It != aux1.end() && aux2It != aux2.end()) {
		if (*aux1It <= *aux2It) {
			*vecIt = *aux1It;
			++aux1It;
		}
		else {
			*vecIt = *aux2It;
			++aux2It;
		}
		++vecIt;
	}
	for (; aux1It < aux1.end(); ++aux1It) {
		*vecIt = *aux1It;
		++vecIt;
	}
	for (; aux2It < aux2.end(); ++aux2It) {
		*vecIt = *aux2It;
		++vecIt;
	}
}

void	PmergeMe::_insertionSortVector(int start, int end) {
	std::vector<int>::iterator	it1 = this->_vector.begin() + start, it2;
	int	key;

	for (++it1; it1 != this->_vector.begin() + end + 1; ++it1) {
		key = *it1;
		it2 = it1 - 1;
		while (it2 >= this->_vector.begin() + start && *it2 > key) {
			*(it2 + 1) = *it2;
			--it2;
		}
		*(it2 + 1) = key;
	}
}

void	PmergeMe::_mergeInsertSortVector(int start, int end, int cutoff) {
	int middle;

	if (start >= end)
		return ;
	if (end - start + 1 <= cutoff) {
		std::cout << "insert!" << std::endl;
		_insertionSortVector(start, end);
	}
	else{
		std::cout << "merge!" << std::endl;
		middle = (start + end) / 2;
		_mergeInsertSortVector(start, middle, cutoff);
		_mergeInsertSortVector(middle + 1, end, cutoff);
		_mergeVector(start, middle, end);
	}
}