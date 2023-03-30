/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:59:40 by pedro             #+#    #+#             */
/*   Updated: 2023/03/29 21:45:29 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <ctype.h>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>
#include <iomanip>

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
	switch (ScalarConverter::assertType(literal)) {
		case (CHAR_TYPE):
			ScalarConverter::convertChar(literal);			
			break ;
		case (INT_TYPE):
			ScalarConverter::convertInt(literal);			
			break ;
		case (FLOAT_TYPE):
			ScalarConverter::convertFloat(literal);			
			break ;
		case (DOUBLE_TYPE):
			ScalarConverter::convertDouble(literal);			
			break ;
		default:
			std::cout << "Invalid literal!" << std::endl;
			break ;
	}
}

int		ScalarConverter::assertType(std::string const &literal) {
	int	result = 0;
	bool	(*isTypes[4])(std::string const &) = {
		&ScalarConverter::_isChar,
		&ScalarConverter::_isInt,
		&ScalarConverter::_isFloat,
		&ScalarConverter::_isDouble};

	for ( ;  result < 4; result++) {
		if((*isTypes[result])(literal)) {
			break ;
		}
	}
	return (result);
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

	if (literal == "inff" || literal == "-inff" || literal == "+inff" || literal == "nanf")
		return (true);
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
	
	if (literal == "inf" || literal == "nan" || literal == "-inf" || literal == "+inf")
		return (true);
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

void	ScalarConverter::convertChar(std::string const &literal) {
	t_types	types;
	
	types._char = static_cast<char>(literal[0]);
	types._int = static_cast<int>(types._char);
	types._float = static_cast<float>(types._char);
	types._double = static_cast<double>(types._char);
	
	std::cout << "Literal: " << literal << " (char type)" << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	ScalarConverter::printConvertion(types);
}

void	ScalarConverter::convertInt(std::string const &literal) {
	t_types	types;
	
	types._int = std::atoi(literal.c_str());
	if (types._int == 0 && literal.length() != 1) {
		std::cerr << "Error when casting '" << literal << "' to int: integer overflow" << std::endl;
		return ;
	}
	types._char = static_cast<char>(types._int);
	types._float = static_cast<float>(types._int);
	types._double = static_cast<double>(types._int);
	
	std::cout << "Literal: " << literal << " (int type)" << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	if (isprint(types._int))
		std::cout << "Char: '" << types._char << "'" << std::endl;
	else
		std::cout << "Char: " << "Not displayable" << std::endl;
	std::cout << "int: " << types._int  << std::endl;
	std::cout << "float: " << types._float << 'f' << std::endl;
	std::cout << "double: " << types._double  << std::endl;
}

void	ScalarConverter::convertFloat(std::string const &literal) {
	t_types	types;
	
	types._float = static_cast<float>(std::atof(literal.c_str()));
	types._char = static_cast<char>(types._float);
	types._int = static_cast<int>(types._float);
	types._double = static_cast<double>(types._float);
	
	std::cout << "Literal: " << literal << " (float type)" << std::endl;
	if (types._int >= 32 && types._int < 127)
		std::cout << "Char: '" << types._char << "'" << std::endl;
	else
		std::cout << "Char: " << "Not displayable" << std::endl;
	if (isnanf(types._float) || isinff(types._float))
		std::cout << "int: " << "impossible"  << std::endl;
	else
		std::cout << "int: " << types._int  << std::endl;
	std::cout << "float: " << types._float << 'f' << std::endl;
	std::cout << "double: " << types._double  << std::endl;
}

void	ScalarConverter::convertDouble(std::string const &literal) {
	t_types	types;
	
	types._double = std::atof(literal.c_str());
	types._char = static_cast<char>(types._double);
	types._int = static_cast<int>(types._double);
	types._float = static_cast<float>(types._double);
	
	std::cout << "Literal: " << literal << " (double type)" << std::endl;
	if (types._int >= 32 && types._int < 127)
		std::cout << "Char: '" << types._char << "'" << std::endl;
	else
		std::cout << "Char: " << "Not displayable" << std::endl;
	if (isnanl(types._double) || isinfl(types._double))
		std::cout << "int: " << "impossible"  << std::endl;
	else
		std::cout << "int: " << types._int  << std::endl;
	std::cout << "float: " << types._float << 'f' << std::endl;
	std::cout << "double: " << types._double  << std::endl;
}

void	ScalarConverter::printConvertion(t_types const types) {
	std::cout << "Char: '" << types._char << "'" << std::endl;
	std::cout << "int: " << types._int  << std::endl;
	std::cout << "float: " << types._float << 'f' << std::endl;
	std::cout << "double: " << types._double  << std::endl;
}
