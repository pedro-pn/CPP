/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:58:00 by pedro             #+#    #+#             */
/*   Updated: 2023/04/11 12:19:16 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange(std::string const &dataBase) {
		this->_openDataBase(dataBase);
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

void	BitcoinExchange::_openDataBase(std::string const &fileName) {
	std::ifstream	file(fileName.c_str());
	std::string		line;
	int				lineCount = 1;

	if (file.is_open() == false)
		throw std::runtime_error("btc error: cannot open '" + fileName + "'");
	std::getline(file, line);
	if (_checkDbHeader(line) == false)
		throw (std::runtime_error("btc error: invalid CSV header"));
	while (std::getline(file, line)) {
		try {
			_getDbLine(line);
		} catch (std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		lineCount++;
	}
}
 
void	BitcoinExchange::processInput(std::string const &fileName) {
	std::ifstream	file(fileName.c_str());
	std::string		line;
	int				lineCount = 1;

	if (file.is_open() == false)
		throw std::runtime_error("btc error: cannot open '" + fileName + "'");
	std::getline(file, line);
	if (_checkInputHeader(line) == false)
		throw (std::runtime_error("btc error: invalid input header"));
	while (std::getline(file, line)) {
		try {
			_getInputLine(line);
		} catch (std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		lineCount++;
	}
}

bool	BitcoinExchange::_checkDbHeader(std::string const &line) {
	if (line.compare("date,exchange_rate") != 0)
		return (false);
	return (true);
}
 
bool	BitcoinExchange::_checkInputHeader(std::string const &line) {
	if (line.compare("data | value") != 0)
		return (false);
	return (true);
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
	date.erase(date.begin() + 4);
	date.erase(date.begin() + 6);
	_dataBase.insert(std::pair<int, double>(std::atoi(date.c_str()), std::atof(value.c_str())));
}

void	BitcoinExchange::_getInputLine(std::string const &line) {
	std::string::const_iterator	begin;
	std::string					date;
	std::string					value;
	std::string					formatDate;
	size_t						pipe;
	long int					lvalue;
	int							key;

	pipe = line.find(" | ");
	if (pipe == std::string::npos)
		throw (std::runtime_error("bad format => " + line));
	begin = line.begin();
	date = line.substr(0, pipe);
	if (_checkDate(date) == false) 
		throw std::runtime_error("bad data format => " + date);
	value = line.substr(pipe + 3, line.length() - pipe - 3);
	if (_isValue(value) == false) 
		throw std::runtime_error("bad format => " + value);
	lvalue = std::atof(value.c_str());
	if (lvalue > __INT_MAX__ || _checkValue(lvalue) == false)
		throw std::runtime_error("bad format => '" + value + "': too large number");
	if (lvalue < 0)
		throw std::runtime_error("bad format => '" + value + "': not a positive number");
	formatDate = date;
	formatDate.erase(formatDate.begin() + 4);
	formatDate.erase(formatDate.begin() + 6);
	key = std::atoi(formatDate.c_str());
	std::cout << date << " => " << value << " = " << std::atof(value.c_str()) * _getClosestValue(key) << std::endl;
}

double	BitcoinExchange::_getClosestValue(int key) {
	std::map<int, double>::iterator	it = this->_dataBase.begin();
	int	lowerKey;

	if (key <= it->first)
		return (this->_dataBase[it->first]);
	else if (key >= this->_dataBase.rbegin()->first)
		return (this->_dataBase[this->_dataBase.rbegin()->first]);
	for (; it->first <= key; ++it) {
		if (it->first <= key)
			lowerKey = it->first;
		}
	return (this->_dataBase[lowerKey]);
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
	if (month < 1 || month > 12)
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

bool	BitcoinExchange::_checkValue(long int value) {
	if (value < 0 || value > 1000)
		return (false);
	return (true);
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
	size_t		doubleDot = 0;
	size_t		iterator = 0;

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
	if (doubleDot > 1 || literal[iterator - 1] == '.')
		return (false);
	return (true);
}
