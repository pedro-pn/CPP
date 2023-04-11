/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:36:18 by pedro             #+#    #+#             */
/*   Updated: 2023/04/11 17:40:13 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <cstdlib>

RPN::RPN(void) {

}

RPN::RPN(std::string const &input) : _input(input) {
	if (_validateInput() == false)
		throw std::runtime_error("Error");
	std::cout << calculate() << std::endl;
}

RPN::RPN(RPN const &rhs) {
	*this = rhs;
}

RPN::~RPN(void) {
	
}

RPN&	RPN::operator=(RPN const &rhs) {
	if (this == &rhs)
		return (*this);
	this->_input = rhs._input;
	this->_stack = rhs._stack;
	return (*this);
}

bool	RPN::_validateInput() const {
	std::string::const_iterator	it = _input.begin();
	std::string				operators = "+-/*";
	int	count = 0;

	while (it < _input.end()) {
		if (std::isdigit(*it))
			count++;
		else if (operators.find(*it) != std::string::npos)
			count--;
		else
			return (false);
		++it;
		if (it >= _input.end())
			break ;
		if (*it != ' ')
			return (false);
		++it;
		if (count < 0)
			return (false);
	}
	if (count != 1)
		return (false);
	return (true);
}

int	operation(int a, int b, char op) {
	switch (op) {
		case '+':
			return (a + b);
		case '-':
			return (a - b);
		case '/':
			return (a / b);
		case '*':
			return (a * b);
	};
	return (a);
}

int	RPN::calculate() {
	std::string::const_iterator	it = _input.begin();
	std::string				operators = "+-/*";

	while (it < _input.end()) {
		if (std::isdigit(*it))
			_stack.push(static_cast<int>(*it - '0'));
		else if (operators.find(*it) != std::string::npos) {
			_stack.push(operation(_pop(), _pop(), *it));
		}
		++it;
	}
	return (_stack.top());
}

int	RPN::_pop() {
	int	top;
	
	top = _stack.top();
	_stack.pop();
	return (top);
}
