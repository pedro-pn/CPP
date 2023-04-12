/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:58:00 by pedro             #+#    #+#             */
/*   Updated: 2023/04/12 11:43:39 by ppaulo-d         ###   ########.fr       */
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
	file.close();
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
	file.close();
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
	_dataBase.insert(std::pair<std::string, double>(date, std::atof(value.c_str())));
}

void	BitcoinExchange::_getInputLine(std::string const &line) {
	std::string::const_iterator	begin;
	std::string					date;
	std::string					value;
	size_t						pipe;
	long int					lvalue;

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
	std::cout << date << " => " << value << " = " << std::atof(value.c_str()) * _getClosestValue(date) << std::endl;
}

double	BitcoinExchange::_getClosestValue(std::string const &key) {
	std::map<std::string, double>::iterator	it;

	it = _dataBase.upper_bound(key);
	if (it == _dataBase.begin())
		return (it->second);
	--it;
	return (it->second);
}

bool	BitcoinExchange::_checkDate(std::string const &date) {
	std::string			syear;
	std::string			smonth;
	std::string			sday;
	size_t				dash;

	dash = date.find('-');
	if (dash == std::string::npos)
		return (false);
	syear = date.substr(0, dash);
	if (this->_isInt(syear) == false)
		return (false);
	if (syear < FYEAR || syear > LYEAR)
		return (false);
	smonth = date.substr(dash + 1, 2);
	if (this->_isInt(smonth) == false)
		return (false);
	dash = dash + 3;
	if (date[dash] != '-')
		return (false);
	sday = date.substr(dash + 1, date.length() - dash + 1);
	if (this->_isInt(sday) == false)
		return (false);
	if (smonth < JAN || smonth > DEC)
		return (false);
	if (smonth == APR || smonth == JUN || smonth == SET || smonth == NOV) {
		if (sday < "01" || sday > "30")
			return (false);
	} else if (smonth == FEV) {
		if (sday < "01" || sday > "29")
			return (false);
	}
	if (sday < "01" || sday > "31")
		return (false);
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
