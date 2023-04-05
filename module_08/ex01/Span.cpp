/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:47:43 by pedro             #+#    #+#             */
/*   Updated: 2023/04/05 18:51:29 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <stdlib.h>

Span::Span(void) : _vec(), _capacity(0) {
	std::cout << "Span default constructor was called!" << std::endl;
}

Span::Span(unsigned int n) : _vec(), _capacity(n) {
	std::cout << "Span constructor was called!" << std::endl;
}

Span::~Span(void) {
	std::cout << "Span destructor was called!" << std::endl;
}

Span::Span(Span const &rhs) : _vec(),  _capacity(rhs._capacity) {
	std::cout << "Span copy construcor was called!" << std::endl;
	*this = rhs;
}

Span&	Span::operator=(Span const &rhs) {
	std::cout << "Span assigment operator was called!" << std::endl;
	if (this == &rhs)
		return (*this);
	if (this->_capacity < rhs._capacity)
		throw Span::InsufficientSizeException();
	this->_vec = rhs._vec;
	return (*this);
}

void	Span::_sortVec(void) {
	std::vector<int>::const_iterator it;

	it = std::adjacent_find(this->_vec.begin(), this->_vec.end(), std::greater<int>());
	if (it == this->_vec.end())
		return ;
	std::sort(_vec.begin(), this->_vec.end());
}

void	Span::addNumber(int number) {
	if (this->_vec.size() >= this->_capacity)
		throw Span::FullSpanException();
	this->_vec.push_back(number);
}

int	Span::longestSpan(void) const {
	if (this->_vec.size() < 2)
		throw Span::InsufficientElementException();
	std::vector<int>::const_iterator	it = this->_vec.begin();
	std::vector<int>::const_iterator	ite = this->_vec.end();

	return (abs(*std::max_element(it, ite) - *std::min_element(it, ite)));
}

int	Span::shortestSpan(void) {
	if (this->_vec.size() < 2)
		throw Span::InsufficientElementException();
	this->_sortVec();
	std::vector<int>::const_iterator	it;
	std::vector<int>::const_iterator	ite = this->_vec.end();
	int	span = __INT_MAX__;
	int	diff;

	for (it = this->_vec.begin(); it != (ite - 1); ++it) {
		diff = abs(*it - *(it + 1));
		if (diff < span)
			span = diff;
	}
	return (span);
}

// exceptions

const char	*Span::FullSpanException::what() const throw() {
	return ("span is full");
}

const char	*Span::InsufficientElementException::what() const throw() {
	return ("span does not have enough elements");
}

const char *Span::InsufficientSizeException::what() const throw () {
	return ("span does not have enough size avaiable");
}
