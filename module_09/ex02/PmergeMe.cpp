/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:39:14 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/04/12 18:51:39 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>

PmergeMe::PmergeMe(void) {

}

PmergeMe::PmergeMe(char **input) {
	this->_parseInput(input);
	_mergeSortVector(this->_vector, 0, this->_vector.size() - 1);
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

void	PmergeMe::_mergeVector(std::vector<int> &vector, int start, int middle, int end) {
	std::vector<int>	aux1;
	std::vector<int>	aux2;
	std::vector<int>::iterator	vecIt = vector.begin() + start;
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

void	PmergeMe::_mergeSortVector(std::vector<int> &vector, int start, int end) {
	if (start >= end)
		return ;
	int middle = (end + start) / 2;
	_mergeSortVector(vector, start, middle);
	_mergeSortVector(vector, middle + 1, end);
	_mergeVector(vector, start, middle, end);
}
