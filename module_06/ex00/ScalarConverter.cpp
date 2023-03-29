/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:59:40 by pedro             #+#    #+#             */
/*   Updated: 2023/03/29 16:16:03 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <ctype.h>

ScalarConverter::ScalarConverter(void) {
	std::cout << "ScalarConverter constructor was called!" << std::endl;
}

ScalarConverter::~ScalarConverter(void) {
	std::cout << "ScalarConverter destructor was called!" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &rhs) {
	std::cout << "ScalarConverter copy constructor was called!" << std::endl;
	*this = rhs;
}

ScalarConverter&	ScalarConverter::operator=(ScalarConverter const & rhs) {
	std::cout << "ScalarConverter assigment operator was called!" << std::endl;
	(void)rhs;
	return (*this);
}

void	ScalarConverter::convert(std::string const &literal) {
	(void)literal;
}

bool	ScalarConverter::is_char(std::string const &literal) {
	if (literal.length() != 1)
		return (false);
	if (isdigit(literal[0]))
		return (false);
	if (isprint(literal[0]))
		return (true);
	return (false);
}

bool	ScalarConverter::is_int(std::string const &literal) {
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

bool	ScalarConverter::is_float(std::string const &literal) {
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

bool	ScalarConverter::is_double(std::string const &literal) {
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
 