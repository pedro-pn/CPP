/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:39:14 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/04/13 12:02:35 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

PmergeMe::PmergeMe(void) {
	std::cout << "Nothing to sort!" << std::endl;
}

PmergeMe::PmergeMe(char **input) {
	this->_parseInput(input);
	// std::cout << "before: ";
	// _printContainer(this->_vector);
	// _sortVector();
	// std::cout << "after: ";
	// _printContainer(this->_vector);

	// std::cout << "before: ";
	// _printContainer(this->_list);
	// std::cout << "at position 5: " << *_getListPosition(0) << std::endl;
	// _insertionSortList(0, this->_list.size() - 1);
	// std::cout << "after: ";
	// _printContainer(this->_list);

	std::cout << "before: ";
	_printContainer(this->_list);
	std::cout << "at position 5: " << *_getListPosition(0) << std::endl;
	_mergeInsertSortList(0, this->_list.size() - 1, 2);
	std::cout << "after: ";
	_printContainer(this->_list);

	// std::cout << "before: ";
	// _printContainer(this->_vector);
	// std::cout << "at position 5: " << *_getListPosition(0) << std::endl;
	// _insertionSortVector(0, this->_vector.size() - 1);
	// std::cout << "after: ";
	// _printContainer(this->_vector);

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

/* ======================= VECTOR SORTING ALGORITHM ========================= */

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
		while (it2 >= (this->_vector.begin() + start) && *it2 > key) {
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
	if (end - start + 1 <= cutoff)
		_insertionSortVector(start, end);
	else {
		middle = (start + end) / 2;
		_mergeInsertSortVector(start, middle, cutoff);
		_mergeInsertSortVector(middle + 1, end, cutoff);
		_mergeVector(start, middle, end);
	}
}

void	PmergeMe::_sortVector(void) {
	clock_t	startTime, endTime;
	double	resultTime;

	startTime = clock();
	this->_mergeInsertSortVector(0, this->_vector.size() - 1, 5);
	endTime = clock();
	resultTime = (double) 1000.0 * (endTime - startTime) / CLOCKS_PER_SEC;
	std::cout << "Time taken by vector: " << resultTime << std::endl;
}

/* ==================== END OF VECTOR SORTING ALGORITHM ===================== */

/* ======================== LIST SORTING ALGORITHM ========================== */

std::list<int>::iterator	PmergeMe::_getListPosition(int position) {
	std::list<int>::iterator	it = this->_list.begin();

	for (int i = 0; i < position; ++it) {
		i++;
	}
	return (it);
}

void	PmergeMe::_mergeList(int start, int middle, int end) {
	std::list<int>	aux1;
	std::list<int>	aux2;
	std::list<int>::iterator	vecIt = this->_getListPosition(start);
	std::list<int>::iterator	vecItm = this->_getListPosition(middle + 1);
	std::list<int>::iterator	aux1It;
	std::list<int>::iterator	aux2It;

	aux1.insert(aux1.begin(), vecIt, vecItm);
	aux2.insert(aux2.begin(), vecItm, _getListPosition(end + 1));
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
	for (; aux1It != aux1.end(); ++aux1It) {
		*vecIt = *aux1It;
		++vecIt;
	}
	for (; aux2It != aux2.end(); ++aux2It) {
		*vecIt = *aux2It;
		++vecIt;
	}
}

void	PmergeMe::_insertionSortList(int start, int end) {
	std::list<int>::iterator	it1 = _getListPosition(start), it2, auxIt1, auxIt2;
	int	key;

	for (++it1; it1 != _getListPosition(start + end + 1); ++it1) {
		key = *it1;
		auxIt1 = it1;
		auxIt1--;
		it2 = auxIt1;
		while (it2 != --this->_list.begin() && *it2 > key) {
			auxIt2 = it2;
			++auxIt2;
			*auxIt2 = *it2;
			--it2;
		}
		auxIt2 = it2;
		++auxIt2;
		*auxIt2 = key;
	}
}

void	PmergeMe::_mergeInsertSortList(int start, int end, int cutoff) {
	int middle;

	if (start >= end)
		return ;
	if (end - start + 1 <= cutoff){
		std::cout << "INSERT" << std::endl;
		_insertionSortList(start, end);
	}
	else {
		std::cout << "MERGE" << std::endl;
		middle = (start + end) / 2;
		_mergeInsertSortList(start, middle, cutoff);
		_mergeInsertSortList(middle + 1, end, cutoff);
		_mergeList(start, middle, end);
	}
}

template<typename T>
void	PmergeMe::_printContainer(T container) const {
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
