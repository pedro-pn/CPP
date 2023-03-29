/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:59:40 by pedro             #+#    #+#             */
/*   Updated: 2023/03/29 18:07:53 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <ctype.h>

ScalarConverter::ScalarConverter(void) {
	if (DEBUG)
		std::cout << "ScalarConverter constructor was called!" << std::endl;
}

ScalarConverter::~ScalarConverter(void) {
	if (DEBUG)
		std::cout << "ScalarConverter destructor was called!" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &rhs) {
	if (DEBUG)
		std::cout << "ScalarConverter copy constructor was called!" << std::endl;
	*this = rhs;
}

ScalarConverter&	ScalarConverter::operator=(ScalarConverter const & rhs) {
	if (DEBUG)
		std::cout << "ScalarConverter assigment operator was called!" << std::endl;
	(void)rhs;
	return (*this);
}

void	ScalarConverter::convert(std::string const &literal) {
	(void)literal;
}

bool	ScalarConverter::_isChar(std::string const &literal) {
	if (literal.length() != 1)
		return (false);
	if (isdigit(literal[0]))
		return (false);
	if (isprint(literal[0]))
		return (true);
	return (false);
}

bool	ScalarConverter::_isInt(std::string const &literal) {
	size_t i = 0;

	if (literal.length() == 0)
		return (false);
	if (literal[i] == '-' || literal[i] == '+')
		i++;
	for (size_t iterator = i, length = literal.length(); iterator < length; iterator++) {
		if (isdigit(literal[iterator]) == 0)
			return (false);
	}
	return (true);
	
}

bool	ScalarConverter::_isFloat(std::string const &literal) {
	size_t	floatDot = 0;
	size_t	iterator = 0;

	if (literal[iterator] == '-' || literal[iterator] == '+')
		iterator++;
	for ( ; iterator < (literal.length() - 1); iterator++) {
		if (literal[iterator] == '.' && floatDot == 0) {
			floatDot += 1;
			continue ;
		}
		if (isdigit(literal[iterator]) == 0)
			return (false);
	}
	if (floatDot == 0 || literal[iterator] != 'f' || literal[iterator - 1] == '.')
		return (false);
	return (true);
}

bool	ScalarConverter::_isDouble(std::string const &literal) {
	size_t	doubleDot = 0;
	size_t	iterator = 0;
	
	if (literal[iterator] == '-' || literal[iterator] == '+')
		iterator++;
	for ( ; iterator < literal.length(); iterator++) {
		if (literal[iterator] == '.' && doubleDot == 0) {
			doubleDot += 1;
			continue ;
		}
		if (isdigit(literal[iterator]) == 0)
			return (false);
	}
	if (doubleDot == 0 || literal[iterator - 1] == '.')
		return (false);
	return (true);
}
