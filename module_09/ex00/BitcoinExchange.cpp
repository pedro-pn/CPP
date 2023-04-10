/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:58:00 by pedro             #+#    #+#             */
/*   Updated: 2023/04/10 18:27:14 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange(std::string const &dataBase) {
	this->openDataBase(dataBase);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &rhs) {
	*this = rhs;
}

BitcoinExchange::~BitcoinExchange(void) {
	
}

BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange const &rhs) {
	if (this == &rhs)
		return (*this);
	this->_dataBase = rhs._dataBase;
	return (*this);
}

void	BitcoinExchange::openDataBase(std::string const &fileName) {
	std::ifstream	file(fileName.c_str());
	std::string		line;
	int				lineCount = 1;

	if (file.is_open() == false)
		throw std::runtime_error("btc error: cannot open '" + fileName + "'");
	std::getline(file, line);
	while (std::getline(file, line)) {
		try {
			_getDbLine(line);
		} catch (std::exception &e) {
			std::cerr << "BBBBBBBBBBBBBBB" << std::endl;
			std::cout << "Error: " << e.what() << std::endl;
		}
		lineCount++;
	}
}
 
void	BitcoinExchange::_getDbLine(std::string const &line) {
	std::string::const_iterator	begin;
	std::string					date;
	std::string					value;
	size_t						comma;

	comma = line.find(',');
	if (comma == std::string::npos)
		throw (std::runtime_error("bad format => " + line));
	begin = line.begin();
	date = line.substr(0, comma);
	if (_checkDate(date) == false) 
		throw std::runtime_error("bad format => " + date);
	value = line.substr(comma + 1, line.length() - comma - 1);
	if (_isValue(value) == false) 
		throw std::runtime_error("bad format => " + value);
	_dataBase.insert(std::pair<std::string, double>(date, std::atof(value.c_str())));
}

bool	BitcoinExchange::_checkDate(std::string const &date) {
	std::string			syear;
	std::string			smonth;
	std::string			sday;
	int					year;
	int					month;
	int					day;
	size_t				dash;

	dash = date.find('-');
	if (dash == std::string::npos)
		return (false);
	syear = date.substr(0, dash);
	if (this->_isInt(syear) == false)
		return (false);
	year = std::atoi(syear.c_str());
	if (year < 1900 || year > 2023)
		return (false);
	smonth = date.substr(dash + 1, 2);
	if (this->_isInt(smonth) == false)
		return (false);
	month = std::atoi(smonth.c_str());
	dash = dash + 3;
	if (date[dash] != '-')
		return (false);
	sday = date.substr(dash + 1, date.length() - dash + 1);
	if (this->_isInt(sday) == false)
		return (false);
	day = std::atoi(sday.c_str());
	if (month < 1 && month > 12)
		return (false);
	if (month == JAN || month == MAR || month == MAY || month == JUL
		|| month == AUG || month == OCT || month == DEC) {
		if (day < 0 || day > 31)
			return (false);
	} else if (month == APR || month == JUN || month == SET || month == NOV) {
		if (day < 0 || day > 30)
			return (false);
	} else if (month == FEV) {
		if (day < 0 || day > 29)
			return (false);
	}
	return (true);
}

bool	BitcoinExchange::_checkValue(std::string const &value) {
	double	dvalue = std::atof(value.c_str());

	if (dvalue < 0 || dvalue > 1000)
		return (false);
	return (true);
}

void	BitcoinExchange::testeDb(std::string const &data) {
	std::cout << this->_dataBase[data] << std::endl;
}

bool	BitcoinExchange::_isInt(std::string const &n) {
	size_t i = 0;

	if (n.length() == 0)
		return (false);
	for (size_t iterator = i, length = n.length(); iterator < length; iterator++) {
		if (isdigit(n[iterator]) == 0)
			return (false);
	}
	return (true);
}

bool	BitcoinExchange::_isValue(std::string const &literal) {
	size_t	doubleDot = 0;
	size_t	iterator = 0;
	
	for ( ; iterator < literal.length(); iterator++) {
		if (literal[iterator] == '.' && doubleDot == 0) {
			doubleDot += 1;
			continue ;
		}
		if (isdigit(literal[iterator]) == 0)
			return (false);
	}
	if (doubleDot > 1 || literal[iterator - 1] == '.')
		return (false);
	return (true);
}
